# Shell script to generate Pascal's Triangle

factorial()
{
	local i=$1
	fact=1
	while [ $i -ne 0 ]
	do
		fact=$(($fact*$i))
		i=$(($i-1))
	done
}

c()
{
	factorial $1
	res=$fact
	factorial $2
	res=$(($res/($fact)))
	factorial $(($1-$2))
	res=$(($res/$fact))
}

pascal()
{
	k=0
	for((i=0;i<$1;i++))
	do
		for((j=0;j<$1;j++))
		do
			if [ $j -le $i ]
			then
				c $i $j
				arr[$k]=$res
				k=$((k+1))
			fi
		done
	done
}

pattern()
{
	pascal $row
	l=0
	for ((i=0;i<$1;i++));
	do
		for ((j=0;j<$2;j++));
		do
			diff=$(($i-$j))
			diff_sq=$(($diff * $diff))
			abs_diff=`echo "scale=0;sqrt($diff_sq)" | bc -l`
			if ([ $abs_diff -eq 0 ] || [ $(($abs_diff % 2)) -eq 0 ]) && ([ $j -ge $(($3 - $i )) ] && [ $j -le $(($3 + $i)) ]);
			then
				echo -n -e "${arr[$l]}"
				l=$((l+1))
			else
				echo -n -e " "
			fi
		done
		echo
	done
	if [ $((row % 2)) -eq 0 ]
	then
		#l=$((l+1))
		for((j=0;j<$((row * 2));j++))
		do
			echo -n "${arr[$l]} "
			l=$((l+1))
		done
	echo
	fi
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

