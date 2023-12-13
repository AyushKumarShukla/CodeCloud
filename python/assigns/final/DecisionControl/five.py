import random
def gameLoop(start,stop,chances):
    secret = random.randrange(start,stop+1) ## [1,10]
    print(f"A secret number between {start} and {stop} has been selected")
    while True:
        print(f"You have {chances} chance(s) remaining")
        guess = int(input("Guess the secret number: "))
        if guess == secret:
            print("You Win !")
            break
        else:
            chances -= 1
            if chances == 0:
                print("You Lose")
                print(f"The secret number was {secret}")
                break
        if guess > secret:
            print("Go lower")
        else:
            print("Go higher")


chances = 10
start = 1
stop = 100
print("\t\tWELCOME TO NUMBER GUESSER\t\t")
gameLoop(start,stop,chances)

