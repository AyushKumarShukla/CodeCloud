import numpy as np
import cv2

cap = cv2.VideoCapture(0)
while True:
	ret, frame=cap.read()
	gray_frame=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
	cv2.imshow("GRAY VID",gray_frame)
	if cv2.waitKey(1)==ord("s"):
		break
cap.release()
cv2.destroyAllWindows()