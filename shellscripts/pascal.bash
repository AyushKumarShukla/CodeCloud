# Shell script to check if a given number is a Krishnamurty Number\

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
	for((i=0;i<$1;i++))
	do
		for((j=0;j<$1;j++))
		do
			if [ $j -le $i ]
			then
				c $i $j
				echo -n "$res "
			else
				echo -n " "
			fi
		done
		echo
	done
}

read -p 'Enter the number of lines needed:' usrnum
pascal $usrnum
