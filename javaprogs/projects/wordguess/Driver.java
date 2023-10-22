import java.util.Scanner;
import java.util.Random;
class StringMan
{
    static StringBuffer dashString(int length)
    {
        if(length<1)
            return null;
        else
        {
            StringBuffer res = new StringBuffer("");;
            for(int i=0;i<length;i++)
                res.append("-");
            return res;
        }
    }
    static void askWord(String secret,int counter)
    {
        int length = secret.length();
        secret=secret.toLowerCase();
        StringBuffer state = StringMan.dashString(length);
        System.out.println("Guess: "+state);
        while(true)
        {
            System.out.print("Guess a word: ");
            Scanner scan = new Scanner(System.in);
            String guess = scan.nextLine();
            if(!(guess.equals("")))
            {
                guess=guess.toLowerCase();
                guess=guess.trim();
            }
            else
                guess=" ";
            if(secret.indexOf(guess) != -1) //HIT
                {
                    for(int i=0;i<length;i++) //0 or -1 ?
                    {
                        int index=secret.indexOf(guess,i);
                        if(index != -1)
                            state.setCharAt(index,secret.charAt(index));
                        else
                            break;
                    }
                }
            else
                {
                    System.out.println("MISS");
                    counter-=1;
                    if(counter == 0)
                    {
                        System.out.println("Game Over");
                        System.out.println("Secret Word Was: "+secret);
                        System.exit(1);
                    }
                    
                }
            System.out.println(state);
            if(secret.equalsIgnoreCase(state.toString()) && !(state.equals("")))
            {
                System.out.println("YOU WON!");
                System.exit(2);
            }
        }
    }
}

class Driver
{
    public static void main(String args[])
    {
        System.out.println("********** WELCOME TO WORDGUESSER!**********");
        Random rand = new Random();
        String[] words = {  "apple", "banana", "cat", "dog", "house", "family", "friend", "car", 
                            "book", "movie", "music", "beach", "vacation", "coffee", "school", 
                            "work", "pizza", "chocolate", "hobby", "guitar", "flower", "summer", 
                            "computer", "phone", "television", "shoes", "jacket", "hat", 
                            "sunglasses", "shopping", "restaurant", "exercise", "holiday", 
                            "party", "weekend", "library", "ocean", "park", "friendship", 
                            "adventure", "sunset", "laughter", "smile"};
        int random_num = rand.nextInt(43);
        String secret = words[random_num];    
        int len = secret.length();
        int counter=5;
        StringMan.askWord(secret,counter);
    }
}
