import cv2
import socket
import struct
import pickle
import sys
import signal


def signal_handler(xsignal, frame):
    if xsignal == signal.SIGINT:
        print("exit")
        sys.exit(0)
    elif xsignal == signal.SIGALRM:
        print("time out")
        sys.exit(0)


server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('0.0.0.0', 8888)
server_socket.bind(server_address)

server_socket.listen(1)

camera = cv2.VideoCapture(0)

while True:
    signal.signal(signal.SIGINT, signal_handler)
    signal.signal(signal.SIGALRM, signal_handler)

    print("waiting...")
    client_socket, client_address = server_socket.accept()

    try:
        print('bind from:', client_address)

        while True:
            ret, frame = camera.read()

            data = pickle.dumps(frame)

            try:
                client_socket.sendall(struct.pack("L", len(data)))
                print(len(data))
            except socket.error as e:
                print("output size error:", e)
                break

            client_socket.sendall(data)

            try:
                response = client_socket.recv(1024)
                if not response:
                    break
            except socket.error as e:
                print("response error:", e)
                break

            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
    finally:
        client_socket.close()

camera.release()
