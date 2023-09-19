import cv2 as cv

image=cv.imread("ref.jpg")
cv.imshow("Input Image",image)
height,width=image.shape[:2]
center=(width//2,height//2)
angle=float(input("Enter angle of rotation: "))
#gets the rotation matrix for scaled rotation with adjustable center of rotation
rotation_mat=cv.getRotationMatrix2D(center,angle,1.0)
#performs an affine transformation based upon the supplied matrix
rotated_image=cv.warpAffine(image,rotation_mat,(width,height))
cv.imshow("Rotated Image",rotated_image)
cv.waitKey(0)
cv.destroyAllWindows()
