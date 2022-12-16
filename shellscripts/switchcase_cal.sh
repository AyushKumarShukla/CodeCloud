add()
{
	echo  "$1 + $2" | bc -l
}
sub()
{
	echo  "$1 - $2" | bc -l
}
mult()
{
	echo  "$1 * $2" | bc -l
}
div()
{
	echo "scale=5;$1 / $2" | bc -l
}
expo()
{
	echo "scale=5;$1 ^ $2" | bc -l
}
get_input()
{
	read -p 'Enter the first number: ' num1
	read -p 'Enter the second number: ' num2
}

echo "To perform Arithmetic operations on two numbers: "
while :
do
cat << mydoc
MENU:
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.DIVISION
5.EXPONENTIATION
6.EXIT
mydoc
	read -p 'Enter your choice: ' ch
	case "$ch" in
	"1")
	get_input
	echo -n "SUM: "
	add $num1 $num2
	;;

	"2")
	get_input
	echo -n "DIFFERENCE: "
	sub $num1 $num2
	;;

	"3")
	get_input
	echo -n "PRODUCT:"
	mult $num1 $num2
	;;

	"4")
	read -p 'Enter divisor: ' num2
	if [ `echo "$num2 == 0" | bc -l` -eq 1 ]
	then
		echo "DIVIDE BY ZERO ERROR"
		exit 1
	fi
	read -p 'Enter dividend ' num1
	echo -n "QUOTIENT: "
	div $num1 $num2
	;;

	"5")
	read -p 'Enter the base: ' num1
	read -p 'Enter the exponent: ' num2
	echo -n "RESULT: "
	expo $num1 $num2
	;;

	"6")
	break
	;;

	*)
	echo -n -e "Invalid Choice.......\n"
	;;
	esac
done

