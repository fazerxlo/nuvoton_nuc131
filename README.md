# PlatformIO Platform for Nuvoton NUC131 Series Microcontrollers

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

This project provides a custom PlatformIO platform for developing on Nuvoton NUC131 series microcontrollers, specifically targeting the NUC131xE3AE. It allows you to leverage the PlatformIO ecosystem (IDE integration, build system, library manager) for bare-metal/BSP-based development, without relying on a higher-level framework like Mbed.

**Note:** This project is currently under development. The build system is functional, but a custom uploader package (`tool-nuvoton-isp`) is **required** for flashing firmware to the target device.  Instructions for creating this package are provided below.

## Features

*   **PlatformIO Integration:** Seamlessly integrates with the PlatformIO IDE and build system.
*   **Nuvoton NUC131BSP:** Includes the necessary header files and source files from the Nuvoton NUC131 Board Support Package (BSP) for direct hardware access.
*   **Bare-metal Development:** Designed for bare-metal programming, giving you fine-grained control over the microcontroller.
*   **Map File Generation:** Generates a linker map file (`.map`) for memory usage analysis and debugging.
*   **Garbage Collection:** Uses linker flags (`--gc-sections`) to remove unused code and minimize firmware size.
*   **Example Project:** Includes a basic "blink" example to demonstrate the platform's functionality.

## Project Structure

```
nuvoton/
├── boards/
│   └── nuvoton_nuc131.json  <- Board definition (NUC131xE3AE)
├── bsp/                      <- Nuvoton NUC131 BSP files
│   ├── CMSIS/              <- CMSIS core files
│   │   └── Include/
│   │       └── ...
│   ├── Device/             <- Nuvoton device-specific files
│   │   └── NUC131/
│   │       └── Include/
│   │           └── ...
│   │       └── Source/     <- Startup code and system files
│   │           └── GCC/    <- startup files
│   │           └── ...
│   └── StdDriver/         <- Nuvoton Standard Driver files
│       └── inc/
│           └── ...
│       └── src/
│           └── ...
├── builder/
│   └── main.py             <- PlatformIO build script
├── examples/
│   └── blink/              <- Example "blink" project
│       └── src/
│           └── main.c
├── platform.json           <- Platform manifest
└── platform_nuvoton.py     <- Platform class
```

## Prerequisites

*   **PlatformIO:**  Install PlatformIO Core or the PlatformIO IDE.
*   **Nuvoton NUC131BSP:**  The BSP files are included in this repository within the `bsp` directory. You should *not* need to download them separately.  If you need a different version of the BSP, you can obtain it from the official Nuvoton website (see Referenced Materials).
*   **ARM GCC Toolchain:**  The platform uses the `toolchain-gccarmnoneeabi` package, which PlatformIO will automatically download and manage.
*   **Nuvoton ISP Tool (or OpenOCD):**  You will need a way to flash your compiled firmware onto the NUC131.  This project is designed to work with a custom uploader package (`tool-nuvoton-isp`).  See the "Uploader Package" section below for detailed instructions.

## Usage

1.  **Clone this Repository:**

    ```bash
    git clone https://github.com/fazerxlo/nuvoton_nuc131.git
    ```

2.  **Place the `nuvoton` directory:** Copy the entire `nuvoton` directory into your PlatformIO platforms directory.  The location of this directory depends on your operating system and PlatformIO installation:
    *   **Linux/macOS:**  `~/.platformio/platforms/`
    *   **Windows:**  `%USERPROFILE%\.platformio\platforms\`
     Alternatively, for development purposes, you can keep the nuvoton folder, where it is, and change platform = path/to/nuvoton in platformio.ini in the examples.

3.  **Create a New PlatformIO Project:**  In the PlatformIO IDE or using the PlatformIO CLI, create a new project.

4.  **Configure `platformio.ini`:**  In your project's `platformio.ini` file, set the following:

    ```ini
    [env:nuvoton_nuc131]
    platform = nuvoton  ; Or path/to/nuvoton if you placed the directory to another location
    board = nuvoton_nuc131
    ; No framework is explicitly specified for bare-metal development
    ; Optional: upload_port = COM3  ; Replace COM3 with your device's port
    ; Add other upload-related options here as needed by your uploader
    ```

5.  **Write Your Code:**  Create your application code in the `src` directory of your project.  You can use the provided `examples/blink` project as a starting point.  Include the necessary Nuvoton header files (e.g., `NUC131.h`) to access peripherals and registers.

6.  **Build the Project:**  Use PlatformIO's "Build" command (either in the IDE or via the CLI) to compile your project.

7.  **Upload the Firmware (Requires `tool-nuvoton-isp`):**  Once the build is successful, you need to use your custom uploader package to flash the firmware onto the NUC131. See "Uploader Package". Use PlatformIO's "Upload" command.

## Uploader Package (`tool-nuvoton-isp`) - *CRITICAL*

This platform requires a custom uploader package named `tool-nuvoton-isp`.  This package is **not** included in this repository and must be created separately. This package is responsible for taking the compiled binary (usually a `.bin` or `.hex` file) and flashing it to the NUC131 microcontroller.

**Recommended Approach: Nuvoton's ISP Tool**

The recommended approach is to create a wrapper around Nuvoton's official ISP (In-System Programming) tool. This tool is typically a command-line utility provided by Nuvoton.

**Steps to Create `tool-nuvoton-isp`:**

1.  **Create a Separate Repository:** Create a new Git repository (e.g., `tool-nuvoton-isp`) for your uploader package.  This keeps it separate from the platform itself.

2.  **Create `package.json`:**  Inside the repository, create a `package.json` file that describes your uploader.  Here's an example:

    ```json
    {
      "name": "tool-nuvoton-isp",
      "version": "1.0.0",
      "description": "Uploader for Nuvoton NUC131 microcontrollers using Nuvoton's ISP tool",
      "keywords": [
        "platformio",
        "platformio-tool",
        "nuvoton",
        "nuc131",
        "isp",
        "uploader"
      ],
      "homepage": "https://github.com/your-username/tool-nuvoton-isp",  ,
      "license": "Apache-2.0",
      "system": [
        "*"
      ],
      "script": {
          "upload": "python upload.py"
      }
    }
    ```
     *  **`name`:**  Must be `tool-nuvoton-isp`.
    *   **`version`:**  The version of your uploader package.
    *   **`description`:** A brief description.
    *   **`system`**: `*` means all systems are supported
    *   **`script.upload`:** This is *crucial*.  It tells PlatformIO to execute `python upload.py` when you run the "Upload" command.

3.  **Create `upload.py`:**  This Python script is the heart of your uploader.  It will be executed by PlatformIO and must handle the following:

    *   **Receive Firmware Path:** Get the path to the compiled firmware file (usually a `.bin` or `.hex`) from PlatformIO.
    *   **Get Upload Settings:** (Optionally) Get upload settings (like COM port, baud rate) from `platformio.ini`.
    *   **Call Nuvoton's ISP Tool:** Execute Nuvoton's ISP tool (likely a command-line utility) with the correct arguments to flash the firmware to the NUC131.  You'll need to handle things like:
        *   Specifying the correct COM port (or using an auto-detect mechanism).
        *   Setting the baud rate (if required).
        *   Providing the path to the firmware file.
        *   Handling any other options required by the ISP tool.
    *   **Provide Feedback:** Print informative messages to the console (success/failure).  PlatformIO will display these messages to the user.

    Here's a *conceptual* example of `upload.py` (you'll need to adapt it to Nuvoton's specific ISP tool):

    ```python
    import subprocess
    import sys
    from os.path import join

    from SCons.Script import Import

    Import("env")

    def upload(source, target, env):
        """Uploads the firmware to the NUC131."""

        # --- Get the path to the compiled firmware ---
        firmware_path = str(source[0])

        # --- Get upload settings from platformio.ini (optional) ---
        upload_port = env.GetProjectOption("upload_port", None)
        # Add other options like upload_speed, etc., if needed

        # --- Construct the command for Nuvoton's ISP tool ---
        command = [
            "path/to/nuvoton/isp/tool.exe",  # Replace with the actual path!
            "-port=" + (upload_port or "AUTO"),
            "-file=" + firmware_path,
            # Add other necessary arguments
        ]
    	print (command)

        # --- Execute the command ---
        try:
            result = subprocess.run(command, check=True, capture_output=True, text=True)
            print(result.stdout)
            if result.returncode == 0:
                print("Upload successful!")
            else:
                print("Upload failed!", file=sys.stderr)
                print(result.stderr, file=sys.stderr)
                sys.exit(1)

        except FileNotFoundError:
            print("Error: Nuvoton ISP tool not found.", file=sys.stderr)
            sys.exit(1)
        except subprocess.CalledProcessError as e:
            print(f"Error during upload: {e}", file=sys.stderr)
            print(e.output, file=sys.stderr)
            sys.exit(1)

    # --- Register the upload function ---
    env.AddPlatformTarget(
        "upload",
        target,
        [upload],
        "Upload",
        "Upload firmware to Nuvoton NUC131"
    )
    ```

4.  **Include the ISP Tool (Optional):** If the license of Nuvoton's ISP tool allows redistribution, you can include the tool's executable files directly within your `tool-nuvoton-isp` repository.  If not, your `upload.py` script might need to prompt the user to download the tool separately and place it in a specific location.

5.  **Test Thoroughly:** Test the upload process extensively to ensure it works reliably.

6. **Place tool-nuvoton-isp to** Place the `tool-nuvoton-isp` directory into your PlatformIO packages directory.  The location of this directory depends on your operating system and PlatformIO installation:
    *   **Linux/macOS:**  `~/.platformio/packages/`
    *   **Windows:**  `%USERPROFILE%\.platformio\packages\`

**Alternative: OpenOCD**

It's *possible* to use OpenOCD (Open On-Chip Debugger) to program the NUC131. However, this typically requires more configuration and is generally more complex than using the manufacturer's provided tools. If you choose to use OpenOCD, you'll need to:

*   Install OpenOCD.
*   Find or create OpenOCD configuration files (`.cfg`) for the NUC131 and your debugging adapter (e.g., ST-Link).
*   Modify the `upload.py` script to call OpenOCD instead of Nuvoton's ISP tool.

## Referenced Materials

*   **PlatformIO Documentation:**
    *   [Creating Custom Platforms](https://docs.platformio.org/en/latest/platforms/creating_platform.html)
    *   [PlatformIO Packages](https://docs.platformio.org/en/latest/core/userguide/pkg/index.html)
*   **Nuvoton Resources:**
    *   [NUC131 Series Page](https://www.nuvoton.com/products/microcontrollers/arm-cortex-m0-mcus/nuc131-series/)
    *   [NUC131BSP (GitHub)](https://github.com/OpenNuvoton/NUC131BSP) - *Note:* The BSP is already included in this repository, but you can refer to the official repository for updates or different versions.
* **Related projects**
	*	[Peugeot 407 CAN bus research](https://github.com/fazerxlo/Peuget-407-canbox)
* **Examples and discussions**
	* [Example PlatformIO Platform for Nuvoton](https://github.com/Community-PIO-CHIPS/platform-nuvoton)
	* [PlatformIO Community Discussion](https://community.platformio.org/t/nuvoton-cortex-m-arm-cpu-infrastructure-support/36164)

## Project Motivation and Acknowledgements

This project was created to support development efforts for the [Peugeot 407 CAN bus research project](https://github.com/fazerxlo/Peuget-407-canbox). It aims to provide a streamlined and convenient development environment for working with the Nuvoton NUC131 microcontroller within the PlatformIO ecosystem.

This project was created with the assistance of an AI language model (Bard/Gemini by Google). The AI provided guidance on the structure, configuration files, and build script, based on the provided documentation, examples, and best practices. The AI also helped in analyzing existing code and suggesting improvements.

## License

This project is licensed under the Apache License 2.0. See the `LICENSE` file for details.

