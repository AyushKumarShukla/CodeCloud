
get_array()
{
	for((i=0;i<$1;i++))
	do
		read val;
		arr[$i]=$val
	done
}

bubble_sort()
{
	for((i=0;i<$1;i++))
	do
		for((j=0;j<$1;j++))
		do
			if [[ ${arr[$j]} -gt ${arr[$j+1]} ]]
			then
				temp=${arr[$j]};
				arr[$j]=${arr[$j+1]};
				arr[$j+1]=$temp;
			fi
		done
		echo "Pass $((i+1)): ${arr[*]}"
	done
}
echo "To sort an array using bubble sort:  "
read -p 'Enter the number of elements needed: ' size
get_array $size
echo "Entered Array: ${arr[*]}"
bubble_sort $size
echo "AFTER SORTING: ${arr[*]}"
