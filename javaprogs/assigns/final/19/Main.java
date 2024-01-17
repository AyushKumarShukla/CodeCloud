class Outer
{
    private int outer_var = 123;
    class Inner
    {
        int inner_var = 1089;

        void printOuterVars()
        {
            //Access of outer class members from inner class without requiring any object
            System.out.format("FROM INNER CLASS: WITHOUT OUTER CLASS OBJECT OUTER_VAR: %d\n",outer_var);
        }
    }

    void printInnerVars()
    {
        //this object is required to access the members of the inner class
        Inner innerobj = new Inner();
        System.out.format("FROM OUTER CLASS: THROUGH INNER CLASS OBJECT: INNER VAR: %d\n",innerobj.inner_var);
    }
}
class Main
{
    public static void main(String args[])
    {
        Outer out = new Outer();
        //the inner class object must be instantiated with respect to a outer class object
        //Outerclass.Innerclass is the fully qualified name for locating the class
        Outer.Inner in = out.new Inner();
        out.printInnerVars();
        in.printOuterVars();
    }

}
