bubble_sort()
{
	k=0
	for((i=0;i<$1;i++))
	do
		for((j=0;j<$(($1-1-i));j++))
		do
			if [[ ${arr[$j]} -gt ${arr[$j+1]} ]]
			then
				temp="${arr[$j]}";
				arr[$j]="${arr[$j+1]}";
				arr[$j+1]="$temp";
			fi
			echo -e "Pass $((k+1)): ${arr[*]}"
			k=$((k+1))
		done
	done
}
echo "To sort an array using bubble sort:  "
echo -n "Enter the elements of the list: "
read -a arr
size=${#arr[@]}
if [ $size -le 0 ]
then
	echo "Invalid input, there must be atleast one entry"
	exit 1
fi
echo "Entered Array: ${arr[*]}"
bubble_sort $size
echo "AFTER SORTING: ${arr[*]}"
