import cv2
image=cv2.imread("ref.jpg",0)#read image in grayscale
cv2.imshow("MISTY MOUNTAINS COLD",image)
key=cv2.waitKey(0)#read keyboard input
if key==27: # if ESC is pressed
	pass 
elif key==ord("s"): #if s is pressed
	cv2.imwrite("grayscalemounts.png",image) #save grayscale image
cv2.destroyAllWindows()
