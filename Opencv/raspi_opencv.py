import cv2
import socket
import struct
import pickle
import time
import signal
import sys

def signal_handler(xsignal, frame):
    if xsignal == signal.SIGINT:
        print("exit")
        sys.exit(0)
    elif xsignal == signal.SIGALRM:
        print("time out")
        sys.exit(0)

# 创建一个TCP/IP套接字, 客户端套接字（client_socket）
# 套接字的地址族(AF_INET)为IPv4，套接字类型(SOCK_STREAM)为TCP类型
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 连接服务器
server_address = ('192.168.137.63', 8888)
client_socket.connect(server_address)

# 初始化OpenCV窗口, 窗口的大小调整为可调整的（cv2.WINDOW_NORMAL参数）
cv2.namedWindow("Video", cv2.WINDOW_NORMAL)

frame_rate = 10

try:
    while True:
        signal.signal(signal.SIGINT, signal_handler)
        #signal.signal(signal.SIGALRM, signal_handler)
        # 接收帧大小
        data = b''
        # "L" 是一个格式字符，代表无符号长整型（Unsigned Long）,struct.calcsize("L")四个字节长
        while len(data) < struct.calcsize("L"):
            packet = client_socket.recv(struct.calcsize("L"))
            if not packet:
                break
            data += packet

        frame_size = struct.unpack("L", data)[0]

        # 接收帧数据
        data = b''
        while len(data) < frame_size:
            packet = client_socket.recv(frame_size - len(data))
            if not packet:
                break
            data += packet

        # 解码帧数据
        frame = pickle.loads(data)

        # 在OpenCV窗口中显示视频
        cv2.imshow("Video", frame)

        # 按下'q'键退出
        #if cv2.waitKey(1) & 0xFF == ord('q'):
            #break

        time.sleep(1/frame_rate)

finally:
    # 关闭连接
    client_socket.close()

# 关闭OpenCV窗口
cv2.destroyAllWindows()
