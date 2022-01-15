# prolog

A place to experiment with interesting open-source cpp-based operations research and logistics algorithms.


## Status

Early stage. More of a project skeleton right now.


## To Build

The project includes some thirdparty static libraries (macOS x86_64).

To build just run `make` in the root. This calls the `scripts/build.sh` script, which basically uses `cmake` to build the system. The root `Makefile` is just for convenience.


## TODO

- [x] [cmake](https://cmake.org) as primary build system
- [x] [pybindl11](https://github.com/pybind/pybind11) for python scripting
- [x] [sqlite3](https://github.com/sqlite/sqlite) for persistence via [SQLiteCpp](https://github.com/SRombauts/SQLiteCpp)
- [x] [sol2](https://github.com/ThePhD/sol2) for lua scripting (why not!!)
- [x] [commandline](https://github.com/adishavit/argh) library
- [x] [cpp-terminal](https://github.com/jupyter-xeus/cpp-terminal) library
- [ ] [workflow](https://github.com/sogou/workflow)
- [ ] [libpqxx](https://github.com/jtv/libpqxx)
- [ ] some algorithms from google [or-tools](https://developers.google.com/optimization).