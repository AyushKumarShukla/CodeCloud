first = ["Ayush","Aryan","Rahul","Rishabh","Ram"]
last = ["Shukla","Pandey","Das","Maiti","Dubey"]

full = list(zip(first,last))
full_string = []
for tup in full:
    full_string.append(' '.join(tup))     
print(full_string)
