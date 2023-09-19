import cv2 as cv
import time
#arg1: image object, arg2: 1 degree to angle degree rotation per key press with 1 degree step
def spin(image,angle):
	for angle in range(1,angle+1): 
		rotation_mat=cv.getRotationMatrix2D(center,angle,1.0)
		rotated_image=cv.warpAffine(image,rotation_mat,(width,height))
		cv.imshow("Rotated Image",rotated_image)
		cv.waitKey(1)
	return
#driver code
image=cv.imread("ref.jpg")
cv.imshow("Input Image",image)
image=cv.resize(image,(900,900))
height,width=image.shape[:2]
center=(width//2,height//2)
spin(image,360)
cv.destroyAllWindows()
