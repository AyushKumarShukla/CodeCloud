class Thread1 implements Runnable

{
	public void run()
	{
		System.out.println("Thread1 Started");
		for(int i=1;i<101;i++)
			System.out.format("i: %d\n",i);
		System.out.println("Thread1 Terminated");
	}
}

class Thread2 implements Runnable
{
        public void run()
        {
		System.out.println("Thread2 Started");
                for(int j=1;j<101;j++)
                        System.out.format("j: %d\n",j);
		System.out.println("Thread2 Terminated");
        }
}

class Thread3 implements Runnable
{
        public void run()
        {
		System.out.println("Thread3 Started");
                for(int k=1;k<101;k++)
                        System.out.format("k: %d\n",k);
		System.out.println("Thread3 Terminated");
        }
}
class Driver
{
	public static void main(String args[])
	{
		Thread1 t1 = new Thread1();
		Thread2 t2 = new Thread2();
		Thread3 t3 = new Thread3();
		//newborn threads
		Thread one = new Thread(t1);
		Thread two = new Thread(t2);
		Thread three = new Thread(t3);
		//Pushing threads to runnable state
		three.setPriority(10);
		two.setPriority(5);
		one.setPriority(1);
		System.out.println(one.getPriority());
		System.out.println(two.getPriority());
		System.out.println(three.getPriority());
		one.start();
		three.start();
		two.start();
	}
}

