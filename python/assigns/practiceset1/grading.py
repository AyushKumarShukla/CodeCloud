"""Program to implement grading system"""
def get_grade(marks):

	if marks>89 and marks<=100:
		print("GRADE: A")
	elif marks>69 and marks<90:
		print("GRADE: B")
	elif marks>49 and marks<70:
		print("GRADE: C")
	elif marks>29 and marks<50:
		print("GRADE: D")
	elif marks>=0 and marks<30:
		print("GRADE: F")
	else: #block for input validation
		print("Invalid Input: Retry")
		
marks=float(input("Enter marks obtained out of 100: "))
get_grade(marks)

"""
OUTPUT:
SET 1:
Enter marks obtained out of 100: 95
GRADE: A
SET 2:
Enter marks obtained out of 100: 85
GRADE: B
SET 3:
Enter marks obtained out of 100: 72
GRADE: C
SET 4:
Enter marks obtained out of 100: 44
GRADE: D
SET 5:
Enter marks obtained out of 100: 15
GRADE: F
"""



