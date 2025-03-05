import os
import shutil
from os.path import join
from SCons.Script import *

env = DefaultEnvironment()

# --- Helper Functions ---

def add_includes(env, include_paths):
    """Adds include paths to the environment."""
    for path in include_paths:
        env.Append(CPPPATH=[path])

def add_sources(env, build_dir, src_dir):
    """Adds source files to the build."""
    env.BuildSources(build_dir, src_dir)

def add_defines(env, defines):
    """Adds preprocessor definitions to the environment."""
    for define in defines:
        env.Append(CPPDEFINES=[define])

# --- Copy BSP Directory (NEW FUNCTION) ---

def copy_bsp(env):
    """Copies the BSP directory to the build directory."""
    platform_dir = env.PioPlatform().get_dir() # Get platform dir
    bsp_src_dir = os.path.join(platform_dir, "bsp")
    build_dir = env.get("PROJECT_BUILD_DIR")
    pioenvv = env.get("PIOENV")
    print(env.get("PIOENV"))
    bsp_dest_dir = os.path.join(build_dir, "bsp")

    if os.path.exists(bsp_src_dir):
        if os.path.exists(bsp_dest_dir):
            shutil.rmtree(bsp_dest_dir)  # Clean previous copy
        shutil.copytree(bsp_src_dir, bsp_dest_dir)
        print(f"Copied 'bsp' directory to {bsp_dest_dir}")
    else:
        print(f"Warning: 'bsp' directory not found in {bsp_src_dir}")

# --- Main Build Script ---

# Call the function to copy the BSP
copy_bsp(env)

env.Replace(
    AR="arm-none-eabi-gcc-ar",
    AS="arm-none-eabi-as",
    CC="arm-none-eabi-gcc",
    CXX="arm-none-eabi-g++",
    GDB="arm-none-eabi-gdb",
    OBJCOPY="arm-none-eabi-objcopy",
    RANLIB="arm-none-eabi-gcc-ranlib",
    SIZETOOL="arm-none-eabi-size",
)


# arm-none-eabi-gcc
# -o .pio/build/nuvoton_nuc131/src/main.o
# -c -std=gnu11
# -Wall
# -march=armv6-m 
# -D__NUC131__ 
# -DPLATFORMIO=60117 
# -D__NUC131__ 
# -Iinclude 
# -Isrc 
# -Ibsp/CMSIS/Include 
# -Ibsp/Device/NUC131/Include 
# -Ibsp/StdDriver/inc src/main.c

env.Replace(
    CCFLAGS=[
        "-std=gnu11",
        "-Wall",
        "-march=armv6-m",
        "-D__NUC131__",
        "-Wl,--verbose"
    ],
    LINKFLAGS=[
        "-mcpu=cortex-m0",
        "-specs=nano.specs",
        "-specs=nosys.specs",
        "-Wl,-Map=" + join("$BUILD_DIR", "${PROGNAME}.map"),
        "-Wl,--gc-sections",
        "-lnosys"
    ],
    CFLAGS = [

    ],
    CXXFLAGS=[
      "-std=gnu++14"
    ]
)

env.Append(

    LIBS=[
      "stdc++",
      "supc++",
      "c",
      "gcc"
    ]
)

# --- BSP Integration ---

# 1. Include Paths
bsp_include_paths = [
    join("$PROJECT_BUILD_DIR", "bsp", "CMSIS", "Include"),     # Use $BUILD_DIR
    join("$PROJECT_BUILD_DIR", "bsp", "Device", "NUC131", "Include"),  # Use $BUILD_DIR
    join("$PROJECT_BUILD_DIR", "bsp", "StdDriver", "inc")   # Use $BUILD_DIR
]
add_includes(env, bsp_include_paths)

# 2. Source Files
add_sources(env, join("$BUILD_DIR", "bsp", "Device", "NUC131"),
             join("$BUILD_DIR", "bsp", "Device", "NUC131", "Source")) # Use $BUILD_DIR
add_sources(env, join("$BUILD_DIR", "bsp", "StdDriver"),
             join("$BUILD_DIR", "bsp", "StdDriver", "src")) # Use $BUILD_DIR
add_sources(env, join("$BUILD_DIR", "bsp", "Device", "NUC131", "Startup"),
    join("$BUILD_DIR", "bsp", "Device", "NUC131", "Source", "GCC")) # Use $BUILD_DIR
# Add startup files here if not already included

# 3. Preprocessor Definitions (if needed)
bsp_defines = [
    # Add BSP-specific defines here, if any
]
add_defines(env, bsp_defines)

# --- Build Program ---

target_elf = env.BuildProgram()