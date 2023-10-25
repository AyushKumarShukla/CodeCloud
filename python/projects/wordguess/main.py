#word guesser game

def get_dashed_string(len):
    res=[]
    for i in range(len):
        res.append("-")
    return res

def game_loop(secret,chances):
    length=len(secret)
    emp=""
    state=get_dashed_string(length)
    while(chances!=0):
        print(f"Word: {emp.join(state)}")
        if emp.join(state)==secret:
            return True
        guess=input("Guess: ")
        hit=False
        for index,char in enumerate(secret):
            if char == guess:
                hit=True
                state[index]=char
        if not hit:
            chances-=1
    return False
words = {"apple","banana","cat","dog", "house", "family", "friend", "car", 
         "book", "movie", "music", "beach", "vacation", "coffee", "school", 
         "work", "pizza", "chocolate", "hobby", "guitar", "flower", "summer", 
         "computer", "phone", "television", "shoes", "jacket", "hat", 
         "sunglasses", "shopping", "restaurant", "exercise", "holiday", 
         "party", "weekend", "library", "ocean", "park", "friendship", 
         "adventure", "sunset", "laughter", "smile"};
secret=words.pop()
chances=5
win=game_loop(secret,chances)
if(win):
    print("You Won!")
else:
    print("You Lose!")
    print("Secret word: ",secret)
