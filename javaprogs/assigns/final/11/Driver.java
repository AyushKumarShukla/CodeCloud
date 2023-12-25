import java.util.*;
class Subject
{
    String title;
    int marks;
    Subject(String title,int marks)
    {
        this.title = title;
        this.marks = marks;
    }

    void showSubjectInfo()
    {
        System.out.format("Title:%s, marks:%d\n",title,marks);
    }

    int getMarks()
    {
        return this.marks;
    }
}

class Student
{
    String name;
    String stream;
    int roll;
    Subject arr[];
    Student(String name,String stream,int roll)
    {
        this.name = name;
        this.stream = stream;
        this.roll = roll;
        this.arr = arr;
    }
    double calcAvg()
    {
        double sum = arr[0].getMarks()+arr[1].getMarks()+arr[2].getMarks();
        double avg = sum/300.0;
        return avg*100;
    }
    void showStudentInfo()
    {
        System.out.println("Name: "+name);
        System.out.println("Stream: "+stream);
        System.out.format("Roll Number: %d",roll);
    }
    void setMarks(Subject arr[])
    {
        this.arr = arr;
    }
    void showStudentPerformanceInfo()
    {
        for(int i=0;i<3;i++)
        {
            System.out.format("\nSubject %d Details:\n",i+1);
            arr[i].showSubjectInfo();
        }
        System.out.format("Average Marks: %f\n",calcAvg());
    }

}

class Driver
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        Student students[] = new Student[30];
        int cnt = 0,index;
        while(true)
        {
            System.out.format("\nMENU:\n1.Admit New Student\n2.Set Student Marks\n3.Get Student Info\n4.Get Student Performance\n5.Exit\n");
            System.out.print("Enter Your Choice: ");
            switch(sc.nextInt())
            {
                case 1:
                    students[cnt]= newAdmit(cnt);
                    cnt += 1;
                    break;
                case 2:
                    System.out.print("Enter Roll No: ");
                    index = sc.nextInt();
                    inputMarks(students[index]);
                    break;
                case 3:
                    System.out.print("Enter Roll No: ");
                    index = sc.nextInt();
                    students[index].showStudentInfo();
                    break;
                case 4:
                    System.out.print("Enter Roll No: ");
                    index = sc.nextInt();
                    students[index].showStudentPerformanceInfo();
                    break;
                case 5:
                    System.exit(0);
                    break;
            }

        }
    }

    static Student newAdmit(int count)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name: ");
        String name = sc.nextLine();
        System.out.println("Enter Stream: ");
        String stream = sc.nextLine();
        Student s = new Student(name,stream,count);
        System.out.format("Roll Number Of %s of stream %s is: %d",name,stream,count);
        return s;
    }

    static void inputMarks(Student obj)
    {
        Scanner sc = new Scanner(System.in);
        Subject arr[] = new Subject[3];
        for(int i=0;i<3;i++)
        {
            System.out.format("Enter Title of Subject %d: ",i);
            String title = sc.nextLine();
            System.out.format("Enter Theory Marks of Subject %d: ",i);
            int marks = sc.nextInt();
            sc.nextLine();
            arr[i] = new Subject(title,marks);
        }
        obj.setMarks(arr);
    }
}
