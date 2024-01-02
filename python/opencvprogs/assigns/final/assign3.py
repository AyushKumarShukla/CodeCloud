import cv2
import numpy as np
import matplotlib.pyplot as plt

image = cv2.imread("ref.jpg",cv2.IMREAD_GRAYSCALE)

fig,pos=plt.subplots(1,2,figsize=(30,30))

#histogram
pos[0].hist(image.ravel(),256,[0,256])
pos[0].set_title("Histogram Of The Grayscale Image")
pos[0].set_xlabel("Intensity Value")
pos[0].set_ylabel("Frequency")

#image
pos[1].imshow(image);
pos[1].set_title("Input Image")

plt.show()
