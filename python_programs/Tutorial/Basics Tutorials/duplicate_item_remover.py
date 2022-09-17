items= ["a","a","b","c"] 
items.sort()

for item in items:
	while items.count(item)!=1:
		items.remove(item)

print(items)