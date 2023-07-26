import sensor, image, time, math, utime

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA) # we run out of memory if the resolution is much bigger...
sensor.skip_frames(30)
sensor.set_auto_gain(False)  # must turn this off to prevent image washout...
sensor.set_auto_whitebal(False)  # must turn this off to prevent image washout...
clock = time.clock()

def degree(rotation):
    return rotation*180/math.pi

#def Change_Position(*args):
#    out = [0, 0, 0]
#    if isinstance(args[0], list):
#        if (len(args[0]) == 6):
#            x_theta = 180-args[0][3]
#            y_theta = args[0][4]
#            z_theta = 360-args[0][5]
#
#            arr = [[math.cos(y_theta)*math.cos(z_theta), math.sin(x_theta)*math.sin(y_theta)*math.cos(z_theta)-math.cos(x_theta)*math.sin(z_theta), math.cos(x_theta)*math.sin(y_theta)*math.cos(z_theta)+math.sin(x_theta)*math.sin(z_theta)],
#                   [math.cos(y_theta)*math.sin(z_theta), math.sin(x_theta)*math.sin(y_theta)*math.sin(z_theta)+math.cos(x_theta)*math.cos(z_theta), math.cos(x_theta)*math.sin(y_theta)*math.sin(z_theta)-math.sin(x_theta)*math.cos(z_theta)],
#                   [-math.sin(y_theta), math.sin(x_theta)*math.cos(y_theta), math.cos(x_theta)*math.cos(y_theta)]]
#
#            for i in range(3):
#                for j in range(3):
#                    out[i] += arr[i][j]*args[0][j]
#    return out


while(True):
    clock.tick()
    img = sensor.snapshot().lens_corr(1.8)

    for tag in img.find_apriltags(families=image.TAG16H5): # defaults to TAG36H11 without "families".
        img.draw_rectangle(tag.rect(), color = (255, 0, 0))
        img.draw_cross(tag.cx(), tag.cy(), color = (0, 255, 0))
        t_x = tag.x_translation()*4.4
        t_y = tag.y_translation()*5
        t_z = tag.z_translation()*6.5
        print(tag.family(),tag.id())
        print(degree(tag.x_rotation()), degree(tag.y_rotation()), degree(tag.z_rotation()))
        print(t_x, t_y, t_z)
        print(t_z*math.cos(180-degree(tag.x_rotation())))
        img.draw_rectangle(tag.rect())
        #tmp = Change_Position([t_x, t_y, t_z, degree(tag.x_rotation()), degree(tag.y_rotation()), degree(tag.z_rotation())])
        #if tmp[0] != tmp[1]:
            #print("x:%f y:%f z:%f" %(tmp[0], tmp[1], tmp[2]))

    img.draw_cross(80, 60, color=(255,0,0), size=5)


#Kx=4.4，Ky=5.0，Kz=6.5，单位为cm
#旋转Z轴,X,Y,Z轴的测量结果不变换
