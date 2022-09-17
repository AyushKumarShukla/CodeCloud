while True:
	number = int(input(":"))
	for i in range(2,number):
		if number%i == 0:
			prime = False
		else:
			prime = True
		break
	if prime:
		print(f"{number} is prime")
	elif type(number) == float:
		print(f"{number} is not prime")
	else:
		print(f"{number} is not prime")








