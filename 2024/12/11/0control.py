import socket

def send_command(ip, port, command):
    try:
        # 创建一个 TCP socket
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            print(f"连接到 {ip}:{port}...")
            # 连接到服务器
            s.connect((ip, port))

            # 发送命令
            print(f"发送命令: {command}")
            s.sendall(command.encode('utf-8'))

            # 接收响应
            response = s.recv(1024)  # 假设响应不会超过 1024 字节
            print(f"收到响应: {response.decode('utf-8')}")

    except Exception as e:
        print(f"发生错误: {e}")

if __name__ == "__main__":
    # 配置目标 IP 和端口
    target_ip = "192.168.1.1"
    target_port = 2001

    # 要发送的命令
    command = "ONB"

    # 调用函数发送命令
    send_command(target_ip, target_port, command)
