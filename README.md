# nuvoton_nuc131
Custom PlatformIO platform for Nuvoton NUC131 series microcontrollers.
## Installation

1.  Install PlatformIO Core (if you don't have it already):

    ```bash
    python3 -m pip install --upgrade platformio
    ```

2.  Install this platform:

    ```bash
    pio platform install /home/Fazer/git/nuvoton_nuc131
    ```

## Usage

1.  Create a new PlatformIO project.
2.  In your `platformio.ini` file, set the `platform` to `nuvoton_nuc131` and the `board` to your specific NUC131 variant (e.g., `nuc131ld2ae`).

    ```ini
    [env:nuc131ld2ae]
    platform = nuvoton_nuc131
    board = nuc131ld2ae
    framework = mbed
    ```

3.  Start coding!

## Supported Boards

*   NUC131LD2AE
*   NUC131LC2AE
*   NUC131LE3AN
*   NUC131SC2AE
*   NUC131SD2AE
*   NUC131SE3AN

## Supported Frameworks

*   mbed

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues.

