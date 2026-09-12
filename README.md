# CB: A mini builder for C/C++ projects

## Make Executable CB

```
cc cb.c -o cb
```

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
