class Account
{
    String cust_name;
    int acc_no;
    String type;
    double balance=0;
    
    Account(String name,int no,String type)
    {
        this.cust_name=name;
        this.acc_no=no;
        this.type=type;
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
    
    SavingsAccount(String cust_name,int acc_no,String type,double principal,double rate)
    {
        super(cust_name,acc_no,type);
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
    CurrentAccount(String cust_name,int acc_no,String type,double penalty)
    {
        super(cust_name,acc_no,type);
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
            System.out.format("Amount Withdrawn: %.2f from account no: %d\n",amount,acc_no);
            checkBal();
        }
    }
}
class Driver
{
    public static void main(String args[])
    {
        Account acc = new Account("Ayush Kumar Shukla",15245658,"Savings");
        SavingsAccount sacc = new SavingsAccount("Aryan Shukla",11223344,"Savings",15000,2.5);
        CurrentAccount cacc = new CurrentAccount("Rahul Shukla",99887766,"Current",100);
        acc.deposit(1000);
        acc.balance();
        sacc.interest(5);
        cacc.deposit(5000);
        cacc.withdraw(4500);
    }
}
