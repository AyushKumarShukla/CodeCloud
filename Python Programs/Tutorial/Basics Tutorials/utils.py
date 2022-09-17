def find_max(numbers):
	maxnum = numbers[0]
	for number in numbers:
		if number>maxnum:
			maxnum = number
	return maxnum
