import cv2 as cv
import time
import sys
#arg1: image object, arg2: 1 degree to angle degree rotation per key press with 1 degree step
def spin(image,angle):
	for angle in range(1,angle+1): 
		rotation_mat=cv.getRotationMatrix2D(center,angle,1.0)
		rotated_image=cv.warpAffine(image,rotation_mat,(width,height))
		cv.imshow("Rotated Image",rotated_image)
		cv.waitKey(1)
	return
#driver code
image_path=sys.argv[1] #name of image
spin_amount=int(sys.argv[2]) #angle upto which rotation to be done
image=cv.imread(image_path)
cv.imshow("Input Image",image)
image=cv.resize(image,(900,900))
height,width=image.shape[:2]
center=(width//2,height//2)
spin(image,spin_amount)
cv.destroyAllWindows()
