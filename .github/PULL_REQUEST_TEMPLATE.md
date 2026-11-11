## Description
<!-- Provide a clear description of the change, problem solved, or feature added. -->

## Associated Milestone / Gate
- [ ] Gate 1: 4:3 Bit-Exact Parity Baseline
- [ ] Gate 2: Direct-State Mouse & Hybrid Input
- [ ] Gate 3: 16:9 Viewport & Map Streaming
- [ ] Modernization Area (1: Telemetry, 2: Navigation, 3: Roster Workbench, 4: JSON Mods)
- [ ] Other / Infrastructure

## Quality Gate Checklist
- [ ] **0-Byte Drift Verified**: Executed `test_oracle` across all 8 canonical `.obrec` traces in `RM_BOTH` mode with zero desyncs.
- [ ] **No ROM Data**: Confirmed zero `.sfc`, `.smc`, `.bin`, `.obsav`, or copyrighted assets in git diff.
- [ ] **Pre-Commit Verified**: `.git/hooks/pre-commit` passed cleanly.
- [ ] **Commit Messages**: Formatted with conventional commit prefixes (and bisection metadata if resolving a desync).
