import cv2
import numpy as np
import matplotlib.pyplot as plt
image = cv2.imread("ref.jpg",cv2.IMREAD_GRAYSCALE)
c = 1
gamma = 1.8
output = c * np.power(image.astype(float)/255.0,gamma)

fig,axs = plt.subplots(1,2,figsize=(30,30))
axs[0].imshow(image,cmap="gray");
axs[0].set_title("Original Image");
axs[1].imshow(output,cmap="gray");
axs[1].set_title(f"gamma={gamma}");

plt.show()
cv2.waitKey(0)
cv2.destroyAllWindows()
