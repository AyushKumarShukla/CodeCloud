items = [1,2,1,2,4,5,4,8,8,88,8,9,2,3,4,7,7,2]
uniques = []

for item in items:
	if item not in uniques:
		uniques.append(item)
print(uniques)