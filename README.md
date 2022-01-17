# prolog

A place to experiment with interesting open-source cpp-based software integrations, as well as operations research and logistics algorithms.


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
- [x] [tomlplusplus](https://github.com/marzer/tomlplusplus) for configuration
- [x] [spdlog](https://github.com/gabime/spdlog) for logging
- [x] [libzeromq](https://github.com/zeromq/libzmq) and [cppzmq](https://github.com/zeromq/cppzmq) for messaging
- [x] [doctest](https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md) for testing
- [x] [libpqxx](https://github.com/jtv/libpqxx) for postgresql access
- [x] [indicators](https://github.com/p-ranav/indicators/) library
- [ ] some algorithms from google [or-tools](https://developers.google.com/optimization).
- [ ] [drogon](https://github.com/drogonframework/drogon) for web application
- [ ] [kore](https://github.com/jorisvink/kore) for web application
- [ ] [imgui](https://github.com/ocornut/imgui) for admin gui
- [ ] [cpr](https://github.com/libcpr/cpr) for http requests

## Research

- crossplatform development options:
	- [flutter](https://flutter.dev) cross-platform framework by google (dart)
	- [ultralight](https://ultralig.ht)
