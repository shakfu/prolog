# Development Notes


## Cmake

- [cmake ref docs](https://cmake.org/cmake/help/v3.22/#reference-manuals)
- [cmake best practices](https://fujii.github.io/2015/10/10/cmake-best-practice/)
- [article](https://crascit.com/2016/01/31/enhanced-source-file-handling-with-target_sources/) on `target_sources()`


## Workflow

```bash
# environment setting to compile workflow with homebrew openssl
export PATH="/usr/local/opt/openssl@1.1/bin:$PATH"
export LDFLAGS="-L/usr/local/opt/openssl@1.1/lib"
export CPPFLAGS="-I/usr/local/opt/openssl@1.1/include"
export PKG_CONFIG_PATH="/usr/local/opt/openssl@1.1/lib/pkgconfig"
export OPENSSL_ROOT_DIR="/usr/local/opt/openssl"
export OPENSSL_LIBRARIES="/usr/local/opt/openssl/lib"
```

## cpr

build with the following for static lib:

```bash
cmake .. -DBUILD_SHARED_LIBS=FALSE
```