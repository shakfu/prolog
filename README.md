# prolog

A place to experiment with interesting open-source cpp-based operations research and logistics algorithms.


## Status

Early stage. More of a project skeleton right now.


## To Build

The project includes some thirdparty static libraries for convenience. These are are built for macOS (amd_64).

To build just run `make` in the root. This calls the `scripts/build.sh` script, which basically uses `cmake` to build the system. The root `Makefile` is just for convenience.


## TODO

- [x] cmake-based build system
- [x] integrate [pybindl11](https://github.com/pybind/pybind11) for python scripting
- [x] embed [sqlite3](https://github.com/sqlite/sqlite) for persistence via [SQLiteCpp](https://github.com/SRombauts/SQLiteCpp)
- [x] integrate [sol2](https://github.com/ThePhD/sol2) for lua scripting (why not!!)
- [x] integrate [commandline](https://github.com/adishavit/argh) library
- [ ] integrate [cpp-terminal](https://github.com/jupyter-xeus/cpp-terminal) library
- [ ] integrate some algorithms from google [or-tools](https://developers.google.com/optimization).
- [ ] integrate [libpqxx](https://github.com/jtv/libpqxx)
- [ ] integrate [workflow](https://github.com/sogou/workflow)
