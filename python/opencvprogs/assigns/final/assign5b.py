import cv2
import numpy as np
import matplotlib.pyplot as plt
image = cv2.imread("ref.jpg",cv2.IMREAD_GRAYSCALE)
#image_float = np.float32(image)
c = 55
result = c * np.log1p(1.0+image)
result = cv2.normalize(result, None, 0, 255, cv2.NORM_MINMAX, cv2.CV_8U)

#hist1 = cv2.calcHist([result], [0], None, [256], [0, 256])
#hist2 = cv2.calcHist([image], [0], None, [256], [0, 256])

fig, axs = plt.subplots(2, 2, figsize=(10, 8))

# Plot histograms
axs[0, 1].hist(result.ravel(), 256, [0, 256])
axs[0, 1].set_title('Histogram of the Log Transformed Image')
axs[0, 1].set_xlabel('Pixel Value')
axs[0, 1].set_ylabel('Frequency')

axs[0, 0].hist(image.ravel(), 256, [0, 256])
axs[0, 0].set_title('Histogram of the Input Image')
axs[0, 0].set_xlabel('Pixel Value')
axs[0, 0].set_ylabel('Frequency')

# Display images
axs[1, 0].imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
axs[1, 0].set_title('Original Image')
axs[1, 0].axis('off')

axs[1, 1].imshow(cv2.cvtColor(result, cv2.COLOR_BGR2RGB))
axs[1, 1].set_title('Log Transformed Image')
axs[1, 1].axis('off')

plt.tight_layout()
plt.show()
