import cv2
import matplotlib.pyplot as plt
import numpy as np

img = cv2.imread('ref.jpg',cv2.IMREAD_GRAYSCALE)

kernel = np.array(
            [[1,1,1],
             [1,1,1],
             [1,1,1]]
            )

#normalise kernel
kernel = kernel / 9

#sum of product filtering
avg_filtered = cv2.filter2D(img,-1,kernel)
#median filter with a 3x3 kernel
median_filtered = cv2.medianBlur(img,3)
#mean filter with a 3x3 kernel
mean_filtered = cv2.blur(img,(3,3))
#max filter with a 3x3 kernel
max_filtered = cv2.dilate(img,(3,3))
#min filter with a 3x3 kernel
min_filtered = cv2.erode(img,(3,3))

#fig,pos=plt.subplots(2,3,figsize=(100,100))

cv2.imshow("Original",img)
cv2.imshow("Average Filtered",avg_filtered)
cv2.imshow("Mean Filtered",mean_filtered)
cv2.imshow("Median Filtered",median_filtered)
cv2.imshow("Max Filtered",max_filtered)
cv2.imshow("Min Filtered",min_filtered)
cv2.waitKey(0)
cv2.destroyAllWindows()
"""
pos[0,0].imshow(cv2.cvtColor(img,cv2.COLOR_BGR2RGB))
pos[0,1].imshow(cv2.cvtColor(avg_filtered,cv2.COLOR_BGR2RGB))
pos[0,2].imshow(cv2.cvtColor(mean_filtered,cv2.COLOR_BGR2RGB))
pos[1,0].imshow(cv2.cvtColor(median_filtered,cv2.COLOR_BGR2RGB))
pos[1,1].imshow(cv2.cvtColor(max_filtered,cv2.COLOR_BGR2RGB))
pos[1,2].imshow(cv2.cvtColor(min_filtered,cv2.COLOR_BGR2RGB))
plt.show()
"""
