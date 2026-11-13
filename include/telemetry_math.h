#ifndef OB_TELEMETRY_MATH_H
#define OB_TELEMETRY_MATH_H

#include "telemetry.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==========================================================================
 * Deterministic Predictive Math Engine (Area 1)
 * ==========================================================================
 * Pure functions operating strictly on const telemetry snapshots and const
 * in-memory ROM tables (Area 4 compatible).
 * ========================================================================== */

#define OB_MAX_PROMO_BRANCHES 16

/* Branching Class Promotion Prerequisite Evaluation */
typedef struct {
    uint8_t  source_class_id;
    uint8_t  target_class_id;
    char     target_class_name[16];
    bool     eligible_now;
    uint8_t  req_min_level;
    uint8_t  req_min_ali;
    uint8_t  req_max_ali;
    uint8_t  req_min_cha;
    int8_t   level_delta;     /* <= 0 if satisfied; > 0 if levels still needed */
    int8_t   ali_delta;       /* 0 if inside [req_min_ali, req_max_ali]; < 0 if too high; > 0 if too low */
    int8_t   cha_delta;       /* <= 0 if satisfied; > 0 if CHA still needed */
    uint8_t  required_relic;  /* 0 if standard branch; else relic item ID (Crown, Undead Staff, etc.) */
    bool     relic_in_stock;  /* True if required_relic is present in Camp Inventory or equipped */
} ObPromotionCheck;

/* Pre-Clash Alignment (ALI) & Charisma (CHA) Kill-Delta Forecast */
typedef struct {
    uint8_t  attacker_slot;
    uint8_t  defender_slot;
    int8_t   predicted_ali_delta; /* Signed ALI change if attacker kills defender */
    int8_t   predicted_cha_delta; /* Signed CHA change if attacker kills defender */
    bool     overlevel_penalty;   /* True if attacker is significantly higher level than target */
    bool     holy_on_law_penalty; /* True if high-ALI unit kills lawful/holy target */
} ObMoralityDriftForecast;

/* Spatial Interceptor Time-to-Contact (TTC) & Clash Tug-of-War Forecast */
typedef struct {
    uint8_t  player_deployed_slot;
    uint8_t  enemy_deployed_slot;
    int32_t  manhattan_distance_px;
    int32_t  closing_speed_px_per_tick;
    int32_t  estimated_ticks_to_contact; /* -1 if diverging or stationary */
    int16_t  clash_damage_margin;        /* player_clash_damage - enemy_clash_damage */
    bool     player_winning_clash;
} ObTacticalEngagementForecast;

/* Town Liberation Compatibility Recommendation */
typedef struct {
    uint8_t  city_index;
    uint8_t  recommended_squad_id; /* 0..24 best deployed squad to liberate this town */
    int8_t   predicted_cf_delta;   /* Estimated Chaos Frame change (+2, +1, 0, -1, -2) */
    uint8_t  ali_mismatch_distance;/* |Squad_Avg_ALI - City_Compatibility| */
} ObCityLiberationMatch;

/* 13-Ending Condition Audit Result */
typedef struct {
    uint8_t  projected_ending_id;  /* 0..12 corresponding to the 13 Major Arcana endings */
    char     ending_name[24];      /* e.g. "THE WORLD", "THE SUN", "THE DEVIL" */
    char     nearest_alt_name[40]; /* Nearest alternate ending & what flag flips it */
    char     audit_summary[128];   /* Human-readable requirement breakdown */
} ObEndingAudit;

/* Evaluates all promotion branches for a given unit against active ROM tables */
size_t ob_telemetry_eval_promotions(
    const ObUnitTelemetry *unit,
    const uint8_t *wram,
    const uint8_t *rom,
    uint32_t rom_size,
    ObPromotionCheck *out_branches,
    size_t max_branches
);

/* Predicts ALI and CHA drift if attacker lands a killing blow on defender */
void ob_telemetry_predict_kill_morality(
    const ObUnitTelemetry *attacker,
    const ObUnitTelemetry *defender,
    bool disable_overlevel_ali_penalty,
    ObMoralityDriftForecast *out_forecast
);

/* Evaluates spatial closing velocity, ETA, and live combat tug-of-war margin */
void ob_telemetry_eval_engagement(
    const ObMapEntityTelemetry *player_entity,
    const ObMapEntityTelemetry *enemy_entity,
    const ObCombatTelemetry *combat,
    ObTacticalEngagementForecast *out_forecast
);

/* Matches unliberated stage cities against deployed player squads for optimal Chaos Frame */
size_t ob_telemetry_match_city_liberators(
    const ObTelemetryFrame *frame,
    ObCityLiberationMatch *out_matches,
    size_t max_matches
);

/* Audits the 13 campaign endings against current Chaos Frame, Leader ALI, and story bitflags */
void ob_telemetry_audit_ending(
    const ObTelemetryFrame *frame,
    ObEndingAudit *out_audit
);

/* ==========================================================================
 * Phase 5B: Walkthrough-Driven Predictive Models & Mechanics Auditing
 * ========================================================================== */

/* Recapture Threat & -5 Chaos Frame Penalty Alert */
typedef struct {
    uint8_t  enemy_slot;         /* 10..20 */
    uint8_t  target_city_index;  /* 0..19 */
    int32_t  distance_px;
    int32_t  eta_ticks;
    bool     is_temple;
    int8_t   penalty_cf;         /* Always -5 */
    char     threat_summary[64];
} ObRecaptureThreat;

/* Live Terrain Neutral Encounter & Persuasion Readiness */
typedef struct {
    uint8_t  squad_index;
    uint8_t  terrain_id;
    char     terrain_name[16];
    char     spawn_class_name[16];
    uint8_t  spawn_level;
    char     recruiter_class_name[16];
    bool     persuade_ready;
    bool     is_undead_ali_farm;
    bool     is_pumpkin_ali_tank;
} ObNeutralSpawnForecast;

/* Tarot Card Hand Detail & Opinion Leader Kill-XP / ALI Trap Guard */
typedef struct {
    uint8_t  card_id;
    char     card_name[16];
    char     draw_effect[32];
    char     battle_effect[32];
    bool     is_offensive;
    bool     leader_overlevel_risk;
} ObTarotAudit;

/* 18 Special Character Recruitment & Relic Prerequisite Audit */
typedef struct {
    uint8_t  hero_id;            /* 0..17 */
    char     hero_name[16];
    char     stage_found[24];
    bool     is_recruited;
    bool     prereq_cf_met;
    bool     prereq_ali_met;
    bool     prereq_item_met;
    char     required_item_name[24];
    char     tradeoff_warning[48];
    char     status_summary[64];
} ObHeroRecruitmentAudit;

/* 12 Zodiac Stones, Tablet of Yaru & 4-Wind Fireseal Quest Tracker */
typedef struct {
    bool     quicksilver_in_hand;    /* Pogrom Forest trade item */
    bool     gem_of_doun_in_hand;    /* Dalmuhd Desert trade item */
    bool     olden_orb_in_hand;      /* Pogrom Forest trade item */
    bool     gem_of_truth_in_hand;   /* Rhyan Sea trade item */
    bool     tablet_of_yaru_in_hand; /* Shangrila key item */
    uint8_t  stones_collected_count; /* 0..12 */
    uint16_t stones_mask;            /* 12 bits */
    bool     beehive_in_hand;        /* Diaspola Posha quest */
    bool     sentoul_demon_in_hand;
    bool     ginger_cake_in_hand;
    bool     pearl_stone_ready;
    uint8_t  wind_weapons_mask;      /* Notos(1), Zephyrus(2), Boreas(4), Euros(8) */
    bool     fireseal_ready;
} ObZodiacQuestStatus;

/* Squad Mobility Tier, Flyer Requirements & Day/Night Synergy */
typedef struct {
    uint8_t  squad_index;
    uint8_t  move_type_id;
    char     move_type_name[16];
    uint8_t  flyers_count;
    uint8_t  flyers_needed_for_sky;
    char     effective_terrain[16];
    bool     is_day_favored;
    bool     is_night_favored;
    char     synergy_summary[48];
} ObSquadMobilityAnalysis;

/* Warren's Divination Quiz 4-Archetype Previewer */
typedef struct {
    uint8_t  projected_archetype;    /* 0=Holy/Icecloud, 1=Iainuki, 2=Thunder, 3=Phantom */
    char     archetype_name[32];
    char     front_skill[20];
    char     back_skill[20];
    char     starting_troops[32];
    uint8_t  projected_starting_ali;
} ObLordArchetypePreview;

/* Hidden City / Temple & Buried Treasure Ledger */
typedef struct {
    uint8_t  total_cities;
    uint8_t  hidden_cities_count;
    uint8_t  unrevealed_cities_count;
    uint8_t  hidden_temples_count;
    uint8_t  unrevealed_temples_count;
    uint8_t  buried_treasures_total;
    uint8_t  buried_treasures_found;
    uint8_t  unliberated_cities_count;
} ObHiddenPoISummary;

/* Detects enemy squads marching toward player-liberated cities/temples (-5 CF penalty) */
size_t ob_telemetry_detect_recapture_threats(
    const ObTelemetryFrame *frame,
    ObRecaptureThreat *out_threats,
    size_t max_threats
);

/* Predicts neutral monster spawns and persuasion feasibility on current squad terrain */
void ob_telemetry_forecast_neutral_encounters(
    const ObTelemetryFrame *frame,
    uint8_t squad_index,
    ObNeutralSpawnForecast *out_forecast
);

/* Audits player's 14-card Tarot hand and flags Opinion Leader overlevel/ALI traps */
size_t ob_telemetry_audit_tarot_hand(
    const ObTelemetryFrame *frame,
    ObTarotAudit *out_audits,
    size_t max_cards
);

/* Audits 18 special character recruitment conditions and trade-off warnings */
size_t ob_telemetry_audit_special_recruits(
    const ObTelemetryFrame *frame,
    ObHeroRecruitmentAudit *out_heroes,
    size_t max_heroes
);

/* Tracks progress on the 12 Zodiac Stones, Tablet of Yaru, and 4-Wind Fireseal chain */
void ob_telemetry_track_zodiac_stones(
    const ObTelemetryFrame *frame,
    ObZodiacQuestStatus *out_status
);

/* Analyzes squad movement bottlenecks and day/night/terrain battle multipliers */
void ob_telemetry_analyze_squad_mobility(
    const ObTelemetryFrame *frame,
    uint8_t squad_index,
    ObSquadMobilityAnalysis *out_analysis
);

/* Previews the Opinion Leader archetype and starting battalion during Warren's Quiz */
void ob_telemetry_preview_lord_archetype(
    const uint8_t *wram,
    ObLordArchetypePreview *out_preview
);

/* Audits hidden cities, temples, and buried treasures on the active stage */
void ob_telemetry_audit_hidden_poi(
    const ObTelemetryFrame *frame,
    ObHiddenPoISummary *out_summary
);

#ifdef __cplusplus
}
#endif

#endif /* OB_TELEMETRY_MATH_H */
