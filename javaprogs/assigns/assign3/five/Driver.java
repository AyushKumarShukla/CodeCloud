/*Demonstration of Method Overriding*/
class Account //base class which contains the show() method
{
    double balance;
    Account()
    {
    }

    Account(double bal)
    {
        this.balance=bal;
    }
    void show()
    {
        System.out.format("The Available Balance Is: %f\n",balance);
    }
}
class SavingsAccount extends Account //inherits show method from base class
{
    double fixedbalance;
    SavingsAccount()
    {
    }

    SavingsAccount(double bal)
    {
        this.fixedbalance=bal;
    }
    void show()
    {
        System.out.format("The Available Balance For Fixed Account Is: %f\n",fixedbalance);
    }
}
class CreditAccount extends Account
{
    double debt;
    CreditAccount()
    {
    }
    CreditAccount(double loan)
    {
        this.debt=loan;
    }
    void show()
    {
        System.out.format("The Credit Used For This Month Is: %f\n",debt);
    }
}
class LoanAccount extends Account
{
    double rem;
    LoanAccount()
    {
    }

    LoanAccount(double rem)
    {
        this.rem=rem;
    }
    void show()
    {
        System.out.format("The Remaining Loan Amount Is: %f\n",rem);
    }
}

class Driver
{
    public static void main(String args[])
    {
        Account acc = new Account(15000);
        SavingsAccount sacc = new SavingsAccount(4000);
        CreditAccount cacc = new CreditAccount(45000);
        LoanAccount lacc = new LoanAccount(475555.36);
        acc.show();
        sacc.show();
        cacc.show();
        lacc.show();
    }
}
















