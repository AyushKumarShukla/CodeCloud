import cv2
image = cv2.imread("ref.jpg",cv2.IMREAD_UNCHANGED)
bits = image.itemsize * 8
levels = 2 ** bits
print(f"No of bits = {bits}, No of levels = {levels}")
negative_image = levels - 1 - image
cv2.imshow("Original",image)
cv2.imshow("Negative",negative_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
