//Multithreading 

class T1 extends Thread // first thread
{
    public void run()
    {
        System.out.println("STARTED T1");
        for(int i=1;i>0;i++)
        {
            System.out.format("i:%d\n",i);
        }
        System.out.println("End Of T1");
    }

}
class T2 extends Thread //second thead
{
    public void run()
    {
        System.out.println("STARTED T2");
        for(int j=1;j>0;j++)
        {
            System.out.format("j:%d\n",j);
        }
        System.out.println("End Of T2");
    }
}
class T3 extends Thread //third thread
{
    public void run()
    {
        System.out.println("STARTED T3");
        for(int k=1;k>0;k++)
        {
            System.out.format("k:%d\n",k);
        }
        System.out.println("End Of T3");
    }
}
class Driver
{
    public static void main(String args[])
    {
        T1 first = new T1(); //newborn states
        T2 second = new T2();
        T3 third = new T3();
        // The decision of running a runnable from the queue is in the hands of the scheduler and not under the
        // control of the programmer, no pattern can be guaranteed
        first.start(); //push first thread to runnable state
        second.start(); // push second thread to runnable state
        third.start(); // push third thread to runnable state
        System.out.println("End Main Thread");
    }
}
