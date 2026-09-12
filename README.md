# CB: A mini builder for C/C++ projects

## Make Executable CB

Bootstrap once with

```
cc cb.c -o cb
```

After that, CB can rebuild itself. Just set `CB_SOURCE` to `cb.c` and run `./cb run`.

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
