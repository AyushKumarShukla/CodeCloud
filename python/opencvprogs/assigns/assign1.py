import cv2
import numpy as np
#RGB IMAGE AS INPUT
image=cv2.imread("sun.jpg")
cv2.imshow("Input Image",image)
#RGB TO GRAY
gray=cv2.cvtColor(image,cv2.COLOR_RGB2GRAY)
#GRAY TO BINARY
_,graytobin=cv2.threshold(gray,250,255,cv2.THRESH_BINARY)
#RGB TO BINARY
_,rgbtobin=cv2.threshold(image,250,255,cv2.THRESH_BINARY)
#RGB TO HSV
hsv=cv2.cvtColor(image,cv2.COLOR_RGB2HSV)
#HSV TO RGB
hsvtorgb=cv2.cvtColor(hsv,cv2.COLOR_HSV2RGB)
#RGB TO YCrCb
rcb=cv2.cvtColor(image,cv2.COLOR_BGR2YCR_CB)
#YCrCb TO RGB
rcbtorgb=cv2.cvtColor(rcb,cv2.COLOR_YCrCb2RGB)
#DISPLAY IMAGES
cv2.imshow("RGB To Gray Image",gray)
cv2.imshow("RGB To HSV Image",hsv)
cv2.imshow("RGB To YCbCr Image",rcb)
cv2.imshow("HSV To RGB Image",hsvtorgb)
cv2.imshow("YCrCb To RGB Image",rcbtorgb)
cv2.imshow("GRAY TO BINARY",graytobin)
cv2.imshow("RGB TO BINARY",rgbtobin)
cv2.waitKey(0)
cv2.destroyAllWindows()
