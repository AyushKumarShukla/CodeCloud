import cv2
import numpy as np
import matplotlib.pyplot as plt
image = cv2.imread("ref.jpg",cv2.IMREAD_GRAYSCALE)
#image_float = np.float32(image)
c = 55
result = c * np.log1p(1.0+image)
result = cv2.normalize(result, None, 0, 255, cv2.NORM_MINMAX, cv2.CV_8U)
hist1 = cv2.calcHist([result], [0], None, [256], [0, 256])
hist2 = cv2.calcHist([image], [0], None, [256], [0, 256])

# Plot the histogram of the output image
plt.figure(figsize=(8, 6))
plt.hist(result.ravel(), 256, [0, 256])
plt.title('Histogram of the Output Image')
plt.xlabel('Pixel Value')
plt.ylabel('Frequency')
plt.show()

# Plot the histogram of the output image
plt.figure(figsize=(8, 6))
plt.hist(image.ravel(), 256, [0, 256])
plt.title('Histogram of the Input Image')
plt.xlabel('Pixel Value')
plt.ylabel('Frequency')
plt.show()

#display the images
cv2.imshow("Original",image)
cv2.imshow("Log Transformed",result)
cv2.waitKey(0)
cv2.destroyAllWindows()
