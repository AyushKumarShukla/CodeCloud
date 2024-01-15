import sys
def enqueue(queue,item):
    queue.append(item)

def dequeue(queue):
    queue.pop(0)

def full(queue):
    return len(queue)==size

def empty(queue):
    return len(queue)==0

size=int(sys.argv[1])
queue = []

while True:
    print("MENU:\n1.INSERT INTO QUEUE\n2.EXTRACT FROM QUEUE\n3.EXIT\n")
    print("QUEUE STATE:")
    print(queue)
    ch = int(input("Enter Your Choice: "))
    if ch==1:
        if not full(queue):
            val=int(input("Enter Value To Insert: "))
            enqueue(queue,val);
        else:
            print("Queue Limit Reached!")
    elif ch==2:
        if not empty(queue):
            dequeue(queue)
        else:
            print("Queue is already empty!")
    elif ch==3:
        break;
    else:
        print("Invalid Choice")
