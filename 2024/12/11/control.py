import socket
import sys

def send_command(ip, port, command):
    try:
        # create a TCP socket
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            print(f"connecting {ip}:{port}...")
            # connect to server
            s.connect((ip, port))

            # send command
            print(f"send: {command}")
            s.sendall(command.encode('utf-8'))

#           # get response
#           response = s.recv(1024)
#           print(f"response: {response.decode('utf-8')}")

    except Exception as e:
        print(f"\033[3;32merror!\033[0m: {e}")

if __name__ == "__main__":
    # configuration
    target_ip = "192.168.1.1"
    target_port = 2001

    # map
    command_map = {
        "left": "ONC",
        "right": "OND",
        "forward": "ONA",
        "back": "ONB",
        "stop": "ONF",
        "videoLeft": "ONLONF",
        "videoRight": "ONIONF",
        "videoUp": "ONKONF",
        "videoDown": "ONJONF"
    }

    # check argument and help
    if len(sys.argv) != 2:
        print("usage: python script.py <command>")
        print("help: left, right, forward, back, stop")
        sys.exit(1)

    # get argument
    input_command = sys.argv[1]
    if input_command not in command_map:
        print(f"unknown command: {input_command}")
        print("command: left, right, forward, back, stop")
        sys.exit(1)

    # mapping argument and signal
    command = command_map[input_command]

    # send signal by tcp
    send_command(target_ip, target_port, command)

