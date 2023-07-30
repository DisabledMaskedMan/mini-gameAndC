import sensor, image, time, gif, pyb, utime

RED_LED_PIN = 1
BLUE_LED_PIN = 3

sensor.reset() # 初始化sensor

sensor.set_pixformat(sensor.RGB565) # or sensor.GRAYSCALE
#设置图像色彩格式，有RGB565色彩图和GRAYSCALE灰度图两种

sensor.set_framesize(sensor.QQVGA) # or sensor.QVGA (or others)
#设置图像像素大小

sensor.skip_frames(time = 2000) # 让新的设置生效
clock = time.clock() # 跟踪FPS帧率

pyb.LED(RED_LED_PIN).on()
sensor.skip_frames(30) # Give the user time to get ready.
#程序开始时，先等待30帧图像，让用户有时间准备

pyb.LED(RED_LED_PIN).off()
pyb.LED(BLUE_LED_PIN).on()

g = gif.Gif("example.gif", loop=True)
#gif.Gif(filename, width=Auto, height=Auto, color=Auto, loop=True)创建一个gif对象，filename为保存gif动图的文件路径

print("You're on camera!")
for i in range(100):
    clock.tick()
    # clock.avg()返回帧与帧之间的毫秒数，其中包含gif延迟
    g.add_frame(sensor.snapshot(), delay=10) # centiseconds.
    #gif.add_frame(image, delay=10),向gif动图中添加图片，delay＝10指每隔
    #10分秒添加一张图。
    print(clock.fps())

g.close()
pyb.LED(BLUE_LED_PIN).off()
print("Done! Reset the camera to see the saved recording.")
