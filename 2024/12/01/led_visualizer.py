import sys
import time

def visualize_leds(line):
    """Visualizes the LED states based on the given input line."""
    states = {'0': 'OFF', '1': 'ON'}
    try:
        # Extract the x, y, z values from the input line
        parts = line.strip().split(";")
        x = parts[0].split("=")[1].strip()
        y = parts[1].split("=")[1].strip()
        z = parts[2].split("=")[1].strip()
        
        # Print LED visualization
        print(f"LED X: {states[x]}\tLED Y: {states[y]}\tLED Z: {states[z]}")
        print("-" * 50)
    except (IndexError, ValueError) as e:
        print(f"Error processing line: {line.strip()}")

def main():
    """Main function to read input from a pipe."""
    print("Reading LED states from input...")
    try:
        while True:
            line = sys.stdin.readline()
            if not line:
                break
            visualize_leds(line)
            time.sleep(0.5)  # Add delay for visualization effect
    except KeyboardInterrupt:
        print("\nExiting LED visualization.")
        sys.exit(0)

if __name__ == "__main__":
    main()

