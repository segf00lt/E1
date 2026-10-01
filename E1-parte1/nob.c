#define NOB_IMPLEMENTATION
#include "nob.h"


# if defined(_WIN32)
#  define PLATFORM_WINDOWS 1
# elif defined(__gnu_linux__) || defined(__linux__)
#  define PLATFORM_LINUX 1
# elif defined(__APPLE__) && defined(__MACH__)
#  define PLATFORM_MAC 1
# else
#  error This compiler/OS combo is not supported.
# endif

int build_compiler_win32(void) {
  nob_log(NOB_INFO, "windows build");

  nob_delete_file("compiler.obj");
  nob_delete_file("compiler.lib");
  nob_delete_file("compiler.pdb");

  NOB_ASSERT(!"UNIMPLEMENTED");

  return 1;
}

int build_compiler_linux(void) {
  nob_log(NOB_INFO, "linux build");

  Nob_Cmd cmd = {0};

  nob_cmd_append(&cmd,
    "gcc",
    "-std=c11",
    "-Wall",
    "-Wextra",
    "-Wno-unused-variable",
    "-Wno-unused-parameter",
    "-Wno-unused-function",
    "-Wno-sign-compare",
    "-Wno-missing-braces",
    "-Wno-switch",
    "-g",
    "-O0",
    "src/compiler_build.c",

    "-o",
    "e1"
  );
  if(!nob_cmd_run_sync_and_reset(&cmd)) return 0;

  return 1;
}



int build_compiler_mac(void) {
  nob_log(NOB_INFO, "mac build");

  Nob_Cmd cmd = {0};

  nob_cmd_append(&cmd,
    "clang",
    "-std=c11",
    "-Wall",
    "-Wextra",
    "-Wno-unused-variable",
    "-Wno-unused-parameter",
    "-Wno-unused-function",
    "-Wno-sign-compare",
    "-Wno-missing-braces",
    "-Wno-switch",
    "-g",
    "-O0",
    "src/compiler_build.c",

    "-o",
    "e1"
  );
  if(!nob_cmd_run_sync_and_reset(&cmd)) return 0;

  return 1;
}

#if PLATFORM_LINUX

#define build_compiler build_compiler_linux

#elif PLATFORM_WINDOWS

#define build_compiler build_compiler_win32

#elif PLATFORM_MAC

#define build_compiler build_compiler_mac

#endif


// NOTE jfd: define the main project build function
#define build build_compiler



int main(int argc, char **argv) {
  NOB_GO_REBUILD_URSELF(argc, argv);


  if(argc == 1) {
    if(!build()) return 1;
    return 0;
  }

  if(!strcmp("compiler", argv[1])) {
    if(!build_compiler()) return 1;
  }

  return 0;
}

