import cv2
import numpy as np

image = cv2.imread("ref.jpg")

blue, green, red = cv2.split(image)

# the blank image must have the same shape as a single channel because a single channel will be merged into it
# to do so, the shape must be same
blank = np.zeros_like(red)

blueimg = cv2.merge([blue, blank, blank])
greenimg = cv2.merge([blank, green, blank])
redimg = cv2.merge([blank, blank, red])

cv2.imshow("Original", image)
cv2.imshow("Blue Component", blueimg)
cv2.imshow("Green Component", greenimg)
cv2.imshow("Red Component", redimg)

cv2.waitKey(0)
cv2.destroyAllWindows()

