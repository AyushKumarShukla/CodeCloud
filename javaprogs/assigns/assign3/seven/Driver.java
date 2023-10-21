import java.util.Scanner;
class Account
{
    String cust_name;
    int acc_no;
    String type;
    double balance=0;
    int pin;
    Account(String name,int no,String type,int pin)
    {
        this.cust_name=name;
        this.acc_no=no;
        this.type=type;
        this.pin=pin;
    }
    String desc()
    {
        String res="CUST_NAME: "+cust_name+" "+"ACC_NO: "+acc_no+" "+"TYPE: "+type+" "+"BAL: "+balance+"\n";
        return res;
    }
    //empty definition; the subclasses that need this method will override it, whereas the ones that don't
    //will not,in which case, when called, nothing will happen
    /*This is being done so that the 'Account' reference is able to access member methods of the subclasses
    ---The superclass must atleast declare if doesnt define to have right over the members of the subclasses*/
    void interest(double time)
    {
        
    }
    void deposit(double amount)
    {
        balance+=amount;
        System.out.format("Amount %.2f credited successfully to account no: %d\n",amount,acc_no);
    }
    void withdraw(double amount)
    {
        if(balance<amount)
            System.out.println("Insufficient Funds To Withdraw");
        else
        {
            balance-=amount;
            System.out.format("Amount Withdrawn: %.2f from account no: %d\n",amount,acc_no);
        }
    }
    void balance()
    {
            System.out.format("Balance: %f in account no: %d\n",balance,acc_no);
    }
}
class SavingsAccount extends Account
{  
    double principal,rate;
    
    SavingsAccount(String cust_name,int acc_no,String type,int pin,double principal,double rate)
    {
        super(cust_name,acc_no,type,pin);
        this.principal=principal;
        this.rate=rate;
    }
    void interest(double time)
    {
        if(this.principal<5000)
            System.out.println("Insufficient principal for interest");
        else
        {
            double interest=(principal*rate*time*0.01);
            this.principal+=interest;
            System.out.format("Interest For %.2f years = %.2f, New Principal = %.2f\n",time,interest,principal);
        }
    }
}
class CurrentAccount extends Account
{
    double penalty;
    CurrentAccount(String cust_name,int acc_no,String type,int pin,double penalty)
    {
        super(cust_name,acc_no,type,pin);
        this.penalty=penalty;
    }
    void checkBal()
    {
        if(balance != 0 && balance < 1000)
        {
            balance -= penalty;
            System.out.format("An amount of Rs 100 has been deducted for low balance\n");
            System.out.format("Remaining Balance: %.2f \n",balance);
        }
    }
    void withdraw(double amount)
    {
        if(balance<amount)
            System.out.println("Insufficient Funds To Withdraw");
        else
        {
            balance-=amount;
            System.out.format("DERIEVED CALL:Amount Withdrawn: %.2f from account no: %d\n",amount,acc_no);
            checkBal();
        }
    }
}
class Driver
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        /*Creates an array of reference variables of type Account - mind it - type "Account"*/
        Account users[] = new Account[10];
        users[0] = new Account("Ayush Kumar Shukla",15245658,"Savings",0);
        users[1] = new CurrentAccount("Aryan Shukla",11223344,"Current",1,100);
        users[2] = new SavingsAccount("Rahul Shukla",99887766,"Savings",2,10000,5);
        System.out.println("\t****WELCOME TO DELTA BANK****\t");
        System.out.println("Enter your pin: ");
        int pin = scan.nextInt();
        int ch=0;
        System.out.println(users[pin].desc());
        while(ch!=5)
        {
            System.out.println("MENU: ");
            System.out.format("1. DEPOSIT\n2. CHECK BALANCE\n3. WITHDRAW\n4. GET INTEREST\n5. EXIT\n");
            System.out.println("Enter Your Choice: ");
            ch = scan.nextInt();
            switch(ch)
            {
                case 1:
                    System.out.println("Enter the amount to be deposited: \n");
                    double amt1 = scan.nextDouble();
                    users[pin].deposit(amt1);
                    break;
                case 2:
                    users[pin].balance();
                    break;
                case 3:
                    System.out.println("Enter the amount to be withdrawn: \n");
                    double amt2 = scan.nextDouble();
                    users[pin].withdraw(amt2);
                    break;
                case 4:
                    System.out.print("Enter time period: ");
                    double time_elap = scan.nextInt();
                    users[pin].interest(time_elap);
                    break;
                case 5:
                    System.exit(0);
            }
        }
       /* acc.deposit(1000);
        acc.balance();
        sacc.interest(5);
        cacc.deposit(5000);
        cacc.withdraw(4500);*/
       } 
}
