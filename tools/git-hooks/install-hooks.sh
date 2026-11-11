#!/usr/bin/env bash
# ==============================================================================
# Install Git Hooks into .git/hooks
# ==============================================================================
set -e

HOOK_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
GIT_DIR="$(git rev-parse --git-dir)"

chmod +x "$HOOK_DIR/pre-commit" "$HOOK_DIR/pre-push"
cp -f "$HOOK_DIR/pre-commit" "$GIT_DIR/hooks/pre-commit"
cp -f "$HOOK_DIR/pre-push" "$GIT_DIR/hooks/pre-push"

echo "Installed pre-commit and pre-push hooks into $GIT_DIR/hooks"
