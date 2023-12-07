import cv2
import numpy as np
image = cv2.imread("sun.jpg",cv2.IMREAD_GRAYSCALE)
image_float = np.float32(image)
c = 55
result = c * np.log1p(1.0+image_float)
result = cv2.normalize(result, None, 0, 255, cv2.NORM_MINMAX, cv2.CV_8U)
cv2.imshow("Original",image)
cv2.imshow("Log Transformed",result)
cv2.waitKey(0)
cv2.destroyAllWindows()
