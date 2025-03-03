import os
from platformio.public import PlatformBase
from platformio.util import get_systype
class NuvotonPlatform(PlatformBase):

    def configure_default_packages(self, variables, targets):
        # Get the system type
        system_type = get_systype()

        # --- Dynamically Find the Toolchain ---
        toolchain_path = self.get_package_dir("toolchain-gccarmnoneeabi")
        if not toolchain_path:
            raise Exception("Could not find toolchain-gccarmnoneeabi package!")

        # Construct the full path to the compiler executable
        if "windows" in system_type:
            compiler_prefix = os.path.join(toolchain_path, "bin", "arm-none-eabi-")
            cc_path = compiler_prefix + "gcc.exe"
            cxx_path = compiler_prefix + "g++.exe"
            as_path = compiler_prefix + "as.exe"
            ar_path = compiler_prefix + "ar.exe"
            link_path = compiler_prefix + "gcc.exe"  # Or ld.exe
        else:
            compiler_prefix = os.path.join(toolchain_path, "bin", "arm-none-eabi-")
            cc_path = compiler_prefix + "gcc"
            cxx_path = compiler_prefix + "g++"
            as_path = compiler_prefix + "as"
            ar_path = compiler_prefix + "ar"
            link_path = compiler_prefix + "gcc"  # Or ld

        # --- Override Compiler Settings ---
        self.env.Replace(
            CC=cc_path,
            CXX=cxx_path,
            AS=as_path,
            AR=ar_path,
            LINK=link_path
        )

        return super().configure_default_packages(variables, targets)
    def get_boards(self, id_=None):
        result = super().get_boards(id_)
        if not result:
            return result
        if id_:
            return self._add_default_debug_tools(result)
        else:
            for key, value in result.items():
                result[key] = self._add_default_debug_tools(value)
        return result