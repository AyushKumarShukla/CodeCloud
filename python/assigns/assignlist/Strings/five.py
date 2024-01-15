def noVowels(seq):
    newseq=seq
    for char in seq:
        if char in "aeiouAEIOU":
            newseq=newseq.replace(char,'')

    return newseq
       
seq = input("Enter a string: ")
out = noVowels(seq)
print(out)
