echo "To print a list of numbers: "
read -p 'Enter the number of elements needed: ' num
IFS=' '
for ((i=0;i<$num;i++))
do
	read temp;
	arr[$i]=$temp;
done
echo "Elements: ${arr[*]}"
echo "${arr[*]}" | sort
