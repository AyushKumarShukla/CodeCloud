#ISSUE: image color changes when displayed in subplot
import cv2 as cv
import matplotlib.pyplot as plt
image=cv.imread("newtring.jpeg",cv.COLOR_BGR2RGB)
height,width=image.shape[:2]
center=(width//2,height//2)
angle=float(input("Enter angle of rotation: "))
#gets the rotation matrix for scaled rotation with adjustable center of rotation
rotation_mat=cv.getRotationMatrix2D(center,angle,1.0)
#performs an affine transformation based upon the supplied matrix
rotated_image=cv.warpAffine(image,rotation_mat,(width,height))

fig,axs = plt.subplots(1,2,figsize=(30,30))

axs[0].imshow(image)
axs[0].set_title("Input Image");
axs[1].imshow(rotated_image)
axs[1].set_title("Rotated Image");

plt.show()
cv.waitKey(0)
cv.destroyAllWindows()
