"""
to calculate the distance between two points using distance formula
"""

p1=input("Enter the x and y coordinates of the first point: ");
p1=p1.split()
p2=input("Enter the x and y coordinates of the second point: ");
p2=p2.split()
x1=float(p1[0])
y1=float(p1[1])
x2=float(p2[0])
y2=float(p2[1])
d=((x2-x1)**2+(y2-y1)**2)**0.5
print("Distance between the points:",d)

