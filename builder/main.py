from os.path import join

from SCons.Script import DefaultEnvironment, Import

Import("env")

# Access to global build environment
# print(env.Dump())

env.Replace(
    LINKFLAGS=[
        "-mcpu=cortex-m0",
        "-mthumb",
        "-specs=nano.specs",
        "-specs=nosys.specs",  # If you don't have newlib, use nosys
        "--specs=retarget.specs",
        "-lnosys"
    ],
      CCFLAGS=[
        "-std=gnu11",
        "-Wall",
        "-march=armv6-m"
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

#
# Target: Build executable and linkable firmware
#
target_elf = env.BuildProgram()