import cv2

image=cv2.imread("ref.jpg")
image=cv2.rotate(image,cv2.ROTATE_180)
cv2.imshow("Input Image",image)
cv2.waitKey(0)
cv2.destroyAllWindows()
