get_array()
{
	for((i=0;i<$1;i++))
	{
		read temp;
		arr[$i]=$temp
	}
}
lin_search()
{
	for((i=0;i<$1;i++))
	{
		if((`echo "${arr[$i]} == $2" | bc -l`))
		then
			flag=1
			pos=$i
		fi
	}
}

echo "To perfom linear search in a list of numbers"
read -p 'Enter the number of elements needed in the list: ' usrnum
if (($usrnum < 1 ))
then
	echo "Invalid list size , the size of the list must be atleast 1"
	exit 1 
fi


echo "Enter $usrnum Elements: "
flag=0
get_array $usrnum

echo "Entered Elements: ${arr[*]}"
read -p 'Enter the number to be searched: ' key
lin_search $usrnum $key

if (($flag == 1))
then
	echo "Element $key found at position $(($pos+1))"
else
	echo "Element $key not found in the list"
fi
