class one
{
    int x;
    int y;
    one(int a,int b)
    {
        this.x=a;
        this.y=b;
    }
    void display_one()
    {
        System.out.println("FROM CLASS ONE:\t"+this.x+" "+this.y);
    }
}
class two extends one
{
    int x;
    int y;
    two(int a,int b,int c,int d)
    {
        super(a,b);
        this.x=c;
        this.y=d;
    }
    void display_two()
    {
        display_one();
        System.out.println("FROM CLASS TWO:\t"+this.x+" "+this.y);
    }
}
class three extends two
{
    int x;
    int y;
    three(int a,int b,int c,int d,int e,int f)
    {
        super(a,b,c,d);
        this.x=e;
        this.y=f;
    }
    void display_three()
    {
        display_two();
        System.out.println("FROM CLASS THREE:"+this.x+" "+this.y);
    }
}

class inherlecture{
    public static void main(String args[])
    {
        int a=Integer.parseInt(args[0]);
        int b=Integer.parseInt(args[1]);
        int c=Integer.parseInt(args[2]);
        int d=Integer.parseInt(args[3]);
        int e=Integer.parseInt(args[4]);
        int f=Integer.parseInt(args[5]);
        /*The class "three" inherits class "two" which again inherits class "one":
        due to this the memory allocation for the object of class "three" will
        contain space for the members variables defined in all the classes -
        "one", "two" and "three". Also, this object will have access to all the
        member methods defined in all the classes*/
        three obj=new three(a,b,c,d,e,f);
        obj.display_three();
    }
}
