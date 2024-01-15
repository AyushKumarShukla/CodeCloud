import sys
words = list(sys.argv[1:])
even=""
odd=""

for i in range(0,len(words),2):
    even += words[i] + " "
for i in range(1,len(words),2):
    odd += words[i] + " "

print(even)
print(odd)
