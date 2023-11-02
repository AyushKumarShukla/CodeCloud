class Node:
    def __init__(self,val):
        self.val=val
        self.next=None
class LinkedList:
    def __init__(self):
        self.head=None
    def append(self,val):
        if self.head:
            temp=self.head
            while temp.next:
                temp=temp.next
            temp.next=Node(val)
        else:
            self.head=Node(val)
    def pop(self):
        if self.head:
            temp=self.head
            while temp.next.next:
                temp=temp.next
            temp.next=None
        else:
            print("List Empty")
    def pull(self):
        if self.head:
            self.head=self.head.next
        else:
            print("List Empty")
    def delwithval(self,key):
        if self.head:
            temp=self.head
            while temp.next:
                if temp.next.val==key:
                    temp.next=temp.next.next
                temp=temp.next
        else:
            print("List Empty")
                    
    def display(self):
        temp=self.head
        while temp:
            print(temp.val,end=" ")
            temp=temp.next

list1=LinkedList()
while True:
    list1.display()
    ch=int(input("\nEnter Your Choice: \n1.APPEND\n2.POP\n3.PULL\n4.DEL VAL\n5.EXIT\n -->"))
    if ch==1:
        val=int(input("Enter a value"))
        list1.append(val)
    elif ch==2:
        list1.pop()
    elif ch==3:
        list1.pull()
    elif ch==4:
        val=int(input("Enter value to be deleted"))
        list1.delwithval(val)
    elif ch==5:
        break
