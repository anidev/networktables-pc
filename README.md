networktables-pc
================

WPILib NetworkTables C++ for PC.

Pulled directly from WPILib revision 3622 with a few minor changes and bugfixes.

Use CMake to compile and install:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ sudo make install
```

Will install to `/usr/local` by default, change that with `cmake .. -DCMAKE_INSTALL_PREFIX=<prefix>`

Headers installed to `<prefix>/include/networktables`. Shared library is libnetworktables.so
and static library is libnetworktables_static.a, both of which are in `<prefix>/lib`.

Tested to compile and run as server (test with WPILib TableViewer and provided test server),
completely untested on Windows.
