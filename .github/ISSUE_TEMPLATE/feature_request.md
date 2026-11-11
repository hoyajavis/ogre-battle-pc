---
name: Feature Request / Modernization Proposal
about: Suggest a modern strategy feature, ergonomic improvement, or UI enhancement
title: "[FEAT]: "
labels: enhancement
assignees: ''
---

**Modernization Pillar / Area**
- [ ] 16:9 Viewport & Viewport Framing
- [ ] Area 1: Zero-Invasion Telemetry (Chaos Frame, combat forecast, promotion checklist)
- [ ] Area 2: Input Injection & Navigation (mouse steering, radial items, hotkeys)
- [ ] Area 3: Tactile Roster Workbench (drag-and-drop squad formation, equipment sockets)
- [ ] Area 4: Boot-Time JSON Mod Manifests (rebalance packs, seed generation)
- [ ] Other

**Target Profile**
- [ ] Profile A: Legacy Purist (strict 1993 feel, optional display toggles)
- [ ] Profile B: Modern PC Strategy Gamer (streamlined UX, zero nested menu fatigue)
- [ ] Profile C: Modder & Randomizer Runner (transparent data tables, seed tracking)

**Proposed Enhancement Description**
A clear description of what the feature would do and how it improves player experience.

**Non-Destructive Implementation Mechanism**
Explain how this feature hooks into runtime state (`RECOMP_PATCH`, 60Hz read-only WRAM polling, or boot-time table builder) without disturbing the 4:3 simulation core.
