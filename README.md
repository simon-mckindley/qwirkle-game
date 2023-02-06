# APT - Assignment 2 - Qwirkle Game

This project is a C++ implementation of the game Qwirkle.

## Prerequisites

The following tools must be installed before running the program.

- C++ 14
- CMake [Installation Instructions](https://cgold.readthedocs.io/en/latest/first-step/installation.html)

## Getting Started

1. Run `make deps` to install necessary dependencies for running tests.
2. Run `make` to compile and run the program.

## Testing

This project uses the Google Test unit testing framework.

### Running Tests

Run `make test` to execute all tests.

### Adding a Test Suite

1. Create a new test file following the `*_test.cpp` naming convention.
2. Add the new test file to the CMake configuration in `CMakeLists.txt`.
