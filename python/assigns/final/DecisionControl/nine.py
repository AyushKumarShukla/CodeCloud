def hollowStar(lines):
    for i in range(0,lines):
        if i==0 or i==lines-1:
            print("*"*lines)
        else:
            print("*" , " "*(lines-2) , "*",sep="")



num = int(input("Enter the number of lines: "))
hollowStar(num)
