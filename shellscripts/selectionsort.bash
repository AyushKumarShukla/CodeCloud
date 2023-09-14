selection_sort()
{
	k=1
	for((i=0;i<$(($1-1));i++))
	do
		minloc=$i
		for((j=$((i+1));j<$1;j++))
		do
			if [ "${arr[$j]}" -lt "${arr[$minloc]}" ]
			then
				minloc="$j"
			fi
		done
		if [ "$minloc" -ne "$i" ]
		then
			temp="${arr[$i]}"
			arr[$i]="${arr[$minloc]}"
			arr[$minloc]="$temp"
		fi
		echo "Pass $k: ${arr[@]}"
		k=$((k+1))
	done
}
echo "To sort a list of integers using selection sort"
echo "Enter the list of integers"
read -a arr
echo -n "Entered Elements: "
echo "${arr[*]}"
len=${#arr[@]}
if [ $len -le 0 ]
then
	echo "Invalid Input, There Must Be Atleast 1 Entry"
	exit 1
fi
selection_sort $len
echo -n "Sorted array: "
echo "${arr[*]}"
