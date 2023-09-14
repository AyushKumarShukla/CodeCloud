pattern()
{
	for ((i=0;i<$1;i++));
	do
		for ((j=0;j<$2;j++));
		do
			diff=$(($i-$j))
			diff_sq=$(($diff * $diff))
			abs_diff=`echo "scale=0;sqrt($diff_sq)" | bc -l`
			if ([ $abs_diff -eq 0 ] || [ $(($abs_diff % 2)) -eq 0 ]) && ([ $j -ge $(($3 - $i )) ] && [ $j -le $(($3 + $i)) ]);
			then
				echo -n "*"
			else
				echo -n " "
			fi
		done
		echo
	done
		

}


echo -n "Enter the number of lines needed in the pattern: "
read row
col=$(((2*row)-1))
mid=$((col / 2))
if [[ $row -le 0 ]]
then
	echo "There must be atleast one line"
else
	pattern $row $col $mid
fi
