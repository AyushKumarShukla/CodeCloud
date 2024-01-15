even=""
odd=""
with open("words.txt","r") as file:
    #empty word string
    words = []
    #get each line into the string
    for line in file:
        words = line.split()
    #group even positioned words
    for i in range(0,len(words),2):
        even += words[i] + " "
    #group odd positioned words
    for i in range(1,len(words),2):
        odd += words[i] + " "

print(even)
print(odd)
