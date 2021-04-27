from PIL import Image
import serial
import numpy as np
from time import sleep

TOTAL = 4861
i = 0

Port = 'COM3'
BPS = 115200
ser = serial.Serial(Port, BPS, timeout=5)
while i < TOTAL:
    with Image.open("./8x/" + str(i) + ".jpg") as img:
        arr = np.asarray(img)
        #print("=====ARR=====")
        #print(arr)
        #print("=====BYTES=====")
        #for i in range(8):
        #    ser.write(arr[i].tobytes())
            #print(arr[i].tobytes())
        ser.write(arr.tobytes())
    print(i)
    sleep(1/15-0.001)
    i = i + 1

