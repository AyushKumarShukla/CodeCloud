
Euclid_Algo()
{
# if num1 is less than num 2 , the first loop operation simply swaps the values - MatheMagically :)
	tnum1=$1
	tnum2=$2
	while :
	do
		rem=$(( $tnum1 % $tnum2 ))
		if [[ "$rem" -eq 0 ]]
		then
			gcd=$tnum2
			echo "GCD: $gcd"
			break 
		fi
		tnum1=$tnum2
		tnum2=$rem
	done
	lcm=$((($1 * $2)/$gcd))
	echo "LCM: $lcm"
}

echo "To find the GCD and LCM of two numbers: "
read -p 'Enter the first number: ' num1
read -p 'Enter the second number: ' num2
if [ $num2 -eq 0 ]
then
	temp=$num1
	num1=$num2
	num2=$temp
fi
Euclid_Algo $num1 $num2
