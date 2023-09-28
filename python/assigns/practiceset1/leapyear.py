#program to check if a given year is a leap year or not

def is_leap_year(year):
	if (year%4==0 and year%100!=0) or (year%400==0):
		return True;
	else:
		return False;



year=int(input("Enter a year: "))
res=is_leap_year(year)
print(f"{year} is leap year: {res}")

"""
SET 1:
Enter a year: 2000
2000 is leap year: True
SET 2:
Enter a year: 2023
2023 is leap year: False
"""
