# CB: A mini builder for C/C++ projects

## Make Executable CB

```
cc cb.c -o cb
```

## How To Use

Edit the macros in cb.h, for example:

```c
#define CB_COMPILER "cc"
#define CB_OPTION   "-Wall"
#define CB_SOURCE   "test.c"
#define CB_TARGET   "test"
```

Then, feel free to use CB in your own projects.

Here is an example to build and run with arguments:

```
./cb run -- foo bar
```
