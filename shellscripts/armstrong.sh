
is_armstrong()
{
	local temp=$1
	sum=0
	while [ $temp -gt 0 ]
	do
		local digit=$(($temp%10))
		temp=$(($temp/10))
		sum=$(($sum+$(($digit*$digit*$digit))))
	done
	if [ $sum -eq $1 ]
	then
		echo "$1 is an Armstrong number"
	else

		echo "$1 is NOT an Armstrong number"
	fi
}


echo "To check if a number is an Armstrong number"
read -p 'Enter a number' usrnum

is_armstrong $usrnum
