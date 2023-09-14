
bin_search()
{
	left=0
	right=$(($1-1))
	while [ $left -le $right ]
	do
		mid=$(((left+right)/2))
		if [[ `echo "${arr[$mid]} == $2" | bc -l` -eq 1 ]]
		then
			flag=1
			pos=$mid
			break;
		elif [[ `echo "${arr[$mid]} < $2" | bc -l` -eq 1 ]]
		then
			left=$((mid+1))
		else
			right=$((mid-1))
		fi
	done
}



echo "To search a list of numbers using binary search: "
echo "Enter the list of numbers"
read -a arr
size=${#arr[@]}
flag=0
if [[ $size -lt 1 ]]
then
	echo "Invalid Input"
	exit 1
fi
arr=(`printf "%s\n" "${arr[@]}" | sort -n`)
echo "${arr[@]}"
read -p 'Enter the element to be searched' key
bin_search $size $key
if [[ $flag -eq 1 ]]
then
	echo "The element $key found at position $((pos+1))"
else
	echo "Element not found in the list"
fi
