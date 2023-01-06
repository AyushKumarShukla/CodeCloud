bin_search()
{
	beg=0
	end=$(( $1-1 ))
	while [[ $beg -le $end ]]
	do
		mid=$(( ($beg+$end)/2 ))
		if [[ `echo "${arr[$mid]} == $2 " | bc -l` -eq 1 ]]
		then
			flag=1
			pos=$mid
			break
		elif [[ `echo "${arr[$mid]} <  $2 " | bc -l` -eq 1 ]]
		then
			beg=$((mid+1))
		else
			end=$((mid-1))
		fi
	done
}
echo "To perform binary search on a list of numbers"
echo "Enter array elements in ascending order: "
flag=0
read -a arr
arr=(`printf "%s\n" "${arr[@]}" | sort -n`)
usrnum=${#arr[@]}
echo "Entered Elements: ${arr[*]}"
read -p 'Enter the number to be searched: ' key
bin_search $usrnum $key
if (($flag == 1))
then
	echo "Element $key found at position $(($pos+1))"
else
	echo "Element $key not found in the list"
fi


