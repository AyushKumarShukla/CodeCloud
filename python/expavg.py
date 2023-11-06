import random
prevprediction = 5
a = 0.8
while True:
    value = int(input("Enter the value: "))
    error = value - prevprediction;
    print("Error: ",error);
    newprediction = a*value + (1-a)*prevprediction
    print(newprediction)
    prevprediction=newprediction
