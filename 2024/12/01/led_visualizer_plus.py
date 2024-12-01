import sys
import time
from colorama import init, Fore, Back, Style

# Initialize colorama
init()

def visualize_leds(line):
    """Visualizes the LED states as colored symbols based on the input line."""
    # LED representation using colored circles
    led_symbols = {
        '0': Fore.RED + '●' + Style.RESET_ALL,  # OFF: Red Circle
        '1': Fore.GREEN + '●' + Style.RESET_ALL  # ON: Green Circle
    }

    try:
        # Extract x, y, z values
        parts = line.strip().split(";")
        if len(parts) < 3:
            raise ValueError("Malformed line")
        x = parts[0].split("=")[1].strip()
        y = parts[1].split("=")[1].strip()
        z = parts[2].split("=")[1].strip()

        # Print the "LEDs"
        # print("\n" + "=" * 50)
        print(f"LED X: {led_symbols.get(x, ' ')}   "
              f"LED Y: {led_symbols.get(y, ' ')}   "
              f"LED Z: {led_symbols.get(z, ' ')}")
        print("=" * 50)
    except (IndexError, ValueError) as e:
        print(f"Error processing line: {line.strip()} - {e}")

def main():
    """Main function to read input from a pipe."""
    print("Reading LED states from input...")
    try:
        while True:
            line = sys.stdin.readline()
            if not line:
                break
            visualize_leds(line)
            time.sleep(0.5)  # Add delay for visualization
    except KeyboardInterrupt:
        print("\nExiting LED visualization.")
        sys.exit(0)

if __name__ == "__main__":
    main()

