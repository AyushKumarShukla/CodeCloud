
class ObjCount
{
    //this variable is not specific to any object, but belongs to the class itself as it is static
    static int cnt=0;
    ObjCount()
    {
        System.out.println("Constructor Called: Object Created");
        cnt += 1;
    }
    static
    {
        System.out.println("Executed before object creation");
    }
    //method is static as it returns a static variable and is not specific to any object
    static int getObjectCount()
    {
        return cnt;
    }
}

class Driver
{
    static
    {
        System.out.println("Executed Before Entering main method");
    }
    public static void main(String args[])
    {
        ObjCount ref1 = new ObjCount();
        ObjCount ref2 = new ObjCount();
        ObjCount ref3 = new ObjCount();
        ObjCount ref4 = new ObjCount();
        ObjCount ref5 = new ObjCount();
        System.out.format("No. of objects created: %d\n",ObjCount.getObjectCount());
    }
}
