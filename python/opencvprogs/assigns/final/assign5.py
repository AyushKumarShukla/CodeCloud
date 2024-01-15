import cv2
import numpy as np

image = cv2.imread("ref.jpg",cv2.IMREAD_GRAYSCALE)

bits = image.itemsize * 8
levels = 2 ** bits

print(f"No of bits = {bits}, No of levels = {levels}")

#image negative
negative_image = levels - 1 - image

#log transformation
c = 55
logt = c * np.log1p(1.0+image)
logt = cv2.normalize(logt, None, 0, 255, cv2.NORM_MINMAX, cv2.CV_8U)

#gamma transformation
c = 1
gamma = 1.8
gt = c * np.power(image.astype(float)/255.0,gamma)

#contrast stretching (Piecewise Linear Transformation)
minval = np.min(image)
maxval = np.max(image)
stretched = (image-minval) * (255.0/(maxval-minval))
stretched = np.uint8(stretched)
cv2.imshow("Original",image)
cv2.imshow("Negative",negative_image)
cv2.imshow("Log Transformation",logt)
cv2.imshow("Gamma Transformation",gt)
cv2.imshow("Contrast Stretching",stretched);
cv2.waitKey(0)
cv2.destroyAllWindows()
