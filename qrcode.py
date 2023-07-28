import sensor, image, lcd

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.VGA) # can be QVGA on M7...
sensor.set_windowing((640, 80))
sensor.run(1)
sensor.skip_frames(30)
sensor.set_auto_gain(False) # must turn this off to prevent image washout...
sensor.set_hmirror(0)
lcd.init()

while(True):
    img = sensor.snapshot()
    lcd.display(img)
    img.lens_corr(1.8) # strength of 1.8 is good for the 2.8mm lens.
    code = img.find_qrcodes()
    if len(code) > 0:
        print(code[0].payload())
