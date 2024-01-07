import java.util.ArrayList;
import java.util.Scanner;
class BankAccount
{
    String name;
    String address;
    int acc_no;
    double balance;
    private static int acc_no_seed=7711;
    private static int no_of_acc = 0;
    BankAccount(String name,String addr)
    {
        this.name=name;
        this.address=addr;
        acc_no=setAccountNumber();
        balance=1000;
    }

    void withdraw(double amt)
    {
        if(amt>balance)
            System.out.println("Insufficient Funds");
        else
        {
            balance -= amt;
            System.out.format("An amount of Rupees %.2f has been debited successfully\nCurrent Balance: %.2f\n",amt,balance);
            if(balance<1000)
                System.out.println("Account balance is below minimum, please keep minimum balance to avoid charges");
        }
    }
    static int getSeed()
    {
        return acc_no_seed;
    }
    void deposit(double amt)
    {
        balance += amt;
        System.out.format("An amount of Rupees %.2f has been credited successfully\nCurrent Balance: %.2f\n",amt,balance);
    }

    void showAccInfo()
    {
        System.out.format("Account Holder's Name: %s\nAddress: %s\nAccount Number: %d\nBalance: %.2f\n",name,address,acc_no,balance);
    }

    private int setAccountNumber()
    {
        int ret=acc_no_seed+no_of_acc;
        no_of_acc += 1;
        return ret;
    }
}

class Driver
{
    static ArrayList<BankAccount> accounts = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);
    public static void main(String args[])
    {
        int index;
        double amt;
        while(true)
        {
            System.out.print("\nMENU:\n1.CREATE ACCOUNT\n2.GET ACCOUNT DETAILS\n3.DEPOSIT\n4.WITHDRAW\n5.DELETE ACCOUNT\n6.EXIT\n");
            System.out.print("Enter Your Choice: ");
            switch(sc.nextInt())
            {
                case 1:
                    sc.nextLine();
                    System.out.print("Enter Full Name: ");
                    String name = sc.nextLine();
                    System.out.print("Enter Communication Address: ");
                    String add = sc.nextLine();
                    BankAccount admit = new BankAccount(name,add);
                    accounts.add(admit);
                    admit.showAccInfo();
                    break;
                case 2:
                    try
                    {
                        index = getIndex();
                        accounts.get(index).showAccInfo();
                    }
                    catch(NullPointerException e)
                    {
                        System.out.println("Account Not Found");
                    }
                    break;
                case 3:
                    try
                    {
                        System.out.print("Enter The Amount To Be Deposited: ");
                        amt = sc.nextDouble();
                        index = getIndex();
                        accounts.get(index).deposit(amt);
                    }
                    catch(NullPointerException e)
                    {
                        System.out.println("Account Not Found");
                    }
                    break;
                case 4:
                    try
                    {
                        System.out.print("Enter the amount to be withdrawn: ");
                        amt = sc.nextDouble();
                        index = getIndex();
                        accounts.get(index).withdraw(amt);
                    }
                    catch(NullPointerException e)
                    {
                        System.out.println("Account Not Found");
                    }
                    break;
                case 5:
                    index = getIndex();
                    accounts.set(index,null);
                    break;
                case 6:
                    System.exit(0);
                    break;
                default:

            }
        }
    }

    static int getIndex()
    {
        System.out.print("Enter Account Number: ");
        int acc = sc.nextInt();
        int index = acc - BankAccount.getSeed();
        return index;
    }
}   
