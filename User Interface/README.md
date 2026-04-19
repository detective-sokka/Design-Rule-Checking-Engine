# DRC System — Rust UI

A desktop UI for the Design Rule Checking (DRC) system, built with [Slint](https://slint.dev/) 1.15.1.

> **Note:** This UI is currently a placeholder counter demo and is not yet connected to the C++ DRC engine.

## Prerequisites

Install the Rust toolchain via [rustup](https://rustup.rs/):

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

## Build and Run

```bash
# Build
cargo build

# Run
cargo run
```

## Project Structure

```
User Interface/
├── src/
│   └── main.rs            # Application entry point
├── ui/
│   └── app-window.slint   # UI definition (Slint markup)
├── build.rs               # Slint build script (compiles .slint files)
└── Cargo.toml
```
