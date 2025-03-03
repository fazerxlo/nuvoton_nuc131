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

# --- Main Build Script ---

env.Replace(
    LINKFLAGS=[
        "-mcpu=cortex-m0",
        "-specs=nano.specs",
        "-specs=nosys.specs",
        "-Wl,-Map=" + join("$BUILD_DIR", "${PROGNAME}.map"),
        "-Wl,--gc-sections",
        "-lnosys"
    ],
    CCFLAGS=[
        "-std=gnu11",
        "-Wall",
        "-march=armv6-m",
        "-D__NUC131__",
    ],
  CFLAGS = [

    ],
    CXXFLAGS=[
      "-std=gnu++11"
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
    "$PROJECT_DIR/bsp/CMSIS/Include",
    "$PROJECT_DIR/bsp/Device/NUC131/Include",
    "$PROJECT_DIR/bsp/StdDriver/inc"
    # Add *all* necessary include paths here
]
add_includes(env, bsp_include_paths)

# 2. Source Files
add_sources(env, join("$BUILD_DIR", "bsp", "Device", "NUC131"),
             join("$PROJECT_DIR", "bsp", "Device", "NUC131", "Source"))
add_sources(env, join("$BUILD_DIR", "bsp", "StdDriver"),
             join("$PROJECT_DIR", "bsp", "StdDriver", "src"))
add_sources(env, join("$BUILD_DIR", "bsp", "Device", "NUC131", "Startup"),
    join("$PROJECT_DIR", "bsp", "Device", "NUC131", "Source", "GCC")) #Adjust the folder accordingly
# Add startup files here if not already included

# 3. Preprocessor Definitions (if needed)
bsp_defines = [
    # Add BSP-specific defines here, if any
]
add_defines(env, bsp_defines)

# --- Build Program ---

target_elf = env.BuildProgram()