import cv2

image = cv2.imshow("ref.jpg",0)
c = 55
output = c * image ** gamma
cv2.imshow("Transformed Image",output);
cv2.waitKey(0)
cv2.destroyAllWindows()
