#include "cb.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define cb_info(fmt, ...)                   \
    do {                                    \
        printf("[CB] " fmt, ##__VA_ARGS__); \
    } while (0)

struct {
    int argc;
    int arg_start;
    const char **args;
} cb;

void show_helper(void)
{
    printf("Options:\n"
           "    compile          Compile the project\n"
           "    run [-- args]    Compile and run the project\n");
}

void run_executable(void)
{
    pid_t pid = fork();
    if (pid == 0) {
        int len = cb.argc - cb.arg_start;
        char **child_argv = malloc((len + 2) * sizeof(char *));
        child_argv[0] = "./" CB_TARGET;
        for (int i = 0; i < len; i++) {
            child_argv[i + 1] = (char *)cb.args[cb.arg_start + i];
        }
        child_argv[len + 1] = NULL;
        cb_info("Starting executable...\n");
        fputc('\n', stdout);
        execv("./" CB_TARGET, child_argv);
        _exit(127);
    } else {
        int status;
        waitpid(pid, &status, 0);
        fputc('\n', stdout);
        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);            
            cb_info("Exit code: %d\n", code);
        }
    }
}

// run == 0: Compilation only
// run == 1: Compile and run
void compile_source_code(int run)
{
    pid_t pid = fork();
    if (pid == 0) {
        cb_info("Compiling source...\n");
        execlp(CB_COMPILER, CB_COMPILER, CB_OPTION, CB_SOURCE, "-o", CB_TARGET, NULL);
        _exit(127);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            if (code != 0) {
                cb_info("Exit code: %d\n", code);
                exit(code);
            }
        }
    }
    cb_info("Target built: %s\n", CB_TARGET);
    if (run) {
        run_executable();
    }
}

// Return 0 when fail
int argument_handler(const char **args)
{
    if (cb.argc < 2) {
        return 0;
    }

    for (int i = 2; i < cb.argc; i++) {
        if (!strcmp(args[i], "--")) {
            cb.arg_start = i + 1;
            break;
        }
    }
    
    if (!strcmp(args[1], "run")) {
        compile_source_code(1);
    } else if (!strcmp(args[1], "compile")) {
        compile_source_code(0);
    } else if (!strcmp(args[1], "help")) {
        show_helper();
        exit(0);
    } else {
        return 0;
    }
    return 1;
}

int main(int argc, const char **args)
{
    cb.argc = argc;
    cb.args = args;
    cb.arg_start = argc;
    if (argc == 1 || !argument_handler(args)) {
        show_helper();
        return 1;
    }
    cb_info("Done.\n");
    return 0;
}
