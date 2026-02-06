# TI-86 Math Programs

A collection of math programs and utilities for the TI-86 graphing calculator.

## Features

- Math utilities including radical simplification (more in the making)
- Fixed-point arithmetic support
- Interactive menu system
- Input handling

## Prerequisites

You will need a way to connect your TI-86 calculator to your computer. Connection is supported on both Windows and Linux with the appropriate tools (such as TI Connect or TiLP).

## Installation

### Option 1: Compile with Docker (Recommended)

This is the easiest way to compile the project without installing the z88dk compiler locally.

**Using Docker Compose:**
```bash
# Build and run the container
docker-compose up --build

# The compiled program will be in the bin/ folder
```

**Using Docker directly:**
```bash
# Build the Docker image
docker build -t ti86-math .

# Run the container and compile
docker run --rm -v "$(pwd)/bin:/app/bin" ti86-math

# The compiled program will be in the bin/ folder
```

### Option 2: Compile Locally

1. Install the [z88dk compiler](https://github.com/z88dk/z88dk) for your platform
2. Ensure Python 3 is installed (used for post-processing the binary)
3. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/ti-86-math.git
   cd ti-86-math
   ```
4. Build the project:
   ```bash
   make
   ```

The compiled program (`mathfunc.86p`) will be available in the `bin/` directory.

## Usage

After compiling, transfer the `bin/mathfunc.86p` file to your TI-86 calculator using TI Connect, TiLP, or your preferred link software.

## Available Commands

```bash
make          # Build the project
make clean    # Remove all build artifacts
```

## Project Structure

```
ti-86-math/
├── src/              # Source code
│   ├── main.c        # Main entry point
│   ├── menu.c        # Menu system
│   ├── input.c       # Input handling
│   └── math/         # Math utilities
│       ├── simp_radicals.c
│       ├── fixed_point.c
│       └── vieta_formula.c
├── bin/              # Compiled binaries (generated)
├── obj/              # Object files (generated)
├── Dockerfile        # Docker build configuration
├── docker-compose.yml # Docker Compose configuration
└── Makefile          # Build rules
```

## License

This project is open source. Feel free to use, modify, and distribute.
