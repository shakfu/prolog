# prolog

A place to experiment with interesting open-source cpp-based operations research and logistics algorithms.


## Status

Early stage, more of a project skeleton right now.


## To Build

The project includes some (macOS x86_64) third-party static libraries for development convenience.

To build just run `make` in the project root. This calls the `scripts/build.sh` script, which basically uses `cmake` to build the application and its related targets. 

The root `Makefile` is just for convenience.


## TODO

- [x] [cmake](https://cmake.org) as primary build system
- [x] [pybindl11](https://github.com/pybind/pybind11) for python scripting
- [x] [sqlite3](https://github.com/sqlite/sqlite) for persistence via [SQLiteCpp](https://github.com/SRombauts/SQLiteCpp)
- [x] [sol2](https://github.com/ThePhD/sol2) for lua scripting (why not!!)
- [x] [args](https://github.com/Taywee/args) library for command-line parsing.
- [x] [cpp-terminal](https://github.com/jupyter-xeus/cpp-terminal) library
- [x] [workflow](https://github.com/sogou/workflow) engine for microservices
- [x] [taskflow](https://github.com/taskflow/taskflow) task programming system
- [x] [webview](https://github.com/webview/webview) web viewing library
- [ ] [tomlplusplus](https://github.com/marzer/tomlplusplus) for configuration
- [ ] [indicators](https://github.com/p-ranav/indicators/) library
- [ ] [libpqxx](https://github.com/jtv/libpqxx)
- [ ] some algorithms from google [or-tools](https://developers.google.com/optimization).


## Research

- crossplatform development options:
	- [flutter](https://flutter.dev) cross-platform framework by google (dart)
	- 
- 