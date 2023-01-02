echo "To sort a list of integers using selection sort"
read -p 'Enter the number of integers needed in the list' len

get_array()
{
	for((i=0;i<$1;i++));
	do
		read num;
		arr[i]=$num
	done		
}

selection_sort()
{
	for((i=0;i<$(($1-1));i++))
	do
		minloc=i
		for((j=1;j<$1;j++))
		do
			if [ ${arr[$j]} -lt ${arr[$minloc]} ]
			then
				min=j;
			fi
		done
		temp=${arr[$minloc]}
		arr[$minloc]=${arr[$min]}
		arr[$min]=$temp		
	done
}


echo "Enter $len integers in the list"
get_array $len
echo -n "Entered Elements: "
echo "${arr[*]}"
selection_sort $len
echo -n "Sorted array: "
echo "${arr[*]}"
