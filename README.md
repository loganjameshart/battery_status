# Battery Percentage Monitor

This is a C program that continuously monitors and displays the battery percentage on a Linux system. It reads battery information from specified files in the `/sys/class/power_supply/BAT1/` directory, calculates the battery percentage, and displays it in the terminal.

## Prerequisites

This program is intended for Linux systems with a battery that exposes charge information in the `/sys/class/power_supply/BAT1/` directory. You may need to adjust the paths if your system's battery information is located elsewhere.

## Usage

1. Compile the program:
   ```bash
   gcc battery.c -o battery
   ```

2. Run the program:
   ```bash
   ./battery
   ```

3. The program will continuously display the battery percentage in the format "Current battery: XX%" where "XX" is the calculated battery percentage. It updates the percentage every second.

4. To stop the program, press Ctrl+C.

## Customization

- If your battery information is located in a different directory, modify the `battery_charge_dir` and `battery_max_dir` constants in the code to match your system's configuration.

## License

This program is provided under the [MIT License](LICENSE).
