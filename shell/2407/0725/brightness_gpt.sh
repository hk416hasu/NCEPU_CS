#!/bin/env bash

# Function to detect the backlight device
detect_backlight_device() {
    local devices
    devices=($(ls /sys/class/backlight))
    if [ ${#devices[@]} -eq 1 ]; then
        echo "/sys/class/backlight/${devices[0]}"
    else
        echo "Multiple or no backlight devices found." >&2
        exit 1
    fi
}

BACKLIGHT_PATH=$(detect_backlight_device)
MAX_BRIGHTNESS=$(cat "$BACKLIGHT_PATH/max_brightness")
BRIGHTNESS_PATH="$BACKLIGHT_PATH/brightness"

usage() {
    echo "Usage: brightness [OPTION]..."
    echo "Change the brightness of your computer"
    echo ""
    echo "  -s, --set INT        set brightness at INT"
    echo "  -p, --percent INT    set brightness as a percentage"
    echo "  -m, --max            get the max brightness value"
    echo "  -h, --help           show help"
    echo "  -c, --current        show current brightness value"
    echo ""
    echo "Only when brightness is really changed, then return 0"
    exit 1
}

if [ $# -eq 0 ]; then
    usage
fi

while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            usage
            ;;
        -m|--max)
            echo "The max brightness value is: $MAX_BRIGHTNESS"
            exit 0
            ;;
        -c|--current)
            echo -n "The current brightness value is: "
            cat "$BRIGHTNESS_PATH"
            exit 0
            ;;
        -s|--set)
            if [ -n "$2" ] && [ "$2" -ge 0 ] 2>/dev/null; then
                BRIGHTNESS=$(( $2 > MAX_BRIGHTNESS ? MAX_BRIGHTNESS : $2 ))
                echo $BRIGHTNESS | sudo tee "$BRIGHTNESS_PATH"
                echo "Brightness set to $BRIGHTNESS"
                shift
            else
                echo "Invalid brightness value: $2" >&2
                usage
            fi
            ;;
        -p|--percent)
            if [ -n "$2" ] && [ "$2" -ge 0 ] && [ "$2" -le 100 ] 2>/dev/null; then
                BRIGHTNESS=$(( MAX_BRIGHTNESS * $2 / 100 ))
                echo $BRIGHTNESS | sudo tee "$BRIGHTNESS_PATH"
                echo "Brightness set to $BRIGHTNESS ($2%)"
                shift
            else
                echo "Invalid percentage value: $2" >&2
                usage
            fi
            ;;
        *)
            echo "Unknown option: $1" >&2
            usage
            ;;
    esac
    shift
done

exit 0
