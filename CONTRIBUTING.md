# Contributing to Ogre Battle PC Port

Thank you for your interest in contributing to the **Ogre Battle: The March of the Black Queen** 1:1 Native PC Port!

This project bridges Quest's 1993 Super NES classic with modern desktop ergonomics via automated 65816 static recompilation and the LakeSnes silicon runtime. To maintain hardware accuracy while introducing modern features, all development is governed by formal quality gates and regression oracles.

---

## 1. Legal & Repository Cleanliness (Rule 4)

> [!IMPORTANT]
> **This repository strictly forbids committing copyrighted assets.**
> - Never submit ROM dumps (`.sfc`, `.smc`, `.bin`), extracted audio samples, or decompressed sprite assets.
> - All tests and builds require the developer to supply their own legally acquired copy of *Ogre Battle (USA)* (`cfc45162b91791a61d4260e348ad43cb3b2eca0f`).
> - The automated pre-commit hook will reject commits containing binary ROM files. Pull requests containing copyrighted material will be immediately closed.

---

## 2. The Sequential Gate Progression Model

Development proceeds strictly through outer progression gates:

1. **Gate 1: Bit-Exact 4:3 Hardware Parity (100% Certified)**
   * Baseline verified with **0-byte memory drift** across 128KB WRAM, VRAM, OAM, CGRAM, and SRAM over 83,450 canonical gameplay frames.
2. **Gate 2: Direct-State Mouse & Hybrid Input (Active Milestone)**
   * Window cursor coordinates mapped to WRAM `$14E7` / `0x7E:00BD`.
   * Left-click (Joypad A) / Right-click (Joypad B) click injection with instant gamepad handoff.
3. **Gate 3: True 16:9 Viewport Extension (Upcoming Milestone)**
   * 400×224 Mode-7 overland map metatile streaming buffer expansion.

### Rule of the Gates
Under no circumstances may a pull request introduce memory drift or desync to the 4:3 simulation core. Modernizations must operate via non-destructive shims (`RECOMP_PATCH`) or 60Hz read-only WRAM telemetry.

---

## 3. Getting Started & Git Workflow

### 1. Install Git Hooks
Run the hook installation script to ensure commits pass pre-commit checks:
```bash
bash tools/git-hooks/install-hooks.sh
```

### 2. Branching Conventions
* **`main`**: Protected branch. Contains only certified, tested releases.
* **`gate/2-mouse-input`**: Active Gate 2 development.
* **`gate/3-widescreen`**: Active Gate 3 development.
* **`fix/<issue-description>`**: Bug fixes, jump table updates, or M/X flag bisections.
* **`spike/<experiment>`**: Disposable exploratory prototypes (e.g., UI shaders, draft menus). If unviable, delete with `git branch -D`.

### 3. Worktree QA
When running heavy lockstep regressions (`test_oracle`), use a parallel worktree to keep your development workspace clean:
```bash
git worktree add ../ob-qa-worktree main
```

---

## 4. Commit Message Guidelines

Use conventional commit prefixes:
* `feat(...)`: New engine feature, input mapper, or UI overlay.
* `fix(...)`: Bug fix or logic correction.
* `fix(bisection)`: Memory desync resolution. **Must include frame number and WRAM address**:
  ```
  fix(bisection): resolve frame 8547 desync at 0x7E:0007 ($05:8299)
  ```
* `refactor(...)`: Code cleanup without behavior change.
* `test(...)`: Adding or updating `.obrec` test fixtures or oracle runners.
* `docs(...)`: Documentation and architectural specifications.

---

## 5. Pull Request Checklist

Before submitting a pull request, verify:
- [ ] Pre-commit hook passes with zero errors (`tools/git-hooks/pre-commit`).
- [ ] No proprietary ROM files, memory snapshots (`.obsav`), or logs are staged.
- [ ] All 8 canonical regression traces pass in `RM_BOTH` mode with 0-byte memory drift (`ctest -R test_oracle`).
- [ ] Commits are clean and logically squashed (`git rebase -i`).
