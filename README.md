# prolog

A place to play around with interesting open-source cpp-based operations research and logistics algorithms.


## Status

Early stage. More of a project skeleton right now.


## To Build

The project includes some thirdparty static libraries which are built for macOS (amd_64)

To build just run `make` in the root. This calls the `scripts/build.sh` script, which basically uses `cmake` to build the system. The root `Makefile` is just for convenience.


## TODO

- [x] integrate pybindl11 from the start
- [x] cmake-based build
- [x] embed sqlite3 for persistence