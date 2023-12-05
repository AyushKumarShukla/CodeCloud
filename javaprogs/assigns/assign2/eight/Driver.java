import java.util.Scanner;
class Subject
{
	String title;
	int internal;
	int theory;

	Subject(String a,int b,int c)
	{
		title = a;
		internal = b;
		theory = c;
	}
}
class Student
{
	int roll;
	String name;
	String stream;
	String college;
	int num;
	Subject subs[] = new Subject[10];
	Scanner sc = new Scanner(System.in);
	Student(int a,String b,String c,String d)
	{
		this.roll = a;	
		this.name = b;	
		this.stream = c;	
		this.college = d;
	}
	void studentInfo()
	{
		System.out.println("\n\nStudent Details");
		System.out.format("Roll: %d\nName: %s\nStream: %s\nCollege: %s",roll,name,stream,college);
	}
	void setSubjects()
	{
		System.out.format("\nEnter the number of subjects taken by %s\n",this.name);
		this.num = sc.nextInt(); 
		for(int i=0;i<num;i++)
		{
			System.out.println("Enter Title");
			sc.nextLine(); // to collect wild newline
			String title = sc.nextLine();
			System.out.println("Enter Internal Marks:");
			int internal = sc.nextInt();
			System.out.println("Enter Theory Marks:");
			int theory = sc.nextInt();
			this.subs[i] = new Subject(title,internal,theory);
		}
	}

	void subjectInfo()
	{
		System.out.format("Subject Details for %s:\n",this.name);
		for(int i=0;i<num;i++)
		{
			System.out.format("\nTitle: %s\n",subs[i].title);
			System.out.format("Internal Marks: %d\n",subs[i].internal);
			System.out.format("Theory Marks: %d\n",subs[i].theory);
		}
	}

}

class Driver
{
	public static void main(String args[])
	{
		Student ayush = new Student(1089,"Ayush Kumar Shukla","Science","Bidhan Chandra College");
		Student pritam = new Student(1082,"Pritam Dey","Commerce","IIT Kanpur");
		ayush.studentInfo();
		pritam.studentInfo();
		ayush.setSubjects();
		ayush.subjectInfo();
		pritam.setSubjects();
		ayush.subjectInfo();
		pritam.subjectInfo();	
		System.out.println();
	}
}
