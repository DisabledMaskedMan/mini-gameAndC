from math import *
import cv2
import os
import glob
import imutils
import numpy as np
'''
    img   --image
    angle --rotation angle
    return--rotated img
    '''

def rotate_img(img, angle):
    h, w = img.shape[:2]
    rotate_center = (w / 2, h / 2)
    # 获取旋转矩阵
    # 参数1为旋转中心点;
    # 参数2为旋转角度,正值-逆时针旋转;负值-顺时针旋转
    # 参数3为各向同性的比例因子,1.0原图，2.0变成原来的2倍，0.5变成原来的0.5倍
    M = cv2.getRotationMatrix2D(rotate_center, angle, 1.0)
    # 计算图像新边界
    new_w = int(h * np.abs(M[0, 1]) + w * np.abs(M[0, 0]))
    new_h = int(h * np.abs(M[0, 0]) + w * np.abs(M[0, 1]))
    # 调整旋转矩阵以考虑平移
    M[0, 2] += (new_w - w) / 2
    M[1, 2] += (new_h - h) / 2

    rotated_img = cv2.warpAffine(img, M, (new_w, new_h))
    return rotated_img


if __name__ == '__main__':

    output_dir = "C:\\Users\\ZZY\\Desktop\\1\\output"
    image_names = glob.glob("C:\\Users\\ZZY\\Desktop\\1\\input\\*.jpg")

    for image_name in image_names:
        image = cv2.imread(image_name, -1)
        print(image_name)
        for i in range(1, 361):
            rotated_img1 = rotate_img(image, i)
#            basename = os.path.basename(image_name)
#            tag, _ = os.path.splitext(basename)
            cv2.imwrite(os.path.join(output_dir, 'b-zu-%d.jpg' % i), rotated_img1)

# cv2.getRotationMatrix2D() 函数是 OpenCV 中的一个函数，用于获取一个旋转矩阵，该矩阵可以应用于图像进行旋转操作。
# 函数的参数如下：
# center：一个元组 (x, y)，表示旋转中心的坐标。
# angle：一个浮点数，表示旋转的角度（以度为单位）。
# scale：一个浮点数，表示缩放因子。
# 函数的返回值是一个形状为 (2, 3) 的 NumPy 数组，表示旋转矩阵。该矩阵可以通过 cv2.warpAffine() 函数应用于图像，实现旋转操作。
# cv2.getRotationMatrix2D() 函数返回的确实是一个形状为 (2, 3) 的 NumPy 数组，而不是一个二维的旋转矩阵。
# 这个返回的数组具有以下结构：
# [[a, b, c],
#  [-b, a, d]]
# 其中，a 和 b 是旋转矩阵的元素，c 和 d 是平移矩阵的元素。在这个数组中，前两列是旋转矩阵的部分，而第三列是平移矩阵的部分。

# M[0, 1] 和 M[0, 0] 表示旋转矩阵 M 的第一行的第二个元素和第一个元素。它们对应于旋转角度的正弦值和余弦值。
# 进行这一步是为了确保旋转后的图像能够完整展示，而不被裁剪。当进行图像旋转时，由于旋转会改变图像的尺寸和位置，可能会导致旋转后的图像被裁剪。为了避免这种情况，需要调整旋转矩阵来进行平移。
# 在旋转矩阵中，第一行第三个元素和第二行第三个元素分别表示了在 x 轴和 y 轴上的平移量。通过将这两个平移量分别加上 (new_w - w) / 2 和 (new_h - h) / 2，可以将旋转后的图像平移回原始图像的中心位置。
# 这样做的目的是确保旋转后的图像的边界不会被裁剪。通过进行适当的平移，可以保持图像完整，使其在旋转后仍能被完整展示出来。


# glob.glob("images/b-zu.png") 是一个用于匹配文件路径的模式，并返回匹配的文件路径列表。
# 具体来说，这个模式是 "images/b-zu.png"，它表示匹配文件路径中包含 "images/b-zu.png" 的文件。
# 假设当前目录下有以下文件：
# images/b-zu.png
# images/b-zu1.png
# images/b-zu2.png
# images/test.png
# 那么，glob.glob("images/b-zu.png") 将返回一个列表，其中只包含一个元素：["images/b-zu.png"]。因为只有一个文件的路径与模式完全匹配。
# 如果模式字符串是 "images/*.png"，则 glob.glob("images/*.png") 将返回以下列表：
# ["images/b-zu.png", "images/b-zu1.png", "images/b-zu2.png"]
# 这是因为模式 "images/*.png" 匹配了所有在 "images" 文件夹下以 ".png" 结尾的文件。

# cv2.imread(image_name, -1) 是 OpenCV 中的一个函数，用于读取图像文件并将其转换为 NumPy 数组表示。
# 具体来说，image_name 是一个字符串，表示要读取的图像文件的路径。第二个参数 -1 是一个整数，用于指定读取图像的方式。
# -1 代表以原始的图像格式读取图像，包括 Alpha 通道（如果有的话）。通常情况下，图像的格式为三通道的 BGR（蓝、绿、红），但如果图像包含 Alpha 通道（透明度），则格式为四通道的 BGRA。
# 此函数会返回一个 NumPy 数组，表示读取的图像。如果图像文件不存在或无法读取，函数将返回一个空的 NumPy 数组。

# os.path.basename(image_name) 是一个函数，用于从给定的路径中提取文件名部分。
# 具体来说，image_name 是一个字符串，表示文件的路径。函数返回给定路径中的文件名部分，而不包括路径信息。
# 以下是一个示例：
# python
# import os
# image_name = "path/to/image.png"
# filename = os.path.basename(image_name)
# print(filename)
# 在这个示例中，image_name 是一个路径字符串，表示图像文件的完整路径。os.path.basename(image_name) 将提取文件名部分，并将其存储在变量 filename 中。然后，我们打印出这个文件名。
# 如果 image_name 是 path/to/image.png，则上述示例将打印出 image.png。

# os.path.splitext(basename) 是一个函数，用于从给定的文件名中提取文件名和文件扩展名的部分。
# 具体来说，basename 是一个字符串，表示文件名部分，通常是通过 os.path.basename() 函数从完整路径中提取得到的。函数返回一个元组，其中第一个元素是文件名部分，第二个元素是文件扩展名部分。
# 以下是一个示例：
# python
# import os
# basename = "image.png"
# filename, extension = os.path.splitext(basename)
# print("Filename:", filename)
# print("Extension:", extension)
# 在这个示例中，basename 是一个文件名字符串，表示图像文件的文件名部分。os.path.splitext(basename) 将返回一个元组，其中第一个元素是文件名部分，即 image，第二个元素是文件扩展名部分，即 .png。然后，我们打印出这两个部分。
# cv2.imwrite(os.path.join(output_dir, 'b-zu-%d.jpg' % i), rotated_img1) 是一个函数调用，用于将图像 rotated_img1 保存到指定路径下的文件中。
# 具体来说，os.path.join(output_dir, 'b-zu-%d.jpg' % i) 构建了一个文件路径，其中 output_dir 是保存文件的目标文件夹路径，'b-zu-%d.jpg' % i 是文件名的格式化字符串，%d 是一个占位符，表示将在此处插入一个整数值 i。最终，cv2.imwrite() 函数将图像 rotated_img1 写入到这个文件中。
