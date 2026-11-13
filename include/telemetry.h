#ifndef OB_TELEMETRY_H
#define OB_TELEMETRY_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ==========================================================================
 * Modernization Area 1: "Zero-Invasion" Read-Only Telemetry Layer
 * ==========================================================================
 * Strictly read-only 60Hz VBlank observation engine polling SNES 128KB WRAM
 * ($7E:0000 - $7F:FFFF) and decoupled ROM tables without mutating a single
 * byte of emulator state.
 * ========================================================================== */

#define OB_WRAM_SIZE_BYTES       (128 * 1024)
#define OB_ROM_BASE_SIZE_BYTES   1572864U
#define OB_MAX_ROSTER_UNITS      100
#define OB_MAX_SQUADS             25
#define OB_MAX_SQUAD_MEMBERS       5
#define OB_MAX_DEPLOYED_SLOTS     21  /* Slots 0..9: Player, Slots 10..20: Enemy */
#define OB_MAX_STAGE_CITIES       20
#define OB_MAX_COMBATANTS         10  /* Slots 0..4: Player, Slots 5..9: Enemy   */
#define OB_MAX_TAROT_HAND         14
#define OB_MAX_CAMP_INVENTORY    126
#define OB_MAX_STAGES             30
#define OB_STORY_BITMAP_BYTES    293  /* 2,344 bits across $7E:8600..$7E:8F27    */
#define OB_CHRONICLE_BLOCK_BYTES  68  /* $7E:F028..$7E:F06B                      */

/* Companion Window / HUD View Modes */
typedef enum {
    OB_HUD_OFF = 0,          /* Profile A: Companion window hidden / paused */
    OB_HUD_MINIMAL,          /* Compact Chaos Frame, Calendar & Noon Tribute */
    OB_HUD_TACTICIAN,        /* Profile B: 4-Panel Tactical Companion Window */
    OB_HUD_EXPLORER          /* Profile C / Dev: Deep Kinematics, AI & Bit-Diffs */
} ObTelemetryHudMode;

/* Active Game Screen Classification (derived from $7E:00CB / $7E:00CC / $7E:07A2) */
typedef enum {
    OB_SCREEN_UNKNOWN = 0,
    OB_SCREEN_TITLE_BOOT,
    OB_SCREEN_WARREN_QUIZ,
    OB_SCREEN_WORLD_MAP,
    OB_SCREEN_TACTICAL_MAP,
    OB_SCREEN_COMBAT_CLASH,
    OB_SCREEN_CAMP_ROSTER,
    OB_SCREEN_TOWN_TEMPLE,
    OB_SCREEN_EPILOGUE
} ObScreenCategory;

/* Tier 1: Individual Roster Character State ($7E:07BA .. $7E:F878) */
typedef struct {
    uint8_t  slot_index;     /* 0..99 */
    bool     is_populated;   /* template_id != 0 && class_id != 0 */
    uint8_t  template_id;    /* $7E:07BA, X: Name/Portrait ID (>= 0x52 special hero) */
    uint8_t  class_id;       /* $7E:085A, X: Class ID ($01 Fighter .. $7D Galf) */
    uint8_t  status_mask;    /* $7E:08FA, X: 0x40=Large, 0x20=Undead, 0x10=Werewolf, 0x08=Tiger, 0x04=Vamp */
    uint8_t  level;          /* $7E:F148, X: Experience level (1..50) */
    uint8_t  exp;            /* $7E:F1E8, X: Experience points (0..99) */
    uint16_t hp_current;     /* $7E:099A, 2*X (LE): Live Hit Points (0 = Dead) */
    uint16_t hp_max;         /* $7E:0ADA, 2*X (LE): Maximum Hit Points */
    uint8_t  str;            /* $7E:F24C, X: Effective Strength */
    uint8_t  agi;            /* $7E:F2EC, X: Effective Agility */
    uint8_t  intel;          /* $7E:F38C, X: Effective Intelligence */
    uint8_t  cha;            /* $7E:F42C, X: Charisma (0..100) */
    uint8_t  ali;            /* $7E:0C1A, X: Alignment (0..100) */
    uint8_t  luk;            /* $7E:F490, X: Luck (0..100) */
    uint16_t deploy_cost;    /* $7E:F4F4, 2*X (LE): Daily Goth deployment fee */
    uint16_t career_record;  /* $7E:0C7E, 2*X (LE): Cumulative kill/soul record */
    uint8_t  equipped_item;  /* $7E:F5BC, X: Equipped item ID */
    uint8_t  squad_id;       /* $7E:0F35, X: Assigned squad ID (0xFF = unassigned) */
    uint8_t  resistances[6]; /* $7E:F621..$7E:F878: Phys, Fire, Cold, Elec, Black, White */
} ObUnitTelemetry;

/* Tier 1: Persistent Player Squad Formation ($7E:0DCD, $7E:0E81, $7E:F901) */
typedef struct {
    uint8_t  squad_index;    /* 0..24 */
    bool     has_leader;
    uint8_t  tactic_stance;  /* $7E:F901, S: 0=Leader, 1=Strong, 2=Weak, 3=Best */
    uint8_t  member_ids[OB_MAX_SQUAD_MEMBERS];     /* $7E:0E81 + 5*S (0xFF = empty) */
    uint8_t  grid_positions[OB_MAX_SQUAD_MEMBERS]; /* Low nibble of $7E:0DCD + 5*S */
    uint8_t  actions_left[OB_MAX_SQUAD_MEMBERS];   /* High nibble of $7E:0DCD + 5*S */
    uint16_t total_deploy_cost;
    uint8_t  avg_alignment;
    uint8_t  avg_level;
    uint8_t  member_count;
} ObSquadTelemetry;

/* Tier 2 (Domains E & F): Active Tactical Map Squad Kinematics & AI State ($7E:18AF .. $7E:1A94) */
typedef struct {
    uint8_t  deployed_slot;  /* 0..9 Player Squads, 10..20 Enemy Squads */
    bool     is_enemy;       /* deployed_slot >= 10 */
    bool     is_active;      /* world_x != 0x7FFF && world_x != -1 */
    int16_t  world_x;        /* $7E:18AF, 2*S */
    int16_t  world_y;        /* $7E:18D9, 2*S */
    int16_t  target_x;       /* $7E:1905, 2*S */
    int16_t  target_y;       /* $7E:192D, 2*S */
    int16_t  vel_dx;         /* $7E:1955, 2*S */
    int16_t  vel_dy;         /* $7E:197D, 2*S */
    uint16_t ai_order_state; /* $7E:19A5, 2*S: AI command & target entity index */
    uint16_t fatigue_stun;   /* $7E:19CD, 2*S: Post-clash knockback stun / rest timer */
    uint16_t mobility_speed; /* $7E:1A11, 2*S: Terrain-adjusted movement rate */
    uint8_t  move_type;      /* $7E:1A45 low byte (0=High Sky .. 9=Slow) */
    uint8_t  terrain_under;  /* $7E:1A45 high byte */
    uint8_t  facing_dir;     /* $7E:1A6D low byte */
} ObMapEntityTelemetry;

/* Tier 2 (Domain H): Active Stage City & Temple State ($7E:1A95 .. $7E:1C9D) */
typedef struct {
    uint8_t  city_index;     /* 0..19 */
    bool     exists;         /* world_x != 0x7FFF && world_x > 0 */
    int16_t  world_x;        /* $7E:1A95, 2*C */
    int16_t  world_y;        /* $7E:1B0D, 2*C */
    uint16_t tribute_base;   /* $7E:1B5D, 2*C */
    uint8_t  shop_id;        /* $7E:1C11, 2*C */
    uint8_t  compatibility;  /* $7E:1C25, 2*C: Town alignment / moral affinity */
    uint8_t  ownership_mask; /* $7E:1C4D, 2*C: Player/Enemy/Temple/Hidden bitflags */
    uint8_t  live_morale;    /* $7E:1C75, 2*C: Real-time morale (0..100) */
    uint8_t  event_drawn;    /* $7E:1C9D, 2*C: Temple Tarot drawn / event triggered */
} ObCityTelemetry;

/* Tier 2 (Domain G): Live Combat Arena Micro-Telemetry ($7E:F925 .. $7E:F9FC) */
typedef struct {
    bool     in_combat;
    uint8_t  active_tactic;          /* $7E:F92E (0=Leader, 1=Strong, 2=Weak, 3=Best) */
    uint8_t  acting_slot;            /* $7E:F931 (0..9) */
    uint8_t  target_slot;            /* $7E:F934 (0..9) */
    uint8_t  attack_element;         /* $7E:F93A */
    uint8_t  hit_outcome_flags;      /* $7E:F93B (Hit/Miss/Crit/Block bitmask) */
    uint8_t  last_hit_damage;        /* $7E:F93C */
    uint8_t  total_actions_left;     /* $7E:F941 */
    uint16_t player_clash_damage;    /* $7E:F942: Cumulative HP damage dealt by Player */
    uint16_t enemy_clash_damage;     /* $7E:F944: Cumulative HP damage dealt by Enemy */
    uint8_t  turn_queue[OB_MAX_COMBATANTS];      /* $7E:F977, X */
    uint8_t  combat_status[OB_MAX_COMBATANTS];   /* $7E:F982, X */
    uint8_t  roster_id[OB_MAX_COMBATANTS];       /* $7E:F98C, X */
    uint8_t  attacks_left[OB_MAX_COMBATANTS];    /* $7E:F996, X */
    uint8_t  grid_pos[OB_MAX_COMBATANTS];        /* $7E:F9AA, X */
    uint8_t  active_skill_id[OB_MAX_COMBATANTS]; /* $7E:F9C8, X */
} ObCombatTelemetry;

/* Tier 2 (Domain H): 7-Register Celestial & Lunar Calendar ($7E:156D .. $7E:1575) */
typedef struct {
    uint8_t  year;           /* $7E:156D (starts at 1, leap-year when (year & 3) == 0) */
    uint8_t  month;          /* $7E:156E (1..12) */
    uint8_t  lunar_weekday;  /* $7E:156F (0..7 8-day lunar week cycle) */
    uint8_t  day;            /* $7E:1570 (1..31) */
    uint8_t  hour;           /* $7E:1571 (0..23; 12 = Noon tribute, 18 = Dusk, 6 = Dawn) */
    uint8_t  minute;         /* $7E:1572 (0..59) */
    uint8_t  sub_tick;       /* $7E:1573 (0..59) */
    uint8_t  clock_speed;    /* $7E:1575 */
    bool     is_nighttime;   /* hour >= 18 || hour < 6 (Werewolf/Vampire/Undead active) */
    uint16_t minutes_to_noon;/* Countdown until 12:00 Noon Goth tribute */
    uint16_t minutes_to_phase_shift; /* Countdown until 06:00 Dawn or 18:00 Dusk */
} ObCalendarTelemetry;

/* Complete View-Agnostic 60Hz Frame Snapshot combining Tier 1 & Tier 2 */
typedef struct {
    uint32_t             frame_counter;
    ObScreenCategory     screen_category;
    uint8_t              raw_mode_cb;        /* $7E:00CB */
    uint8_t              raw_mode_cc;        /* $7E:00CC */
    uint16_t             raw_mode_07a2;      /* $7E:07A2 */
    uint8_t              bgm_track_id;       /* $7E:00D4 */
    uint8_t              sfx_last_id;        /* $7E:00D5 */
    int16_t              cursor_screen_x;    /* Active OAM cursor X ($7E:0100..$7E:013F) */
    int16_t              cursor_screen_y;    /* Active OAM cursor Y */
    int16_t              camera_world_x;     /* $7E:0420 / Mode-7 scroll X */
    int16_t              camera_world_y;     /* $7E:0422 / Mode-7 scroll Y */
    uint8_t              lord_profile[17];   /* $7E:07A4 */
    uint32_t             goth_treasury;      /* $7E:1578..$7E:157B (32-bit LE) */
    int32_t              projected_noon_net; /* Liberated Tribute - Deployed Squad Upkeep */
    uint32_t             active_upkeep_drain;
    uint32_t             projected_tribute_income;
    uint8_t              chaos_frame;        /* $7E:157C (0..100) */
    uint8_t              chaos_frame_sub;    /* $7E:157D */
    uint16_t             stages_cleared_cnt; /* $7E:1576 */
    uint8_t              boss_aggro_state;   /* $7E:15FC */
    uint8_t              stage_event_locks[5]; /* $7E:1659..$7E:165D */
    uint16_t             enemy_spawn_timer;  /* $7E:12B3 */
    uint16_t             enemy_spawn_wave;   /* $7E:12B5 */
    uint16_t             prng_entropy_sample;/* $7F:0000..$7F:0001 sample */
    ObCalendarTelemetry  calendar;
    uint8_t              active_roster_count;
    ObUnitTelemetry      units[OB_MAX_ROSTER_UNITS];
    ObSquadTelemetry     squads[OB_MAX_SQUADS];
    ObMapEntityTelemetry map_entities[OB_MAX_DEPLOYED_SLOTS];
    ObCityTelemetry      cities[OB_MAX_STAGE_CITIES];
    ObCombatTelemetry    combat;
    uint8_t              tarot_hand[OB_MAX_TAROT_HAND];       /* $7E:0DBE */
    uint8_t              tarot_hand_count;
    uint8_t              camp_inventory[OB_MAX_CAMP_INVENTORY];/* $7E:157E */
    uint8_t              stage_flags[OB_MAX_STAGES];          /* $7E:1723 */
    uint8_t              stage_aux_1741[7];                   /* $7E:1741 */
    uint8_t              stage_aux_1748[4];                   /* $7E:1748 */
    uint8_t              story_bitmap[OB_STORY_BITMAP_BYTES]; /* $7E:8600..$7E:8F27 */
    uint8_t              chronicle_block[OB_CHRONICLE_BLOCK_BYTES]; /* $7E:F028..$7E:F06B */
} ObTelemetryFrame;

/* Bitflag / State Transition Event emitted by ob_telemetry_diff_frames() */
typedef struct {
    uint32_t frame_number;
    uint16_t wram_address;   /* e.g., 0x8600 + byte_offset */
    uint16_t bit_index;      /* 0..2343 for story_bitmap, or 0xFFFF for byte change */
    uint8_t  old_value;
    uint8_t  new_value;
    char     category[24];   /* "STORY_BIT_A", "TREASURE_BIT_B", "RECRUIT_BIT_C", "CHAOS_FRAME", etc. */
} ObTelemetryDiffEvent;

/* Pluggable Frontend Presentation Sink (Companion Window now; 16:9 Wings post-Gate 3) */
typedef struct {
    const char *sink_name;
    void (*on_frame)(const ObTelemetryFrame *prev, const ObTelemetryFrame *curr, void *userdata);
    void *userdata;
} ObTelemetrySink;

/* Strictly read-only polling entry point: accepts const WRAM and const ROM pointers */
void ob_telemetry_poll_vblank(
    const uint8_t *wram,
    const uint8_t *rom,
    uint32_t rom_size,
    uint32_t frame_counter,
    ObTelemetryFrame *out_frame
);

/* Diffs two consecutive frames to capture bitflag transitions (0->1 / 1->0) and state deltas */
size_t ob_telemetry_diff_frames(
    const ObTelemetryFrame *prev_frame,
    const ObTelemetryFrame *curr_frame,
    ObTelemetryDiffEvent *out_events,
    size_t max_events
);

/* Formats diff events as newline-delimited JSON strings */
size_t ob_telemetry_format_diff_jsonl(
    const ObTelemetryDiffEvent *events,
    size_t event_count,
    char *out_buf,
    size_t max_len
);

/* Looks up the ASCII class name from the active ROM buffer (0x8BB29 table) */
const char *ob_telemetry_get_class_name(
    const uint8_t *rom,
    uint32_t rom_size,
    uint8_t class_id,
    char *out_name,
    size_t max_len
);

#ifdef __cplusplus
}
#endif

#endif /* OB_TELEMETRY_H */
