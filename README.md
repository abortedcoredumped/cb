# CB: A mini builder for C/C++ projects

Follow the steps to build your project with CB.

## Make Executable CB

Edit the macros in cb.h, for example:

```c
#define CB_COMPILER  "cc"
#define CB_OPTION    "-Wall"
#define CB_SOURCE    "test.c"
#define CB_TARGET    "test"
```

Alter the values with your actual project files.

Then, build the tool itself with the system compiler:

```
cc cb.c -o cb
```

Note, CB does not rebuild itself. Since configuration is saved in cb.h, where compilation burns it into image.

## Build project files

Build the project with:

```
./cb run -- foo bar
```

For more support, run

```
./cb help
```
