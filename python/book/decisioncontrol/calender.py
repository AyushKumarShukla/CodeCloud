"""
WRITE A PYTHON PROGRAM TO PRINT THE CALENDER OF A MONTH GIVEN:
START DAY(1-7):SUN=1,MON=2,TUE=3,WED=4,THU=5,FRI=6,SAT=7
NO. OF DAYS IN THE MONTH
"""

def valid_input(start_date,days):
	valid=True
	if start_day not in range(1,8):
		print("Invalid start date")
		valid=False
	if days not in (28,29,30,31):
		print("Invalid number of days");
		valid=False
	return valid

start_day=int(input("Enter the start date of the month(1-7): "))
days=int(input("Enter the number of days in the month: "))

if(valid_input(start_day,days)):
	print("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n")
	for i in range(start_day-1):
		print("\t",end="")
	i=start_day-1
	for j in range(1,days+1):
		if(i>6):
			print()
			i=1
		else:
			i+=1
		print(j,"\t",end="")
	print()


