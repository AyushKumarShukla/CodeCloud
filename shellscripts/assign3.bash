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

is_krishna()
{
	factsum=0
	local temp=$1
	while [ $temp -gt 0 ]
	do
		local digit=$(($temp%10))
		temp=$(($temp/10))
		factorial $digit
		factsum=$(( $factsum + $fact ))
	done

	if [ $factsum -eq $1 ]
	then
		echo "$1 IS a Krishnamurty number"
	else
		echo "$1 IS NOT a Krishnamurty number"
	fi
}

is_perfect()
{
	local i=1
	local factsum=0
	while [ $i -le $(( $1 / 2 )) ]
	do
		if [ $(($1 % $i)) -eq 0 ]
		then
			factsum=$(($factsum + $i))
		fi
		i=$(($i+1))
	done
	if [ $factsum -eq $1 ]
	then
		echo "The number $1 is a perfect number"
	else
		echo "The number $1 is not a perfect number"
	fi
}

is_armstrong()
{
	temp=$1
	sum=0
	digcount=0
	#Counting the number of digits
	while [ $temp -gt 0 ]
	do
		temp=$(($temp / 10))
		digcount=$(($digcount + 1))
	done
	#computing as per Armstrong number criteria
	temp=$1
	while [ $temp -gt 0 ]
	do
		digit=$((temp % 10))
		sum=`echo "$sum + ($digit^$digcount)" | bc -l`
		temp=$((temp / 10))
	done
	if [ $sum -eq $1 ]
	then
		echo "$1 is an Armstrong number"
	else

		echo "$1 is NOT an Armstrong number"
	fi
}

while :
do
cat << EOF
MENU:
1. CHECK FOR PERFECT NUMBER
2. CHECK FOR KRISHNAMURTY NUMBER
3. CHECK FOR ARMSTRONG NUMBER
4. EXIT
EOF
	read -p 'Enter your choice: ' ch
	if [ $ch -eq 4 ]
	then
		exit 0
	fi
	read -p 'Enter a number: ' usrnum

	case $ch in
	1)
		is_perfect $usrnum
		;;
	2)
		is_krishna $usrnum
		;;
	3)
		is_armstrong $usrnum
		;;
	*)
		echo "Invalid Choice"
		;;
	esac
done
