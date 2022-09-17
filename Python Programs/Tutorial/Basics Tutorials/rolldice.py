import random

class Dice:
    def roll(self):
        num1 = random.randint(1,6)
        num2 = random.randint(1,6)
        result = (num1,num2)
        return result

dice1 = Dice()
roll1 = dice1.roll()
print(roll1)