# Agent Governance & Operating Rules: Ogre Battle 1:1 PC Port

This document defines the mandatory operating protocols, verification standards, task templates, and **Git version control workflows** for all AI agents and subagents contributing to the **Ogre Battle 1:1 Native PC Port** project.

---

## 1. Non-Negotiable Core Rules of Engagement

Every rule here represents a catastrophic failure mode observed in prior reverse engineering and recompilation efforts:

1. **Never Synthesize or Mock Execution Results:**
   * Never fake a passing test, mock an emulator response, or skip a compilation step.
   * If a recompiled routine produces a lockstep memory mismatch or crash, report the exact instruction address and memory delta. Never bypass it with a dummy return or hardcoded value.
2. **Lockstep Parity is Authoritative:**
   * The golden reference emulator running the original ROM is the sole source of truth.
   * If recompiled C code diverges by even 1 byte in WRAM or VRAM, that change is considered broken and must not be accepted until resolved.
3. **Instruction-Level Verification over Intuition:**
   * A previous agent's analysis is an unverified hypothesis. Always confirm register sizing ($M$ and $X$ flags) and stack pointer ($S$) behavior directly against the raw disassembled bytes.
   * Do not guess whether an operation is 8-bit or 16-bit; trace every path leading to the instruction from the nearest `REP`/`SEP` or `PLP`.
4. **Legal & Repository Cleanliness:**
   * Never commit proprietary ROM binaries (`.sfc`, `.smc`), decompressed copyrighted sprites, or music samples to Git.
   * Enforce this via `.gitignore` and the automated pre-commit hook (`tools/git-hooks/pre-commit`).
5. **Strict Gate Progression (Anti-Premature Modernization):**
   * **Gate 1 (4:3 Bit-Exact Parity) must pass 100% across all 8 `.obrec` walkthrough traces before any subagent touches mouse or widescreen code.**
   * Subagents are strictly prohibited from modifying map streaming buffers or viewport compositors until the 4:3 baseline is certified.
6. **Automated Lifter First, Selective Refactor Second:**
   * Do not waste time manually decompiling low-level math, DMA transfer loops, or sound queues from scratch. 
   * Mechanically generate 100% of subroutines into C via the automated lifter. Refactoring via `RECOMP_PATCH` is reserved strictly for high-value targets (`map.c`, `input.c`, `unit.c`).
7. **Mandatory Session Handoff Logs with Git Metadata:**
   * When concluding an agent session or delegating to another subagent, produce a structured handoff document following the format specified in Section 4, including active branch, head commit SHA, and uncommitted stash inventory.
8. **Iterative Bisection & Discovery Loop:**
   * When lockstep QA detects a desync, crash, or unhandled jump table, follow the bisection protocol: Role C bisects the frame to the offending PC, Role A analyzes the disassembly/CDL to update `config/jumptables.ini` or `config/symbols.ini`, Role B re-transpiles the affected bank, and Role C re-verifies from the snapshot.
9. **Strict Git Branch & Gate Boundary Isolation:**
   * Under no circumstances may any subagent commit modernization features directly to `main` or merge a feature branch without passing the automated oracle regression suite (`test_oracle`).
   * Modernization features must be developed on their designated gate branch (`gate/2-mouse-input`, `gate/3-widescreen`) or experimental spike branch (`spike/*`).
10. **Git Worktree Isolation for Lockstep QA & Toolchains:**
    * When running the complete 83,450-frame lockstep regression test or performing cross-platform MinGW builds, agents must use a dedicated Git worktree (`git worktree add ../ob-qa-worktree`) to eliminate file locking and CMake cache contamination.
11. **Bisection Commit Traceability:**
    * When committing bug fixes from bisection, the commit message must record the exact failing Frame Number, PC Address, and Divergent WRAM location (e.g., `fix(bank05): resolve frame 8547 divergence at WRAM 0x7E:0007 ($05:8299)`).

---

## 2. Specialized Subagent Role Definitions & Git Responsibilities

```mermaid
graph TD
    Orchestrator["Lead Orchestrator Agent\n(main & gate branches, release tags)"] --> SubA["Role A: Disassembly & CDL Specialist\n(branch: data/symbols)"]
    Orchestrator --> SubB["Role B: Automated Lifter & Transpiler\n(branch: lifter/bank-transpile)"]
    Orchestrator --> SubC["Role C: Lockstep QA & Debugger\n(worktree: ../ob-qa-worktree)"]
    Orchestrator --> SubD["Role D: Renderer & Modernization\n(branches: gate/2-mouse, gate/3-wide, spike/*)"]

    SubA <-->|Symbols & Jump Tables / Bisection Queries| SubB
    SubB <-->|Generated C Routines / Memory Desync Deltas| SubC
    SubC -->|Discovered Anomalies & Frame Snapshots| SubA
    SubC -->|Gate 1 Certified (0 Drift across all 8 traces)| SubD
    SubD -->|Gate 2 (Mouse) & Gate 3 (16:9)| Orchestrator
```

### Lead Orchestrator Agent
* **Role**: Project governance, gate advancement certification, and Git repository stewardship.
* **Git Responsibilities**:
  * Manages `main` branch merges and tags milestone releases (`v0.1.0-gate1-certified`, `v0.2.0-gate2-mouse`, `v0.3.0-gate3-wide`).
  * Enforces the Pre-Push Oracle Verification Gate before fast-forwarding or merging feature branches.

### Role A: Disassembly & CDL Specialist
* **Focus**: Empirical analysis using Mesen-S CDL traces, tracing CFG from vectors, resolving jump tables, and tracking $M/X$ flags.
* **Git Branch**: `data/symbols-and-jumptables`
* **Git Output**: Atomic commits targeting `config/symbols.ini`, `config/jumptables.ini`, and `tools/crawler.py`. Never touches gameplay C code directly.

### Role B: Automated Lifter & Subsystem Transpiler
* **Focus**: Executing the 65816-to-C pipeline for 100% ROM coverage, and refactoring targeted modules into typed C.
* **Git Branch**: `lifter/bank-transpilation`
* **Git Output**: Commits updating code generators (`tools/autogen.py`) and generated translation units (`src/gen/ob_bank_*.c`).

### Role C: Lockstep QA & Regression Debugger
* **Focus**: Running the dual-execution harness (`RM_BOTH`), managing the 8 walkthrough traces (`.obrec`), capturing `.obsav` snapshots, and bisecting memory desyncs.
* **Git Worktree**: `../ob-qa-worktree` (on `main` or the target gate branch).
* **Git Output**: Commits tracking certified `.obrec` binary fixtures under `traces/`, regression test scripts, and divergence bisection logs.

### Role D: Renderer & Input Modernization Engineer
* **Focus**: Interfacing with LakeSnes virtual PPU, implementing direct-state mouse control (Gate 2), widening map streaming to 16:9 (Gate 3), and prototyping UI workbench features.
* **Git Branches**:
  * `gate/2-mouse-input` (Gate 2 active implementation)
  * `gate/3-widescreen` (Gate 3 active implementation)
  * `spike/roster-workbench`, `spike/mod-loader` (throwaway exploratory branches)
* **Git Output**: Interception patches (`src/engine/map.c`, `src/engine/input.c`), SDL3 input translation, and modular UI shaders.

---

## 3. Subagent Prompt Templates

### Template 1: For Subroutine Transpilation (Role B)
```markdown
You are acting as the Subsystem Transpiler for Ogre Battle PC.
ACTIVE GIT BRANCH: lifter/bank-transpilation

TASK: Lift and refactor the subroutine at SNES address ${BANK}:${ADDR} (Routine Name: ${ROUTINE_NAME}).

CONTEXT & REQUIREMENTS:
1. Entry state: M-flag = ${M_FLAG} (8/16-bit A), X-flag = ${X_FLAG} (8/16-bit Index).
2. Direct Page (DP) base = ${DP_BASE}, Data Bank (DB) = ${DB_BASE}.
3. Reference the disassembly in ${DISASM_FILE} lines ${START_LINE}-${END_LINE}.
4. Translate this routine into idiomatic C using the RECOMP_PATCH(${ROUTINE_NAME}, 0x${SNES_ADDR}) signature.
5. Replace raw WRAM offsets with identified global structs where known.
6. Verify that all stack pushes (PHA, PHX, PHY) match corresponding pulls before any return instruction (RTS/RTL).
7. Do not guess register widths; if a branch modifies REP/SEP, trace both branches.
8. Commit message format: `feat(transpile): lift ${ROUTINE_NAME} at $${BANK}:${ADDR}`
```

### Template 2: For Lockstep Desync Bisection (Role C)
```markdown
You are acting as the Lockstep QA & Regression Debugger for Ogre Battle PC.
ACTIVE GIT WORKTREE: ../ob-qa-worktree (branch: ${CURRENT_GATE_BRANCH})

TASK: Isolate and diagnose a memory mismatch detected during lockstep validation.

INCIDENT DETAILS:
1. Divergence Frame: ${FRAME_NUMBER}
2. Test Scenario / Replay: ${REPLAY_FILE}.obrec (Trace 01-08)
3. Divergent Memory Region: WRAM address 0x${RAM_ADDR} (Expected: 0x${EXPECTED_VAL}, Actual: 0x${ACTUAL_VAL}).

PROCEDURE:
1. Load the snapshot from frame ${PREV_FRAME} into the debug runner.
2. Step instruction-by-instruction across frame ${FRAME_NUMBER} logging all writes to address 0x${RAM_ADDR}.
3. Compare the executed 65816 assembly instruction against the recompiled C function executed at that step.
4. Identify whether the bug is:
   a) Incorrect register width (truncated 16-bit write or expanded 8-bit write).
   b) Unhandled direct page offset arithmetic.
   c) Jump table misdirection or stack return address abuse.
5. Provide a minimal C patch to fix the desync and verify that lockstep parity is restored across all 8 canonical walkthrough traces.
6. Commit message format: `fix(bisection): resolve frame ${FRAME_NUMBER} desync at 0x${RAM_ADDR} (PC: $${BANK}:${PC})`
```

---

## 4. Mandatory Session Handoff Protocol

At the end of every work session or when delegating to another subagent, generate or append a report in `docs/handoffs/HANDOFF-YYYY-MM-DD-sessionN.md` using this exact structure:

```markdown
# Session Handoff: [Session Number]
* **Date**: YYYY-MM-DD
* **Current Milestone**: [e.g., Milestone 4 - Gate 2 Mouse Input]
* **Author / Agent Role**: [e.g., Role D: Renderer & Input Modernization Engineer]
* **Git Status**:
  - Active Branch: [e.g., gate/2-mouse-input]
  - Head Commit SHA: [e.g., a1b2c3d4e5f6]
  - Clean Worktree: [YES / NO (list stashed items if NO)]
  - Stashed Spikes: [e.g., stash@{0}: "spike: radial item menu prototype"]

### 1. Completed & Verified Deliverables
- [Specific functions, build targets, or traces completed]
- [Lockstep verification status: e.g., All 8 canonical traces PASS in RM_BOTH with 0 byte desync]

### 2. Blockers & Open Anomalies
- [Any memory mismatch, compilation error, or unexpected hardware behavior]
- [Exact address, opcode, or function involved]

### 3. Gate Certification Status
- Gate 1 (4:3 Bit-Exact Parity): [CERTIFIED - Tag v0.1.0-gate1-certified]
- Gate 2 (Mouse Input 4:3): [IN PROGRESS / CERTIFIED]
- Gate 3 (16:9 Expanded Viewport): [LOCKED / IN PROGRESS]

### 4. Immediate Next Steps for the Next Agent
- [Step 1: Specific task, target file, and git branch]
- [Step 2: Specific verification command to execute: e.g., ctest -R test_oracle]

### 5. Working Hypotheses & Context Notes
- [Empirical observations, RAM offset mappings discovered, or jump table conventions]
```

---

## 5. Git Operational Protocol & Workflow Standards

### 5.1 Branch Topology & Sequential Gate Gating

```
main (Certified Releases Only)
  │
  ├── tag: v0.1.0-gate1-certified (83,450 frames 0-drift baseline)
  │     │
  │     └── gate/2-mouse-input (Active: Direct-state cursor & hybrid input)
  │           │
  │           ├── fix/cursor-jitter-boundary
  │           └── [PR with 100% test_oracle PASS] ──> merged to main (v0.2.0-gate2)
  │                                                           │
  │                                                           └── gate/3-widescreen (16:9 Map Viewport)
  │                                                                 │
  │                                                                 ├── spike/mode7-400x224 (exploratory)
  │                                                                 └── spike/roster-workbench
```

1. **`main` is protected:** Direct commits are forbidden. Every merge to `main` requires:
   - Full automated pass of all 8 canonical walkthrough traces (`test_oracle`, 83,450 frames).
   - Zero byte memory drift in `RM_BOTH` dual-execution mode.
2. **Gate Branches (`gate/X-...`)**:
   - Long-lived feature branches representing formal progression gates.
   - Rebased against `main` whenever bug fixes are committed upstream.
3. **Spike Branches (`spike/...`)**:
   - Disposable proof-of-concept branches for exploratory UI and architectural shims.
   - If a spike fails, delete cleanly: `git branch -D spike/failed-approach`.
   - If a spike succeeds, clean up commits via `git rebase -i` or cherry-pick isolated utilities (`git cherry-pick <hash>`).

### 5.2 Git Worktree Configuration for Parallel Subagent Work

To avoid constant build tree invalidation and file-locking collisions:

```bash
# 1. Primary Development Tree (on gate/2-mouse-input or gate/3-widescreen)
/home/antigravity/

# 2. Dedicated QA & Lockstep Oracle Worktree (runs full 83,450-frame suite)
git worktree add ../ob-qa-worktree main

# 3. Dedicated Cross-Compilation Worktree (Windows MinGW builds)
git worktree add ../ob-win-preview gate/2-mouse-input
```

### 5.3 Automated Git Hooks Specification

All subagents and contributors must install the project pre-commit and pre-push hooks:

#### Pre-Commit Hook (`.git/hooks/pre-commit`):
Prevents committing copyrighted ROM files, large RAM snapshots, and malformed configuration:
```bash
#!/usr/bin/env bash
set -e

# Reject copyrighted ROM files
if git diff --cached --name-only | grep -E '\.(sfc|smc|rom|bin)$'; then
    echo "ERROR: Attempted to commit a copyrighted ROM binary. Commit aborted by Rule 4."
    exit 1
fi

# Reject raw RAM snapshots and temporary test logs
if git diff --cached --name-only | grep -E '(\.obsav|\.log|\.diff)$'; then
    echo "ERROR: Attempted to commit temporary snapshot/log data. Use .gitignore."
    exit 1
fi

# Validate INI & JSON syntax
for file in $(git diff --cached --name-only | grep -E '\.(ini|json)$'); do
    if [ -f "$file" ]; then
        python3 -c "import json, configparser; json.load(open('$file')) if '$file'.endswith('.json') else configparser.ConfigParser().read('$file')" || {
            echo "ERROR: Syntax validation failed for $file."
            exit 1
        }
    fi
done
```

#### Pre-Push Hook (`.git/hooks/pre-push`):
Enforces the Golden Oracle rule before pushing to shared remotes:
```bash
#!/usr/bin/env bash
set -e

echo "=== Running Pre-Push Oracle Verification Gate ==="
./build/test_trace --trace traces/trace_01_boot_to_title.obrec --mode RM_BOTH --exit-on-drift

if [ $? -ne 0 ]; then
    echo "FATAL: Pre-push smoke test failed! Memory drift detected. Push blocked."
    exit 1
fi
echo "Pre-push verification passed."
```

### 5.4 Git Command Recipes for Subagents

| Purpose | Command |
| :--- | :--- |
| **Start Experimental Feature** | `git switch -c spike/roster-drag-drop` |
| **Commit with Bisection Metadata** | `git commit -m "fix(bisection): resolve frame 8547 desync at 0x7E:0007 ($05:8299)"` |
| **Discard Dead-End Experiment** | `git switch gate/2-mouse-input && git branch -D spike/roster-drag-drop` |
| **Clean Up WIP History Before PR** | `git rebase -i main` *(squash / fixup intermediate checkpoints)* |
| **Extract Successful Helper from Spike** | `git cherry-pick <commit-hash>` |
| **Safely Stash Work Before QA Check** | `git stash push -m "WIP: Mode 7 scanline expansion buffer"` |
| **Recover Accidentally Discarded Work** | `git reflog` $\rightarrow$ `git checkout -b recovery-branch HEAD@{N}` |
