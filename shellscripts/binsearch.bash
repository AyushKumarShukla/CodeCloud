get_array()
{
	for((i=0;i<$1;i++))
	{
		read temp;
		arr[$i]=$temp
	}
}
bin_search()
{
	beg=0
	end=$(( $usrnum-1 ))
	while [[ $beg -le $end ]]
	do
		mid=$(( ($beg+$end)/2 ))
		mid=${mid/.*}
		if((`echo "${arr[$mid]} == $key " | bc -l`))
		then
			flag=1
			pos=$mid
			break
		elif((`echo "${arr[$mid]} <  $key " | bc -l`))
		then
			end=$(($mid-1))
		else
			beg=$(($mid+1))
		fi
	done
}

echo "To perform binary search on a list of numbers"
read -p 'Enter the number of elements needed in the list: ' usrnum
if (($usrnum < 1 ))
then
	echo "Invalid list size , the size of the list must be atleast 1"
	exit 1 
fi

echo "Enter $usrnum Elements in decending order : "
flag=0
get_array $usrnum

echo "Entered Elements: ${arr[*]}"
read -p 'Enter the number to be searched: ' key
bin_search $usrnum $key

if (($flag == 1))
then
	echo "Element $key found at position $(($pos+1))"
else
	echo "Element $key not found in the list"
fi


