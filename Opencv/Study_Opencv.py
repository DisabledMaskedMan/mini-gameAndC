import cv2
import matplotlib.pyplot as plt
import numpy as np

def cv_show(name, img):
    cv2.imshow(name, img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

'''
img = cv2.imread("C:\\Users\\ZZY\\Desktop\\1.jpg")
# img = cv2.imread("C:\\Users\\ZZY\\Desktop\\4.jpg", cv2.IMREAD_GRAYSCALE)
# img = cv2.medianBlur(img, 3)
# cv2.imshow("img", img)
'''



'''
cv2.imshow("img", img)
cv2.waitKey(0)
cv2.destroyAllWindows()

print(img.shape)
print(img.dtype)
print(img.size)
print(type(img))

------------------------------------------------------------------------------------------------------------------------

b, g, r = cv2.split(img)
print(b)
print(g)
print(r)

img = cv2.merge((b, g, r))
# hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow("gray", gray)
cv2.waitKey(0)
cv2.destroyAllWindows()

------------------------------------------------------------------------------------------------------------------------

tmp = img.copy()
tmp[:, :, 0] = 0
tmp[:, :, 1] = 0
cv2.imshow("tmp", tmp)
cv2.waitKey(0)
cv2.destroyAllWindows()

------------------------------------------------------------------------------------------------------------------------

img = img[50:150, 50:150]
cv2.imshow("img", img)
print(img.shape)
cv2.waitKey(0)
cv2.destroyAllWindows()

------------------------------------------------------------------------------------------------------------------------

top_size, bottom_size, left_size, right_size = (50, 50, 50, 50)
# BORDER_CONSTANT 常量法 常量值填充
# BORDER_WRAP 外包装法 cdefgh|abcdefgh|abcdef
# BORDER_REFLECT_101 反射法，也就是以最边缘的像素为轴，对称，hgfedcb|abcdefgh|gfedcba
# BORDER_REFLECT 反射法，对感兴趣的图像中的像素在两边进行复制，例如：hgfedcba|abcdefgh|hgfedcba
# BORDER_REPLICATE 复制法，也就是赋值最边缘的像素
result1 = cv2.copyMakeBorder(img, top_size, bottom_size, left_size, right_size, cv2.BORDER_CONSTANT, 0)
result2 = cv2.copyMakeBorder(img, top_size, bottom_size, left_size, right_size, cv2.BORDER_WRAP)
result3 = cv2.copyMakeBorder(img, top_size, bottom_size, left_size, right_size, cv2.BORDER_REFLECT_101)
result4 = cv2.copyMakeBorder(img, top_size, bottom_size, left_size, right_size, cv2.BORDER_REFLECT)
result5 = cv2.copyMakeBorder(img, top_size, bottom_size, left_size, right_size, cv2.BORDER_REPLICATE)

result = [result1, result2, result3, result4, result5]

for i in range(5):
    cv2.imshow("result"+str(i), result[i])
    cv2.waitKey(5000)
    cv2.destroyAllWindows()

# plt.subplot(2, 3, 1)表示将绘图区域分为2行3列，并将当前子图设置为第1个位置,该函数没有返回值，它会直接创建一个绘图区域和子图
# 可以使用plt.figure(figsize=(width, height))来设置绘图区域的大小。通过调整width和height参数的值，可以控制子图的比例和大小。
# width和height的单位是英寸（inch），默认值为6.4和4.8。

# plt.imshow(img, 'gray')
# plt.imshow()函数用于在matplotlib中显示图像。
# X：要显示的图像数据，可以是二维数组（灰度图像）或三维数组（彩色图像）。对于彩色图像，数组的形状应为(高度，宽度，通道数)，其中通道数为3（红、绿、蓝）或4（红、绿、蓝、透明度）。
# cmap（可选）：用于指定颜色映射的参数，用来表示如何将图像的像素值映射到颜色空间。常用的颜色映射有 “gray”（灰度图像，默认值）、“viridis”、“jet”、“hot” 等。
# interpolation（可选）：用于指定图像插值方式的参数，用来控制如何在图像的像素之间进行插值。常用的插值方式有 “nearest”（最近邻插值，默认值）、“bilinear”、“bicubic” 等。
# aspect（可选）：用于指定图像的长宽比的参数，可以是字符串 “equal”（等比例缩放）、浮点数（高度与宽度的比例）等。
# 没有显式的返回值，它直接在当前的轴（Axes）对象上显示图像

# plt.title()函数用于设置图像的标题
# plt.axis('off')用于关闭坐标轴的显示。

plt.subplot(2, 3, 1), plt.imshow(img, 'gray'), plt.title('ORIGINAL')
plt.subplot(2, 3, 2), plt.imshow(result1, 'gray'), plt.title('BORDER_CONSTANT')
plt.subplot(2, 3, 3), plt.imshow(result2, 'gray'), plt.title('BORDER_WRAP')
plt.subplot(2, 3, 4), plt.imshow(result3, 'gray'), plt.title('BORDER_REFLECT_101')
plt.subplot(2, 3, 5), plt.imshow(result4, 'gray'), plt.title('BORDER_REFLECT')
plt.subplot(2, 3, 6), plt.imshow(result5, 'gray'), plt.title('BORDER_REPLICATE')
# plt.show()函数是matplotlib库中用于显示所有已创建的图形，包括子图、坐标轴、图例等。它会打开一个图形窗口并显示在其中创建的所有图形,通常放在绘图代码的最后一行，以确保所有图形都已创建并可以显示。
plt.show()

------------------------------------------------------------------------------------------------------------------------
xlabel(),ylabel()参数
ticks：一个数组或列表，指定要显示在x轴上的刻度值的位置。
labels：一个数组或列表，用于指定要显示在x轴上的刻度值的标签。标签通常与刻度值一一对应，但可以根据需求进行调整。
**kwargs：任意可选的关键字参数，用于设置坐标轴的属性，例如字体大小、颜色等。

返回一个或多个Text对象的列表，这些对象表示设置后的刻度标签。

x = [1, 2, 3, 4, 5]
y = [10, 20, 30, 40, 50]

plt.plot(x, y)
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

# 设置x轴的刻度和标签
plt.xticks([1, 2, 3, 4, 5], ['A', 'B', 'C', 'D', 'E'])

# 设置y轴的刻度和标签
plt.yticks([10, 20, 30, 40, 50], ['Low', 'Medium', 'High', 'Very High', 'Maximum'], rotation=45)

plt.show()

------------------------------------------------------------------------------------------------------------------------

img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# ret, dst = cv2.threshold(src, thresh, maxval, type)
# src： 输入图，只能输入单通道图像，通常来说为灰度图
# dst： 输出图
# thresh： 阈值
# maxval： 当像素值超过了阈值（或者小于阈值，根据type来决定），所赋予的值
# type：二值化操作的类型，包含以下5种类型： cv2.THRESH_BINARY； cv2.THRESH_BINARY_INV； cv2.THRESH_TRUNC； cv2.THRESH_TOZERO；cv2.THRESH_TOZERO_INV
# cv2.THRESH_BINARY           超过阈值部分取maxval（最大值），否则取0
# cv2.THRESH_BINARY_INV    THRESH_BINARY的反转
# cv2.THRESH_TRUNC            大于阈值部分设为阈值，否则不变
# cv2.THRESH_TOZERO          大于阈值部分不改变，否则设为0
# cv2.THRESH_TOZERO_INV  THRESH_TOZERO的反转
# cv2.THRESH_OTSU是OpenCV中用于图像阈值化的一个标志常量。它是基于大津算法（Otsu’s method）的自动阈值化方法
# cv2.THRESH_OTSU常量必须与其他阈值化方法（如cv2.THRESH_BINARY）一起使用，用于指定阈值化的方法类型。这是因为cv2.threshold()函数的type参数可以同时包含多个阈值化方法的标志。使用|运算
# 返回值:
# retval：实际使用的阈值，即在进行阈值化处理时计算得到的最佳阈值。
# threshold_image：阈值化后的二值图像，即根据阈值对输入图像进行二值化处理得到的结果。

ret, thresh1 = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)
ret, thresh2 = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY_INV)
ret, thresh3 = cv2.threshold(img, 127, 255, cv2.THRESH_TRUNC)
ret, thresh4 = cv2.threshold(img, 127, 255, cv2.THRESH_TOZERO)
ret, thresh5 = cv2.threshold(img, 127, 255, cv2.THRESH_TOZERO_INV)

titles = ['Original Image', 'BINARY', 'BINARY_INV', 'TRUNC', 'TOZERO', 'TOZERO_INV']
images = [img, thresh1, thresh2, thresh3, thresh4, thresh5]

for i in range(6):
    plt.subplot(2, 3, i + 1), plt.imshow(images[i], 'gray')
    plt.title(titles[i])
    plt.xticks([]), plt.yticks([])
plt.show()

------------------------------------------------------------------------------------------------------------------------

# 均值滤波，简单的平均卷积操作
blur = cv2.blur(img, (3, 3))
cv2.imshow("blur", blur)
cv2.waitKey(0)
cv2.destroyAllWindows()

# cv2.boxFilter() 方框滤波
# src：输入图像（单通道，8位或浮点型）。
# ddepth：输出图像的深度，使用 -1 表示与输入图像的深度相同。
# 在图像处理中，深度表示图像像素值的数据类型。常见的深度类型有以下几种：
# cv2.CV_8U：8位无符号整数（0-255）。
# cv2.CV_8S：8位有符号整数（-128 到 127）。
# cv2.CV_16U：16位无符号整数（0-65535）。
# cv2.CV_16S：16位有符号整数（-32768 到 32767）。
# cv2.CV_32S：32位有符号整数。
# cv2.CV_32F：32位浮点数。
# cv2.CV_64F：64位浮点数。

# ksize：盒式滤波核的大小，指定为 (ksize.width, ksize.height)。
# dst（可选）：输出图像。
# anchor（可选）：锚点位置，默认为 (-1, -1)，即位于中心。可以指定 (x, y) 对相对于滤波核的锚点位置。
# normalize（可选）：是否将结果进行标准化，默认为 True，表示对结果进行归一化处理。
# borderType（可选）：像素边界处理方式，默认为 cv2.BORDER_DEFAULT，也可以选择其他的边界处理方式。
# cv2.boxFilter() 函数根据指定的核大小对输入图像进行盒式滤波操作。盒式滤波是一种线性滤波方法，它将核内所有像素的值相加并求平均，然后将结果作为输出图像对应位置的像素值。
box = cv2.boxFilter(img, -1, (3, 3), normalize=False)
cv2.imshow("box", box)
cv2.waitKey(0)
cv2.destroyAllWindows()

# 高斯滤波
aussian = cv2.GaussianBlur(img, (3, 3), 1)
cv2.imshow("aussian", aussian)
cv2.waitKey(0)
cv2.destroyAllWindows()

# 中值滤波
median = cv2.medianBlur(img, 3)
cv2.imshow("median", median)
cv2.waitKey(0)
cv2.destroyAllWindows()

# 合并
hsk = np.hstack((blur, aussian, median))
cv2.imshow("hsk", hsk)
cv2.waitKey(0)
cv2.destroyAllWindows()

------------------------------------------------------------------------------------------------------------------------

# 腐蚀erode
kernel = np.ones((3, 3), np.uint8)
imerode = cv2.erode(img, kernel, iterations=1)
cv2.imshow("eroded", imerode)
cv2.waitKey(0)
cv2.destroyAllWindows()

# 膨胀dilate
imdilate = cv2.dilate(imerode, kernel, iterations=1)
cv2.imshow("imdilate", imdilate)
cv2.waitKey(0)
cv2.destroyAllWindows()

# 开运算 先腐蚀后膨胀
# 礼帽 = 原始输入-开运算结果
tophat = cv2.morphologyEx(img, cv2.MORPH_TOPHAT, kernel)
cv2.imshow("tophat", tophat)
cv2.waitKey(0)
cv2.destroyAllWindows()

# 闭运算 先膨胀后腐蚀
# 黑帽 = 闭运算-原始输入
blackhat = cv2.morphologyEx(img, cv2.MORPH_BLACKHAT, kernel)
cv2.imshow("blackhat", blackhat)
cv2.waitKey(0)
cv2.destroyAllWindows()

# 梯度运算，膨胀-腐蚀
gradient = cv2.morphologyEx(img, cv2.MORPH_GRADIENT, kernel)
cv2.imshow("gradient", gradient)
cv2.waitKey(0)
cv2.destroyAllWindows()

------------------------------------------------------------------------------------------------------------------------

# 图像梯度-Sobel算子
# cv2.Sobel(src, ddepth, dx, dy[, ksize[, scale[, delta[, borderType]]]])
# 参数说明：
# src：输入图像。可以是灰度图像或彩色图像，数据类型为 numpy.ndarray。
# ddepth：输出图像的深度（数据类型）。通常使用 -1 表示与输入图像相同。
# dx：x方向上的差分阶数，表示求导的次数。
# dy：y方向上的差分阶数，表示求导的次数。
# ksize：Sobel核的大小，必须是奇数且大于1的正整数。默认值为 3。
# scale：可选参数，分配给计算出的梯度的缩放因子，默认值为 1。
# delta：可选参数，添加到计算出的梯度中的值，默认值为 0。
# borderType：可选参数，用于扩展图像边界的方法，默认值为 cv2.BORDER_DEFAULT。
# 返回值为输出图像，它与原始图像大小相同，数据类型为 numpy.ndarray。

sobx = cv2.Sobel(img, -1, 1, 0, ksize=3)
cv_show("sobx", sobx)

soby = cv2.Sobel(img, -1, 0, 1, ksize=3)
cv_show("soby", soby)

sobelx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=3)
sobelx = cv2.convertScaleAbs(sobelx)

sobely = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=3)
sobely = cv2.convertScaleAbs(sobely)

# cv2.addWeighted() 是 OpenCV 中的一种图像混合函数，用于将两个图像按权重进行线性混合。下面是该函数的参数、作用和返回值的解释：
# 参数：
# src1：第一个输入图像，即要混合的图像之一。
# alpha：第一个输入图像的权重系数。
# src2：第二个输入图像，即要混合的图像之二。
# beta：第二个输入图像的权重系数。
# gamma：图像混合的偏置值（可选参数）。将它添加到结果图像上，用于调整亮度。
#
# 作用：
# cv2.addWeighted() 函数将两个输入图像按权重进行线性混合。权重系数 alpha 和 beta 决定了每个输入图像在混合过程中的贡献程度，从而控制混合后图像的外观。
# 混合公式为： dst = alpha * src1 + beta * src2 + gamma，其中 dst 是输出的混合图像。
#
# 返回值：
# dst：混合后的图像，它是两个输入图像按权重线性混合得到的结果。
# 返回值的数据类型和通道数与输入图像的一致。
# 需要注意的是，混合过程中图像的尺寸、深度和通道数必须相同。另外，权重系数 alpha 和 beta 的取值范围通常为 [0, 1]，可以根据需要进行调整以获得不同的混合效果。
sobelxy = cv2.addWeighted(sobelx, 0.5, sobely, 0.5, 0)
cv_show("sobelxy", sobelxy)

------------------------------------------------------------------------------------------------------------------------
# Scharr算子
scharrx = cv2.Scharr(img, cv2.CV_64F, 1, 0)
scharry = cv2.Scharr(img, cv2.CV_64F, 0, 1)
scharrx = cv2.convertScaleAbs(scharrx)
scharry = cv2.convertScaleAbs(scharry)
scharrxy = cv2.addWeighted(scharrx, 0.5, scharry, 0.5, 0)

laplacian = cv2.Laplacian(img, cv2.CV_64F)
laplacian = cv2.convertScaleAbs(laplacian)

all = np.hstack((scharrxy, laplacian))
cv_show("all", all)

------------------------------------------------------------------------------------------------------------------------

# Canny边缘检测
# 1. 使用高斯滤波器，以平滑图像，滤除噪声。
# 2. 计算图像中每个像素点的梯度强度和方向。
# 3. 应用非极大值（Non-Maximum Suppression）抑制，以消除边缘检测带来的杂散响应。
# 4. 应用双阈值（Double-Threshold）检测来确定真实的和潜在的边缘。
# 5. 通过抑制孤立的弱边缘最终完成边缘检测。

result1 = cv2.Canny(img, 80, 150)
result2 = cv2.Canny(img, 50, 100)
result = np.hstack((result1, result2))
cv_show("result", result)

img = cv2.imread("C:\\Users\\ZZY\\Desktop\\3.jpg", cv2.IMREAD_GRAYSCALE)

result1 = cv2.Canny(img, 80, 150)
cv_show("result1", result1)
result2 = cv2.Canny(img, 50, 100)
cv_show("result2", result2)

result = np.hstack((result1, result2))
cv_show("result", result)

------------------------------------------------------------------------------------------------------------------------

# pyramid金字塔
# 高斯金字塔
pyrup = cv2.pyrUp(img)
cv_show("pyrup", pyrup)
pyrdown = cv2.pyrDown(img)
cv_show("pyrdown", pyrdown)

cv_show("result", np.hstack((img, cv2.pyrDown(pyrup))))

# laplacian pyramid拉普拉斯金字塔
pyrdown = cv2.pyrDown(img)
down_up = cv2.pyrUp(pyrdown)
cv_show("down_up", down_up)
lap = img - down_up
cv_show("lap", lap)

------------------------------------------------------------------------------------------------------------------------
# 轮廓检测与处理
# cv2.findContours()函数是OpenCV中用于查找图像中的轮廓的函数。它有三个参数：
# 1. image：输入图像，通常是灰度图像。在查找轮廓前，通常需要对原始图像进行阈值处理或边缘检测。
# 2. mode：指定轮廓的检测模式。有四种可选模式：
#    cv2.RETR_EXTERNAL：只检测最外层的轮廓。
#    cv2.RETR_LIST：检测所有的轮廓，并将其存储为列表。
#    cv2.RETR_CCOMP：检测所有的轮廓，并将其存储为两层的层次结构。
#    cv2.RETR_TREE：检测所有的轮廓，并将其存储为树形结构。
# 3. method：指定轮廓的近似方法。有三种可选方法：
#    cv2.CHAIN_APPROX_NONE：存储所有的轮廓点。
#    cv2.CHAIN_APPROX_SIMPLE：压缩水平、垂直和对角线的部分，并只存储其端点。
#    cv2.CHAIN_APPROX_TC89_L1和cv2.CHAIN_APPROX_TC89_KCOS：应用Teach Chain编码方法。
# 4. 返回值有两个：
#    contours：存储检测到的轮廓，每个轮廓表示为一个点的数组。
#    hierarchy：轮廓的层次结构，用于指示轮廓之间的关系。

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret, thres = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
contours, hierarchy = cv2.findContours(thres, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)
# print(contours)
# print(hierarchy)

tmp = img.copy()

# cv2.drawContours()函数用于绘制轮廓。
# 1. 它有五个参数：
#    image：要绘制轮廓的图像。
#    contours：要绘制的轮廓，可以通过cv2.findContours()得到。
#    contourIdx：指定绘制轮廓的索引。如果为负数，则绘制全部轮廓。
#    color：轮廓的颜色。
#    thickness：轮廓的线宽，如果为负数或cv2.FILLED，则填充轮廓。
# 2. 返回的值即为绘制好轮廓的图像。

cv_show("tmp", cv2.drawContours(tmp, contours, -1, (0, 0, 255), 1))

for i in range(len(contours)):
    # 面积
    print(str(i)+": "+str(cv2.contourArea(contours[i]))+'\n')
    # 周长
    print(str(i) + ": " + str(cv2.arcLength(contours[i], True)) + '\n')

------------------------------------------------------------------------------------------------------------------------

# 轮廓近似
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret, thres = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
contours, hierarchy = cv2.findContours(thres, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)

tmp = img.copy()

# cv2.approxPolyDP()函数是OpenCV中用于对轮廓进行多边形逼近的函数。
# 1. 它有三个参数：
#    curve：输入的轮廓，通常是cv2.findContours()函数返回的轮廓之一。
#    epsilon：指定逼近精度的参数。表示从原始轮廓到逼近多边形的最大距离。较小的 epsilon 值会导致更精确的逼近。
#    closed：一个布尔值，指定逼近多边形是否是闭合的。如果为True，则代表多边形是闭合的，否则为False。
# 2. 返回值为一个多边形的点集，表示逼近后的多边形。
#    下面是函数的返回值的形式：
#    如果原始轮廓为空，则返回空列表 []。
#    如果无法从给定参数创建多边形，则返回空列表 []。
#    否则，返回逼近多边形的点集，形式为 numpy.ndarray 类型的列表。每个点由二维坐标 (x, y) 表示。

# cv_show("result", cv2.drawContours(tmp, [cv2.approxPolyDP(contours[0], 0.05*cv2.arcLength(contours[0], True), True)], -1, (0, 0, 255), 2))

curve = contours[0]
epsilon = 0.01*cv2.arcLength(curve, True)
approx = cv2.approxPolyDP(curve, epsilon, True)
cv_show("result", cv2.drawContours(tmp, [approx], -1, (0, 0, 255), 2))

------------------------------------------------------------------------------------------------------------------------
# 边界矩形
# cv2.rectangle()函数是OpenCV中用于在图像上绘制矩形的函数。
# 1. 它有五个参数：
#    img：要绘制矩形的图像。
#    pt1：矩形的左上角顶点坐标。
#    pt2：矩形的右下角顶点坐标。
#    color：矩形的颜色。
#    thickness：矩形的线宽。如果为负数或cv2.FILLED，则填充矩形。
# 2. 没有显式的返回值，该函数直接在输入的图像上绘制了矩形。

# cv2.boundingRect()函数是用于计算轮廓的最小边界矩形的函数。
# 1. 它有一个参数：
#    contour：输入的轮廓，通常是cv2.findContours()函数返回的轮廓之一。
# 2. 返回值是一个包围轮廓的矩形。返回的矩形是以 (x, y, width, height) 的形式表示，其中 (x, y) 是矩形左上角的坐标，width 和 height 是矩形的宽度和高度。

x, y, width, height = cv2.boundingRect(contours[0])
tmp = img.copy()
cv2.rectangle(tmp, (x, y), (x+width, y+height), (0, 0, 255), 2)
cv_show("tmp", tmp)

area = cv2.contourArea(contours[0])
print(area / (width * height))

# 外接圆
# cv2.minEnclosingCircle()函数是OpenCV中用于计算轮廓的最小包围圆的函数。
# 1. 它有一个参数：
#    contour：输入的轮廓，通常是cv2.findContours()函数返回的轮廓之一。
# 2. 返回值是一个元组，包含两个值：
#    center：最小包围圆的圆心坐标，以 (x, y) 的形式表示。
#    radius：最小包围圆的半径。
# 该函数计算出的最小包围圆是将轮廓完全包围的一个圆，使得圆的面积最小。返回的圆心坐标和半径可以用于绘制最小包围圆或其他需要使用该信息的操作。

# cv2.circle()函数是OpenCV中用于在图像上绘制圆形的函数。
# 1. 它有六个参数：
#    img：要绘制圆形的图像。
#    center：圆心的坐标，以 (x, y) 的形式表示。
#    radius：圆的半径。
#    color：圆的颜色。
#    thickness：圆的线宽。如果为负数或cv2.FILLED，则填充圆。
#    lineType：圆边界的线型。
# 2. 没有显式的返回值，该函数直接在输入的图像上绘制了圆形。通过指定圆心坐标、半径、颜色和线宽，可以在图像中绘制一个圆形。
# 请注意，绘制圆形的圆心坐标和半径需要符合图像的尺寸范围，否则可能会导致越界或不正确的绘制结果。

(x, y), radius = cv2.minEnclosingCircle(contours[0])
tmp = img.copy()
cv2.circle(tmp, (int(x), int(y)), int(radius), (0, 0, 255), 2)
cv_show("tmp", tmp)

------------------------------------------------------------------------------------------------------------------------

# 模板匹配,从上到下，从左到右匹配
# cv2.matchTemplate()
# 1. 参数：
#    image：输入图像。
#    template：待匹配的模板图像。
#    method：匹配方法，用于指定匹配的度量标准。
#       常用的方法有：
#       cv2.TM_SQDIFF：平方差匹配法。计算平方不同，计算出来的值越小，越相关
#       cv2.TM_SQDIFF_NORMED：归一化平方差匹配法。计算归一化平方不同，计算出来的值越接近0，越相关
#       cv2.TM_CCORR：相关性匹配法。计算相关性，计算出来的值越大，越相关
#       cv2.TM_CCORR_NORMED：归一化相关性匹配法。计算归一化相关性，计算出来的值越接近1，越相关
#       cv2.TM_CCOEFF：相关性系数匹配法。计算相关系数，计算出来的值越大，越相关
#       cv2.TM_CCOEFF_NORMED：归一化相关性系数匹配法。计算归一化相关性，计算出来的值越接近1，越相关
#       methods = ['cv2.TM_CCOEFF', 'cv2.TM_CCOEFF_NORMED', 'cv2.TM_CCORR',
#            'cv2.TM_CCORR_NORMED', 'cv2.TM_SQDIFF', 'cv2.TM_SQDIFF_NORMED']
# 2. 返回值：
#    匹配结果图像，其大小为 (W - w + 1, H - h + 1)，其中 W 和 H 是输入图像的宽度和高度，w 和 h 是模板图像的宽度和高度。每个像素表示模板与输入图像上对应位置的匹配程度。
# 一般来说，匹配结果图像中的较亮区域表示匹配度较高的区域，可以通过阈值设置来确定匹配的位置。最佳匹配位置可以通过使用函数 cv2.minMaxLoc() 来获取，该函数返回最小值和最大值的位置坐标。

# cv2.minMaxLoc() 函数用于在数组中找到最小值和最大值的位置。以下是该函数的参数、作用和返回值：
# 1. 参数：
#    src：输入数组，可以是单通道或多通道的图像。
#    mask：可选参数，与输入数组相同大小的掩码。只会在掩码为非零的位置进行最小值和最大值的计算。
#    若不需使用掩码，则可以将其设为 None（默认值）。
# 2. 返回值：
#    函数会返回一个元组，包含以下值：
#    minVal：输入数组中的最小值。
#    maxVal：输入数组中的最大值。
#    minLoc：最小值的位置坐标，以 (x, y) 的形式表示。
#    maxLoc：最大值的位置坐标，以 (x, y) 的形式表示。

img = cv2.imread("C:\\Users\\ZZY\\Desktop\\2.jpg")
template = img[50:150, 50:150]
cv_show("img", img)
cv_show("template", template)

result = cv2.matchTemplate(img, template, cv2.TM_SQDIFF_NORMED)
minVal, maxVal, minLoc, maxLoc = cv2.minMaxLoc(result)
x1 = minLoc[0] + 100
y1 = minLoc[1] + 100
tmp = img.copy()
cv2.rectangle(tmp, minLoc, (x1, y1), (0, 0, 255), 2)
cv_show("tmp", tmp)
print(minVal)

------------------------------------------------------------------------------------------------------------------------
# 模板匹配，不同methods
# plt.suptitle() 是 Matplotlib 库中用于设置整个图表的标题的函数。以下是该函数的参数、作用和返回值：
# 1. 参数：
#    t：标题的文本内容。
#    **kwargs：可选参数，用于设置标题的属性，如字体大小、颜色等。
# 2. 返回值：
#    该函数没有显式的返回值，调用该函数后会设置整个图表的标题。
# 3. 作用：
#    plt.suptitle() 函数用于在生成的图表中添加一个标题，该标题会显示在图表的顶部。可以使用该函数设置图表的主标题。可选参数 kwargs 可以用于设置标题的属性，如字体大小、颜色等，以满足个性化的需求。
# 4. 示例用法：
#    import matplotlib.pyplot as plt
#    plt.plot([1, 2, 3, 4], [1, 4, 9, 16])
#    plt.suptitle("Plot Title", fontsize=14, color='red')
#    plt.show()
#    上述代码会生成一个简单的折线图，并设置标题为 “Plot Title”，标题的字体大小为 14，颜色为红色。可以根据实际需求自定义标题的样式和属性。
# 请注意，plt.suptitle() 函数是用于设置整个图表的标题，而不是单独某个子图的标题。如果需要为单独的子图添加标题，应该使用相应子图对象的 set_title() 方法。

img = cv2.imread("C:\\Users\\ZZY\\Desktop\\2.jpg")
template = img[50:150, 50:150]
w = h = 100
methods = ['cv2.TM_CCOEFF', 'cv2.TM_CCOEFF_NORMED', 'cv2.TM_CCORR',
           'cv2.TM_CCORR_NORMED', 'cv2.TM_SQDIFF', 'cv2.TM_SQDIFF_NORMED']

for meth in methods:
    img2 = img.copy()

    # 匹配方法的真值
    method = eval(meth)
    print(method)
    res = cv2.matchTemplate(img, template, method)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)

    # 如果是平方差匹配TM_SQDIFF或归一化平方差匹配TM_SQDIFF_NORMED，取最小值
    if method in [cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]:
        top_left = min_loc
    else:
        top_left = max_loc
    bottom_right = (top_left[0] + w, top_left[1] + h)

    # 画矩形
    cv2.rectangle(img2, top_left, bottom_right, 255, 2)

    plt.subplot(1, 2, 1), plt.imshow(res, cmap='gray')
    plt.xticks([]), plt.yticks([])  # 隐藏坐标轴
    plt.subplot(1, 2, 2), plt.imshow(img2, cmap='gray')
    plt.xticks([]), plt.yticks([])
    plt.suptitle(meth)
    plt.show()

------------------------------------------------------------------------------------------------------------------------
# 多模板匹配
img = cv2.imread("C:\\Users\\ZZY\\Desktop\\0.jpg")
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
tmp = img.copy()
template = cv2.imread("C:\\Users\\ZZY\\Desktop\\1.jpg", cv2.IMREAD_GRAYSCALE)
# shape返回数组的行，列
h, w = template.shape[:2]
# print(tmp.shape)
# print(template.shape)
result = cv2.matchTemplate(img_gray, template, cv2.TM_CCOEFF_NORMED)    # 用cv2.TM_SQDIFF_NORMED直接全红
threshold = 0.8
locs = np.where(result >= threshold)
# print(locs)
# print(locs[::-1])
# print(*locs[::-1])
# print(zip(*locs[::-1]))
# minVal, maxVal, minLoc, maxLoc = cv2.minMaxLoc(result)
for loc in zip(*locs[::-1]):
    Right_Bottom = (loc[0]+w, loc[1]+h)
    cv2.rectangle(tmp, loc, Right_Bottom, (0, 0, 255), 2)

cv_show("all", tmp)
------------------------------------------------------------------------------------------------------------------------
# 对比度（Contrast）是用来描述图像中不同亮度区域之间差异程度的一个概念。在数字图像处理中，对比度是指图像中灰度级别（或颜色）之间的差异程度。
# 对比度的高低决定了图像中不同区域的灰度级别差异的明显程度。当对比度较低时，图像中的不同区域之间灰度级别的差异很小，图像呈现出灰暗、柔和的效果。而当对比度较高时，图像中的不同区域之间灰度级别的差异很大，图像呈现出明亮、锐利的效果。
# 增加图像的对比度可以使图像中的细节更加明显，使得图像更加清晰和有层次感。而降低图像的对比度可以使图像呈现出柔和、艺术化的效果。
# 在数字图像处理中，可以通过一些调整图像像素值的方法来改变图像的对比度，例如通过增加或减小像素值的差异来增强或降低对比度。常见的图像增强方法包括直方图均衡化、对比度拉伸、伽马校正等。
# 因此，如果要拉高图片的对比度，可以使用适当的图像增强方法来增加图像中不同区域之间的灰度级别差异，使图像更加清晰和鲜明。
# 对比度的概念可以通过以下方式来理解：
# 当图像的对比度较低时，图像中的不同区域之间的灰度级别差异很小。这意味着图像中的亮部和暗部的灰度级别之间的差异不明显。结果是图像呈现出一种柔和、平缓的外观，可能缺乏细节和明确的边界。这种低对比度的图像可能看起来灰暗、模糊或稍微失真。
# 相反，当图像的对比度较高时，图像中的不同区域之间的灰度级别差异很大。这意味着图像中的亮部和暗部的灰度级别之间有明显的差异。结果是图像呈现出明亮、鲜艳的外观，细节和边界更加清晰。高对比度的图像可能具有明确的黑白分界线，具有较强的视觉影响力。
# 通过调整图像的对比度，可以改变图像中不同区域的灰度级别差异。这可以通过增强或降低图像中的像素值差异来实现。例如，增强对比度可以通过扩展图像的灰度级别范围，使亮部更亮，暗部更暗，以突出图像的细节。而降低对比度可以通过压缩图像的灰度级别范围来实现，使灰度级别之间的差异减小，以获得一种更平缓、柔和的外观。
# 综上所述，对比度决定了图像中不同区域之间的灰度级别差异明显程度。低对比度图像看起来柔和、模糊，而高对比度图像看起来明亮、锐利。

# #直方图
# cv2.calcHist() 是OpenCV库中用于计算图像直方图的函数。它接受一些参数来指定图像和直方图的计算方式，并返回一个表示直方图的NumPy数组。
# 1. 具体来说，cv2.calcHist() 的参数如下：
#    images：表示图像的NumPy数组，可以是灰度图像或彩色图像。
#    channels：列表类型的参数，表示要计算直方图的通道索引。对于灰度图像，值为[0]；对于彩色图像，值为[0, 1, 2] 分别表示蓝色通道、绿色通道和红色通
#    mask：表示用于计算直方图的掩膜图像（可选）。如果传入了掩膜图像，则只统计掩膜区域内的像素。
#    histSize：整数或列表类型的参数，表示直方图的大小（即直方图的 bin 数量）。对于灰度图像，值为[256] 表示使用 256 个 bin；对于彩色图像，可以为每个通道指定不同的 bin 数量，例如 [32, 32, 32] 表示每个通道使用 32 个 bin。
#    ranges：列表类型的参数，表示直方图的范围。对于灰度图像，值为[0, 256] 表示灰度级别范围；对于彩色图像，可以为每个通道指定不同的范围，例如 [0, 256, 0, 256, 0, 256] 表示蓝色通道、绿色通道和红色通道的范围分别为 0-256。
#    cv2.calcHist() 的作用是计算图像的直方图，即统计图像中每个灰度级别（或颜色）对应的像素数量。直方图可以用来描述图像中不同灰度级别（或颜色）的分布情况，帮助分析图像的亮度和颜色特征。
# 2. 返回值是一个表示直方图的NumPy数组，数组的维度取决于图像和通道的数量以及直方图的大小。对于灰度图像，返回的数组是一个一维数组，长度为直方图的 bin 数量；对于彩色图像，返回的数组是一个多维数组，每个维度的长度都对应于相应通道的 bin 数量。

# 方法一
img = cv2.imread("C:\\Users\\ZZY\\Desktop\\0.jpg", cv2.IMREAD_GRAYSCALE)
hist = cv2.calcHist(img, [0], None, [256], [0, 256])
# print(hist)
plt.plot(hist)
plt.xlim([0, 256])
plt.show()

# 方法二
# print(img)
# print(img.ravel())
plt.hist(img.ravel(), 256)
plt.show()

# 方法三
img = cv2.imread("C:\\Users\\ZZY\\Desktop\\0.jpg")
img = cv2.medianBlur(img, 5)
color = ['r', 'g', 'b']
for i, col in enumerate(color):
    hist = cv2.calcHist(img, [i], None, [256], [0, 256])
    plt.plot(hist, color=col)
    plt.xlim([0, 256])
plt.show()

# 方法四
# cv2.bitwise_and() 是 OpenCV 库中的一个位与运算函数，用于对图像进行按位与操作。它对输入的两个数组进行逐元素的位与运算，并将结果作为输出返回。
# 1. 具体来说，cv2.bitwise_and() 的参数如下：
#    src1：表示第一个输入的数组，可以是图像或其他多维数组。
#    src2：表示第二个输入的数组，也可以是图像或其他多维数组。src1 和 src2 的大小和数据类型必须一致。
#    mask：可选参数，表示一个掩膜图像或阈值图像，用于指定要执行位与运算的区域（像素）。如果指定了掩膜图像，则只有掩膜图像中对应的像素为非零时，位与运算才会被执行；否则，输出图像对应位置的像素为零。
# 2. 返回值是执行位与运算后的输出数组，与输入的数组具有相同的大小和数据类型。

img = cv2.imread("C:\\Users\\ZZY\\Desktop\\0.jpg", cv2.IMREAD_GRAYSCALE)
mask = np.zeros(img.shape[:2], np.uint8)
mask[50:150, 50:150] = 255
res = cv2.bitwise_and(img, mask)
# res = cv2.bitwise_and(img, img, mask=mask)
cv_show("res", res)
parthist = cv2.calcHist([img], [0], mask, [256], [0, 256])
fullhist = cv2.calcHist([img], [0], None, [256], [0, 256])

plt.subplot(2, 2, 1), plt.imshow(img, 'gray')
plt.subplot(2, 2, 2), plt.imshow(mask, 'gray')
plt.subplot(2, 2, 3), plt.imshow(res, 'gray')
plt.subplot(2, 2, 4), plt.plot(fullhist, color='r'), plt.plot(parthist, color='b')
plt.xlim([0, 256])
plt.show()
------------------------------------------------------------------------------------------------------------------------

# 直方图均衡化
# cv2.equalizeHist() 是 OpenCV 库中的直方图均衡化函数，用于对灰度图像进行直方图均衡化操作。直方图均衡化是一种图像增强的技术，通过重新分配图像像素的灰度值，使得图像的直方图在整个灰度范围内更加均匀，增强了图像的对比度和细节。
# 1. 具体来说，cv2.equalizeHist() 的参数如下：
#    src：表示输入的灰度图像。
# 2. 返回值是均衡化后的输出图像。
# cv2.equalizeHist() 可以用于增强图像的对比度，改善图像的视觉效果。它在计算机视觉和图像处理领域具有广泛的应用，例如人脸识别、物体检测、图像增强等。通过均衡化直方图，可以使图像的灰度分布更加均匀，从而提高图像的质量和可分辨性。
img = cv2.imread("C:\\Users\\ZZY\\Desktop\\1.jpg", cv2.IMREAD_GRAYSCALE)
plt.hist(img.ravel(), 256)
plt.show()

eqhist = cv2.equalizeHist(img)
plt.hist(eqhist.ravel(), 256)
plt.show()

cv_show("all", np.hstack((img, eqhist)))
# cv2.createCLAHE() 是 OpenCV 库中的自适应直方图均衡化函数，用于创建自适应的对比度限制自适应直方图均衡器（CLAHE）。CLAHE 是一种改进的直方图均衡化算法，它将图像分成小块区域，并对每个小块区域进行直方图均衡化，从而提高对比度的同时避免过度增强噪声。
# 1. 具体来说，cv2.createCLAHE() 的参数如下：
#    clipLimit：表示对比度限制的阈值。它控制对比度增强的程度，较小的值会产生较弱的增强效果，较大的值会产生较强的增强效果。通常取值范围为 0 到 40 之间。
#    tileGridSize：表示用于图像分块的网格大小，以像素为单位。它决定了均衡器将图像分成多少个互不重叠的块。较小的值会产生更多的细节，但可能会导致增加噪声的风险，较大的值则会产生更平滑的结果。
# 2. 返回值是一个CLAHE对象，可用于后续的直方图均衡化操作。
# 自适应的对比度限制自适应直方图均衡化 (CLAHE) 在图像的局部区域进行直方图均衡化，在处理具有不同光照条件的图像时效果更好。它常用于医学图像处理、计算机视觉任务中的图像增强等领域。

clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8))
res_clahe = clahe.apply(img)
cv_show("all", np.hstack((img, res_clahe)))

plt.hist(img.ravel(), 256, color='r')
plt.hist(res_clahe.ravel(), 256, color='b')
plt.show()
------------------------------------------------------------------------------------------------------------------------

# 傅里叶变换
# https://zhuanlan.zhihu.com/p/19763358

# 傅里叶变换的作用
# 高频：变化剧烈的灰度分量，例如边界
# 低频：变化缓慢的灰度分量，例如一片大海

# 滤波
# 低通滤波器：只保留低频，会使得图像模糊
# 高通滤波器：只保留高频，会使得图像细节增强

# opencv中主要就是cv2.dft()和cv2.idft()，输入图像需要先转换成np.float32 格式。
# 得到的结果中频率为0的部分会在左上角，通常要转换到中心位置，可以通过shift变换来实现。
# cv2.dft()返回的结果是双通道的（实部，虚部），通常还需要转换成图像格式才能展示（0,255）。

img = cv2.imread("C:\\Users\\ZZY\\Desktop\\2.jpg", cv2.IMREAD_GRAYSCALE)
img = np.float32(img)
# cv2.DFT_COMPLEX_OUTPUT表示输出将被计算为复数数组，其中实部和虚部分别存储在不同的通道中。
Fourier_transform = cv2.dft(img, flags=cv2.DFT_COMPLEX_OUTPUT)
# 使用np.fft.fftshift函数将零频率分量移动到频谱的中心
Fourier_transform_shift = np.fft.fftshift(Fourier_transform)

print(img.shape)
# 频谱数组的实部（Real Part）表示信号在不同频率上的实际成分或振幅。它描述了信号在频域上的强度分布。
# 频谱数组的虚部（Imaginary Part）表示信号在不同频率上的虚部成分。它描述了信号在频域上的相位分布。
# 复数数组的幅度（Magnitude）是一个实数，表示了频谱数组的强度或振幅。它可以通过计算实部和虚部构成的复数的模来获得：
# amplitude = sqrt(real_part^2 + imaginary_part^2
# 在频谱分析中，通常使用np.log()函数对幅度谱进行对数变换，以便更好地可视化频谱的强度分布。
# 为了增强对数变换后的幅度谱的显示效果，通常会乘以一个常数（在此例中为20）。
# 对数变换可以将较大的数值范围压缩为较小的范围，使得强度分布更易于观察和分析。
magnitude_spectrum = 20*np.log(cv2.magnitude(Fourier_transform_shift[:, :, 0], Fourier_transform_shift[:, :, 1]))

plt.subplot(1, 2, 1), plt.imshow(img, cmap='gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(1, 2, 2), plt.imshow(magnitude_spectrum, cmap='gray')
plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])
plt.show()

# 低通滤波
row, col = img.shape
crow, ccol = row//2, col//2
# 在代码中，rows和cols表示所需的行数和列数，这里创建的数组具有两个通道，对应频谱的实部和虚部。
tmp = np.zeros((row, col, 2), np.uint8)
tmp[crow-30:crow+30, ccol-30:ccol+30] = 1
Fourier_transform_shift_x = Fourier_transform_shift*tmp
Fourier_transform_shift_i = np.fft.ifftshift(Fourier_transform_shift_x)
Fourier_transform_shift_ii = cv2.idft(Fourier_transform_shift_i)
res = cv2.magnitude(Fourier_transform_shift_ii[:, :, 0], Fourier_transform_shift_ii[:, :, 1])

plt.subplot(1, 2, 1), plt.imshow(img, cmap='gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(1, 2, 2), plt.imshow(res, cmap='gray')
plt.title('res'), plt.xticks([]), plt.yticks([])
plt.show()

# 高通滤波
row, col = img.shape
crow, ccol = row//2, col//2
# 在代码中，rows和cols表示所需的行数和列数，这里创建的数组具有两个通道，对应频谱的实部和虚部。
tmp = np.ones((row, col, 2), np.uint8)
tmp[crow-30:crow+30, ccol-30:ccol+30] = 0
Fourier_transform_shift_x = Fourier_transform_shift*tmp
Fourier_transform_shift_i = np.fft.ifftshift(Fourier_transform_shift_x)
Fourier_transform_shift_ii = cv2.idft(Fourier_transform_shift_i)
res = cv2.magnitude(Fourier_transform_shift_ii[:, :, 0], Fourier_transform_shift_ii[:, :, 1])

plt.subplot(1, 2, 1), plt.imshow(img, cmap='gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(1, 2, 2), plt.imshow(res, cmap='gray')
plt.title('res'), plt.xticks([]), plt.yticks([])
plt.show()
------------------------------------------------------------------------------------------------------------------------


# 视频处理---------------------------------------------------------------------------------------------------------------
video = cv2.VideoCapture("C:\\Users\\ZZY\Desktop\\0.mp4")
if video.isOpened():
    Open, frame = video.read()
else:
    Open = False

while Open:
    ret, frame = video.read()
    if frame is None:
        break
    if ret is True:
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        cv2.imshow("result", gray)
        if cv2.waitKey(100) & 0xFF == 27:
            break

video.release()
cv2.destroyAllWindows()
'''