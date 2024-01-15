import sys
def push(stack,item):
    stack.insert(0,item)

def pop(stack):
    stack.pop(0)

def full(stack):
    return len(stack)==size

def empty(stack):
    return len(stack)==0

def disp(stack):
    for val in stack:
        print(val)

size=int(sys.argv[1])
stack = []

while True:
    print("MENU:\n1.PUSH INTO STACK\n2.POP FROM STACK\n3.EXIT\n")
    print("STACK STATE:")
    if not empty(stack):
        disp(stack)
    else:
        print("Empty")
    ch = int(input("Enter Your Choice: "))
    if ch==1:
        if not full(stack):
            val=int(input("Enter Value To Push: "))
            push(stack,val);
        else:
            print("Stack Limit Reached!")
    elif ch==2:
        if not empty(stack):
            pop(stack)
        else:
            print("Stack is already empty!")
    elif ch==3:
        break;
    else:
        print("Invalid Choice")
