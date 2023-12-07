import cv2

image = cv2.imshow("ref.jpg",IMREAD_GRAYSCALE)
c = 55
output = c * image ** gamma
