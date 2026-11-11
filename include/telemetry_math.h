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

#ifdef __cplusplus
}
#endif

#endif /* OB_TELEMETRY_MATH_H */
