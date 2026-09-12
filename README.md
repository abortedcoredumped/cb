# CB: A mini builder for C/C++ projects

## Make Executable CB

Build the tool itself with the system compiler:

```
cc cb.c -o cb
```

CB does not rebuild itself — re-run that command after editing `cb.c`.

The macros in `cb.h` are compile-time configuration: changing them has no effect
until `cb` itself is rebuilt.

## How To Use

Edit the macros in cb.h, for example:

```c
#define CB_COMPILER  "cc"
#define CB_OPTION    "-Wall"
#define CB_SOURCE    "test.c"
#define CB_TARGET    "test"
```

Then, build the project with:

```
./cb run -- foo bar
```

For more support, run

```
./cb help
```
