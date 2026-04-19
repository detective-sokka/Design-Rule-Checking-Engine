# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

A Digital Rule Checking (DRC) system for verifying electronic board components (Pins, Vias, Wires). It tracks violations when objects are created, updated, or removed. Built as a C++17 core engine.

## Commands

```bash
# Initial build (from repo root)
./build.sh         # creates build/ dir, runs cmake + cmake --build

# Rebuild after changes
cd build && cmake --build .

# Run all tests (from build/ directory)
cd build && ctest

# Run a specific test binary
./build/tests/test_drc_engine
./build/tests/test_db_object
./build/tests/test_drc_violation

# Run via Docker
docker-compose up
```

## Architecture

### Source Layout (`src/`, `include/drc_system/`, `tests/`)

Built around two design patterns:

**Observer Pattern**
- `Subject` interface (`include/drc_system/Subject.hpp`): `subscribe()`, `unsubscribe()`, `notify()`
- `Observer` interface (`include/drc_system/Observer.hpp`): `update()`
- `DBObject` implements `Subject` — represents board components; notifies subscribers on changes
- `DRCViolation` implements `Observer` — represents a rule violation between two DBObjects; marks itself for deletion when notified

**Singleton Pattern**
- `DRCEngine` is a singleton (`getInstance()`) — central manager that creates violations between pairs of DBObjects

**Data flow:** DBObjects change → notify subscribed DRCViolations → violations self-manage (mark for deletion) → DRCEngine coordinates lifecycle

### Mocks (`include/drc_system/mocks/`)

- `MockDBObject`: concrete DBObject with configurable ID for testing without real components
- `MockObserver`: GMock-based observer to verify `update()` call expectations

### Testing

Google Test + Google Mock, fetched via CMake `FetchContent` at build time. Tests live in `tests/` — one file per class. Mock headers are in `include/drc_system/mocks/` and referenced via `target_include_directories` in `tests/CMakeLists.txt`.

### Design Diagram

`design/design.plantuml` (rendered as `design/design.svg`) shows the full class hierarchy and pattern relationships.
