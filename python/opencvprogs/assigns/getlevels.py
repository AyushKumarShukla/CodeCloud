import cv2
image = cv2.imread("ref.jpg",cv2.IMREAD_UNCHANGED)
bits = image.itemsize * 8
levels = 2 ** bits
print(f"No of bits = {bits}, No of levels = {levels}")
