from os.path import join

from SCons.Script import DefaultEnvironment, Import, Builder

Import("env")

# Access to global build environment
# print(env.Dump())

env.Replace(
    LINKFLAGS=[
        "-mcpu=cortex-m0",
        "-mthumb",
        "-specs=nano.specs",
        "-specs=nosys.specs",  # Or retarget.specs if you have retargeting
        "--specs=retarget.specs",
        "-lnosys"
    ],
    CCFLAGS=[
        "-std=gnu11",
        "-Wall",
        "-march=armv6-m",
        "-D__NUC131__" # Ensure this is defined here as well
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
    ],
    CPPPATH=[  # Add include paths for the BSP
        "$PROJECT_DIR/bsp/CMSIS/Include",
        "$PROJECT_DIR/bsp/Device/NUC131/Include",
        "$PROJECT_DIR/bsp/StdDriver/inc"
    ],
    # Assuming source files are directly under these directories:
    CPPDEFINES=[
    ]

)
# Add source files from the BSP to the build
env.BuildSources(
    join("$BUILD_DIR", "bsp", "Device", "NUC131"),
    join("$PROJECT_DIR","bsp", "Device", "NUC131", "Source"),
)

env.BuildSources(
    join("$BUILD_DIR", "bsp", "StdDriver"),
    join("$PROJECT_DIR","bsp", "StdDriver", "src"),
)
#
# Target: Build executable and linkable firmware
#
target_elf = env.BuildProgram()