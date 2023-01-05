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
echo "To perform linear search in a list of numbers"
echo -n "Enter array elements: "
read -a arr
flag=0
usrnum=${#arr[@]}
if [ $usrnum = 0 ]
then
	echo "Invalid Input, There must be atleast 1 element"
	exit 1
fi
echo "Entered Elements: ${arr[*]}"
read -p 'Enter the number to be searched: ' key
lin_search $usrnum $key

if (($flag == 1))
then
	echo "Element $key found at position $(($pos+1))"
else
	echo "Element $key not found in the list"
fi
