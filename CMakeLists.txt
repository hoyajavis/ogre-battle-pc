cmake_minimum_required(VERSION 3.16)
project(OgreBattlePC C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiler optimization and warnings
if(MSVC)
    add_compile_options(/W3 /O2)
else()
    add_compile_options(-Wall -Wextra -Wno-unused-parameter -O2)
endif()

set(OGRE_BATTLE_ROM "${CMAKE_CURRENT_SOURCE_DIR}/ogre_battle.sfc" CACHE FILEPATH "Path to clean USA Ogre Battle ROM")

# SDL2 dependency paths (local headers + vendored lib link)
set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/sdl2_headers)
set(SDL2_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/lib)

if(EXISTS ${SDL2_LIB_DIR})
    link_directories(${SDL2_LIB_DIR})
endif()

# LakeSnes hardware emulation core
set(LAKESNES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/snesrecomp/ext/LakeSnes/snes)

add_library(lakesnes STATIC
    ${LAKESNES_DIR}/apu.c
    ${LAKESNES_DIR}/cart.c
    ${LAKESNES_DIR}/cpu.c
    ${LAKESNES_DIR}/dma.c
    ${LAKESNES_DIR}/dsp.c
    ${LAKESNES_DIR}/dsp1.c
    ${LAKESNES_DIR}/gsu.c
    ${LAKESNES_DIR}/input.c
    ${LAKESNES_DIR}/ppu.c
    ${LAKESNES_DIR}/snes.c
    ${LAKESNES_DIR}/snes_other.c
    ${LAKESNES_DIR}/spc.c
    ${LAKESNES_DIR}/statehandler.c
)
target_include_directories(lakesnes PUBLIC ${LAKESNES_DIR})
if(NOT MSVC)
    target_compile_options(lakesnes PRIVATE -w) # Suppress warnings in upstream LakeSnes
endif()

# SNES static recompilation runtime
set(SNESRECOMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/snesrecomp)
add_library(snesrecomp STATIC
    ${SNESRECOMP_DIR}/src/bus.c
    ${SNESRECOMP_DIR}/src/cpu.c
    ${SNESRECOMP_DIR}/src/func_table.c
    ${SNESRECOMP_DIR}/src/recomp_interp.c
)
target_include_directories(snesrecomp PUBLIC
    ${SNESRECOMP_DIR}/include
    ${LAKESNES_DIR}
)
target_link_libraries(snesrecomp PUBLIC lakesnes)

# Generated recompiled game code
file(GLOB GEN_SOURCES "src/gen/*.c")
add_library(ob_recomp STATIC
    ${GEN_SOURCES}
)
target_include_directories(ob_recomp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gen
    ${SNESRECOMP_DIR}/include
    ${LAKESNES_DIR}
)
target_link_libraries(ob_recomp PUBLIC snesrecomp lakesnes)

# Runner / Oracle verification framework
add_library(runner_core STATIC
    runner/src/snapshot.c
    runner/src/replay.c
    runner/src/oracle.c
    runner/src/lockstep.c
)
target_include_directories(runner_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/runner/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gen
    ${SNESRECOMP_DIR}/include
    ${LAKESNES_DIR}
)
target_link_libraries(runner_core PUBLIC ob_recomp snesrecomp lakesnes)

# Core OgreBattlePC runner / harness (requires SDL2)
find_package(SDL2 QUIET)
if(SDL2_FOUND OR WIN32)
    add_executable(ogre_battle_pc
        src/main.c
    )
    target_include_directories(ogre_battle_pc PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/runner/include
        ${SDL2_INCLUDE_DIR}
        ${LAKESNES_DIR}
    )
    target_link_libraries(ogre_battle_pc PRIVATE
        runner_core
        lakesnes
        SDL2
        m
    )
endif()

# Oracle & Lockstep Verification Test Suite
add_executable(test_oracle
    runner/test/test_oracle.c
)
target_include_directories(test_oracle PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/runner/include
    ${LAKESNES_DIR}
)
target_link_libraries(test_oracle PRIVATE
    runner_core
    lakesnes
    m
)

# Canonical Trace Generator & Verifier
add_executable(generate_canonical_traces
    tools/generate_canonical_traces.c
)
target_include_directories(generate_canonical_traces PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/runner/include
    ${LAKESNES_DIR}
)
target_link_libraries(generate_canonical_traces PRIVATE
    runner_core
    lakesnes
    m
)

# Standalone Trace Verifier
add_executable(verify_trace
    tools/verify_trace.c
)
target_include_directories(verify_trace PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/runner/include
    ${LAKESNES_DIR}
)
target_link_libraries(verify_trace PRIVATE
    runner_core
    lakesnes
    m
)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tools/bisect_frame_3101.c)
    add_executable(bisect_frame_3101
        tools/bisect_frame_3101.c
    )
    target_include_directories(bisect_frame_3101 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/runner/include
        ${LAKESNES_DIR}
    )
    target_link_libraries(bisect_frame_3101 PRIVATE
        runner_core
        lakesnes
        m
    )
endif()


# Dynamic Code/Data Log (CDL) Collector
add_executable(cdl_collector
    tools/cdl_collector.c
)
target_include_directories(cdl_collector PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tools
    ${CMAKE_CURRENT_SOURCE_DIR}/runner/include
    ${LAKESNES_DIR}
)
target_link_libraries(cdl_collector PRIVATE
    runner_core
    lakesnes
    m
)

# Gate 2-4 Engine Unit Tests
add_executable(test_mouse_three_pillar
    tests/test_mouse_three_pillar.c
    src/engine/input.c
)
target_include_directories(test_mouse_three_pillar PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine
)

add_executable(test_widescreen_16_9
    tests/test_widescreen_16_9.c
    src/engine/widescreen.c
    src/engine/snes_ui_rasterizer.c
    src/engine/input.c
)
target_include_directories(test_widescreen_16_9 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine
)

add_executable(test_area_1_telemetry
    tests/test_area_1_telemetry.c
    src/engine/telemetry.c
    src/engine/telemetry_math.c
    src/engine/telemetry_window.c
    src/engine/snes_ui_rasterizer.c
)
target_include_directories(test_area_1_telemetry PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/engine
    ${LAKESNES_DIR}
)
target_link_libraries(test_area_1_telemetry PRIVATE lakesnes m)

# Custom target for ROM verification
add_custom_target(verify_rom
    COMMAND ${CMAKE_COMMAND} -E echo "Verifying Ogre Battle ROM..."
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/tools/verify_rom.py ${OGRE_BATTLE_ROM}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Enable CTest suite
enable_testing()
add_test(NAME OracleHarnessTest COMMAND test_oracle ${OGRE_BATTLE_ROM})
add_test(NAME Gate2MouseThreePillarTest COMMAND test_mouse_three_pillar)
add_test(NAME Gate3Widescreen16x9Test COMMAND test_widescreen_16_9)
add_test(NAME Gate4TelemetryTest COMMAND test_area_1_telemetry ${OGRE_BATTLE_ROM})
add_test(NAME CanonicalTrace1Test COMMAND verify_trace 
    ${CMAKE_CURRENT_SOURCE_DIR}/traces/trace_01_boot_to_title.obrec 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_01.obsav 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_01_verify.png 
    ${OGRE_BATTLE_ROM}
)
add_test(NAME CanonicalTrace2Test COMMAND verify_trace 
    ${CMAKE_CURRENT_SOURCE_DIR}/traces/trace_02_tarot_creation.obrec 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_02.obsav 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_02_verify.png 
    ${OGRE_BATTLE_ROM}
)
add_test(NAME CanonicalTrace3Test COMMAND verify_trace 
    ${CMAKE_CURRENT_SOURCE_DIR}/traces/trace_03_felnamia_deploy.obrec 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_03.obsav 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_03_verify.png 
    ${OGRE_BATTLE_ROM}
)
add_test(NAME CanonicalTrace4Test COMMAND verify_trace 
    ${CMAKE_CURRENT_SOURCE_DIR}/traces/trace_04_tactical_march_clock.obrec 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_04.obsav 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_04_verify.png 
    ${OGRE_BATTLE_ROM}
)
add_test(NAME CanonicalTrace5Test COMMAND verify_trace 
    ${CMAKE_CURRENT_SOURCE_DIR}/traces/trace_05_battle_encounter.obrec 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_05.obsav 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_05_verify.png 
    ${OGRE_BATTLE_ROM}
)
add_test(NAME CanonicalTrace6Test COMMAND verify_trace 
    ${CMAKE_CURRENT_SOURCE_DIR}/traces/trace_06_daskania_liberation.obrec 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_06.obsav 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_06_verify.png 
    ${OGRE_BATTLE_ROM}
)
add_test(NAME CanonicalTrace7Test COMMAND verify_trace 
    ${CMAKE_CURRENT_SOURCE_DIR}/traces/trace_07_warren_boss_clear.obrec 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_07.obsav 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_07_verify.png 
    ${OGRE_BATTLE_ROM}
)
add_test(NAME CanonicalTrace8Test COMMAND verify_trace 
    ${CMAKE_CURRENT_SOURCE_DIR}/traces/trace_08_world_map_save.obrec 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_08.obsav 
    ${CMAKE_CURRENT_BINARY_DIR}/trace_08_verify.png 
    ${OGRE_BATTLE_ROM}
)





