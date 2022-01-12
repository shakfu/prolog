# prolog

A place to experiment with interesting open-source cpp-based operations research and logistics algorithms.


## Status

Early stage. More of a project skeleton right now.


## To Build

The project includes some thirdparty static libraries for convenience. These are are built for macOS (amd_64).

To build just run `make` in the root. This calls the `scripts/build.sh` script, which basically uses `cmake` to build the system. The root `Makefile` is just for convenience.


## TODO

- [x] cmake-based build system
- [x] integrate pybindl11 for python scripting
- [x] embed [sqlite3](https://github.com/sqlite/sqlite) for persistence via [SQLiteCpp](https://github.com/SRombauts/SQLiteCpp)
- [ ] integrate sol2 for lua scripting (why not!!)
- [ ] integrate some algorithms from google [or-tools](https://developers.google.com/optimization).
- [ ] integrate [libpqxx](https://github.com/jtv/libpqxx)
