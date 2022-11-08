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



echo "To Check if a number is Krishnamurty number"
read -p 'Enter a number' usrnum
if [ $usrnum -lt 0 ]
then
	echo "Invalid Input"
elif [ $usrnum -eq 0 ]
then
	echo "$usrnum IS NOT a Krishnamurty number"
else
	is_krishna $usrnum
fi
