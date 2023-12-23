import java.util.Arrays;
class NumList
{
    int[] list;

    NumList(int...values)
    {
        list=new int[values.length];
        int k=0;
        for(int value:values)
        {
            list[k]=value;
            k++;
        }
        Arrays.sort(list);
    }

    void display()
    {
        for(int i:list)
        {
            System.out.format("%d\t",i);
        }
        System.out.println();

    }

    int find(int key)
    {
        int left=0;
        int right=(list.length-1);
        int mid,loc=-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(list[mid]==key)
            {
                loc=mid;
                break;
            }
            else if(list[mid]>key)
                right=mid-1;
            else
                left=mid+1;
        }
        return loc;
    }
}

class Driver
{
    public static void main(String[] args)
    {
        NumList list1 = new NumList(7,5,6,4,3,2,4);
        list1.display();
        int ret=list1.find(3);
        System.out.println( (ret!=-1) ? "Element At Location: "+(ret+1) : "Not Found");
    }
}
