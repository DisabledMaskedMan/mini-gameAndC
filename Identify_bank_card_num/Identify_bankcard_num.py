import cv2
import numpy as np
from imutils import contours

def cv_show(name, img):
    cv2.imshow(name, img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

def resize(image, width=None, height=None, inter=cv2.INTER_AREA):
    dim = None
    (h, w) = image.shape[:2]
    if width is None and height is None:
        return image
    if width is None:
        r = height / float(h)
        dim = (int(w * r), height)
    else:
        r = width / float(w)
        dim = (width, int(h * r))
    resized = cv2.resize(image, dim, interpolation=inter)
    return resized

# 模板图片处理
template = cv2.imread("C:\\Users\\ZZY\Desktop\\template-matching-ocr\\images\\ocr_a_reference.png")
template_gray = cv2.cvtColor(template, cv2.COLOR_BGR2GRAY)
# cv_show("template", template)
tem_gray_thresh = cv2.threshold(template_gray, 10, 255, cv2.THRESH_BINARY_INV)[1]
# cv_show("temp", tem_thresh)
tem_g_t_contours = cv2.findContours(tem_gray_thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
# cv_show("cpy", cv2.drawContours(template.copy(), tem_g_t_contours, -1, (0, 0, 255), 3))

# 模板提取
num = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
rect = []
for contour in tem_g_t_contours:
    rect.append(cv2.boundingRect(contour))
rect = sorted(rect, key=lambda a: a[0], reverse=False)
num_seq = zip(num, rect)
num_template = []
# print(list(num_seq))
# tmp = template.copy()
for i in num_seq:
    x, y = i[1][0], i[1][1]
    x1, y1 = x+i[1][2], y+i[1][3]
    tmp = tem_gray_thresh[y:y1, x:x1]
    tmp = cv2.resize(tmp, (57, 88))
    num_template.append(tmp)
# for i in range(10):
#     print(num_template[i].shape)      # (85, 53)
#     cv_show(str(i), num_template[i])

# 目标图片处理
img = cv2.imread("C:\\Users\\ZZY\Desktop\\template-matching-ocr\\images\\credit_card_01.png")
# cv_show("img_gray", img)
# print(img.shape)
img = resize(img, width=300)
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# cv_show("img_gray", img_gray)
# print(img_gray.shape)

# 得到卷积核
rectKernel = cv2.getStructuringElement(cv2.MORPH_RECT, (9, 3))
sqKernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))

# 礼帽操作，突出更明亮的区域
img_gray_th = cv2.morphologyEx(img_gray, cv2.MORPH_TOPHAT, rectKernel)
# Sobel算子
img_gray_th_f = cv2.Sobel(img_gray_th, ddepth=cv2.CV_32F, dx=1, dy=0, ksize=3)
img_gray_th_f = np.absolute(img_gray_th_f)
# 归一化
(minVal, maxVal) = (np.min(img_gray_th_f), np.max(img_gray_th_f))
img_gray_th_f = (255 * ((img_gray_th_f - minVal) / (maxVal - minVal)))
img_gray_th_f = img_gray_th_f.astype("uint8")
# 闭运算
img_gray_th_f_close = cv2.morphologyEx(img_gray_th_f, cv2.MORPH_CLOSE, rectKernel)
# 阈值处理
img_gray_th_f_close = cv2.threshold(img_gray_th_f_close, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)[1]
# 通过闭操作（先膨胀，再腐蚀）将数字连在一起
img_gray_th_f_close = cv2.morphologyEx(img_gray_th_f_close, cv2.MORPH_CLOSE, rectKernel)
# cv_show("img_gray_th_close", img_gray_th_f_close)

# 我的方法
img_gray_thresh = cv2.threshold(img_gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)[1]
img_gray_thresh_close = cv2.morphologyEx(img_gray_thresh, cv2.MORPH_CLOSE, rectKernel)
img_gray_thresh_close = cv2.morphologyEx(img_gray_thresh_close, cv2.MORPH_CLOSE, rectKernel)
# cv_show("img_gray_thresh_close", img_gray_thresh_close)

# res = np.hstack((img_gray_th_f_close, img_gray_thresh_close))
# cv_show("res", res)

# 寻找轮廓
img_contours = cv2.findContours(img_gray_th_f_close, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
img_rect = []
for contour in img_contours:
    img_rect.append(cv2.boundingRect(contour))
# tmp = img.copy()
# for rect in img_rect:
#     x, y = rect[0], rect[1]
#     x1, y1 = x+rect[2], y+rect[3]
#     cv2.rectangle(tmp, (x, y), (x1, y1), (0, 0, 255), 3)
# cv_show("tmp", tmp)
# cv_show("tmp", cv2.drawContours(img.copy(), img_contours, -1, (0, 0, 255), 3))

# 我的方法
m_img_contours = cv2.findContours(img_gray_thresh_close, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
m_img_rect = []
for contour in img_contours:
    m_img_rect.append(cv2.boundingRect(contour))
# tmp = img.copy()
# for rect in m_img_rect:
#     x, y = rect[0], rect[1]
#     x1, y1 = x+rect[2], y+rect[3]
#     cv2.rectangle(tmp, (x, y), (x1, y1), (0, 0, 255), 3)
# cv_show("tmp", tmp)
# cv_show("tmp", cv2.drawContours(img.copy(), m_img_contours, -1, (0, 0, 255), 3))

img_rect_res = []
# 遍历轮廓
for (i, c) in enumerate(m_img_rect):
    (x, y, w, h) = c
    ar = w / float(h)
    # 选择合适的区域，根据实际任务来，这里的基本都是四个数字一组
    if ar > 2.5 and ar < 4.0:
        if (w > 40 and w < 55) and (h > 10 and h < 20):
            # 符合的留下来
            img_rect_res.append((x, y, w, h))

img_rect_res = sorted(img_rect_res, key=lambda a: a[0], reverse=False)
# print(img_rect_res)
# tmp = img.copy()
# for rect in img_rect_res:
#     x, y = rect[0], rect[1]
#     x1, y1 = x+rect[2], y+rect[3]
#     cv2.rectangle(tmp, (x, y), (x1, y1), (0, 0, 255), 3)
# cv_show("tmp", tmp)

num = []
for i, (x, y, w, h) in enumerate(img_rect_res):
    group = img_gray[y-5:y+h+5, x-5:x+w+5]
    group = cv2.threshold(group, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)[1]
    # cv_show("group", group)
    group_contours = cv2.findContours(group, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
    group_contours_rects = []
    for group_contour in group_contours:
        group_contours_rects.append(cv2.boundingRect(group_contour))
    group_contours_rects = sorted(group_contours_rects, key=lambda a: a[0], reverse=False)
    for group_contours_rect in group_contours_rects:
        x, y, w, h = group_contours_rect
        group_target = group[y:y+h, x:x+w]
        group_target = cv2.resize(group_target, (57, 88))
        # cv_show("group_target", group_target)
        res = []
        for num_t in num_template:
            _, maxVal, _, _ = cv2.minMaxLoc(cv2.matchTemplate(group_target, num_t, cv2.TM_CCOEFF_NORMED))
            res.append(maxVal)
        num.append(res.index(max(res)))
print(num)

# cv2.resize()函数是OpenCV库中的函数，用于调整图像的大小。
# 参数：
# src：输入的图像，可以是一个Mat对象或图像文件的路径。
# dsize：输出图像的大小，可以是一个元组 (width, height)，也可以是一个整数表示新的大小。
# fx：图像宽度的缩放因子。
# fy：图像高度的缩放因子。
# interpolation：插值方法，用于确定图像如何进行缩放。默认值为INTER_LINEAR。
# interpolation=inter是对图像调整大小过程中的插值方法进行指定的参数。插值是指通过已知的数据点，推测出未知位置上的值的方法。
# cv2.INTER_NEAREST：最近邻插值，取最近的已知像素的值作为插值结果。
# cv2.INTER_LINEAR：双线性插值，基于四个最近的已知像素的值进行线性插值计算。
# cv2.INTER_CUBIC：双三次插值，基于最近的16个已知像素的值进行三次插值计算。
# cv2.INTER_AREA：区域插值，根据像素面积关系进行插值计算。
# cv2.INTER_LANCZOS4：Lanczos插值，计算复杂度较高，但结果质量较好。
