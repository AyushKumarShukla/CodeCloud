echo "To perfom linear search in a list of numbers"
read -p 'Enter the number of elements needed in the list: ' usrnum
echo "Enter $usrnum Elements: "

flag=0

for((i=0;i<$usrnum;i++))
{
	read temp;
	arr[$i]=$temp
}
echo "Entered Elements: ${arr[*]}"
read -p 'Enter the number to be searched: ' key
for((i=0;i<$usrnum;i++))
{
	if((`echo "${arr[$i]} == $key" | bc -l`))
	then
		flag=1
		pos=$i
	fi
}
if (($flag == 1))
then
	echo "Element $key found at position $(($pos+1))"
else
	echo "Element $key not found in the list"
fi
