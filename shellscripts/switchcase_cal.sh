add ()
{
	echo  "$1+$2" | bc -l
}
sub ()
{
	echo  "$1 - $2" | bc -l
}
mult ()
{
	echo  "$1 * $2" | bc -l
}
div ()
{
	if [ echo "$1 == $2" | bc -l ]
	then
		echo "DIVIDE BY ZERO ERROR"
	else
		echo "$1/$2" | bc -l
	fi
}

echo "To perform Arithmetic operations on two numbers: "
read -p 'Enter the first number: ' num1
read -p 'Enter the second number: ' num2

while :
do
cat << mydoc
MENU:
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.DIVISION
5.EXIT
mydoc
	read -p 'Enter your choice: ' ch
	case "$ch" in
	"1")
	echo -n "SUM: "
	add $num1 $num2
	;;
	"2")
	echo -n "DIFFERENCE: "
	sub $num1 $num2
	;;
	"3")
	echo -n "PRODUCT:"
	mult $num1 $num2
	;;
	"4")
	echo -n "QUOTIENT: "
	div $num1 $num2
	;;
	"5")
	break
	;;
	*)
	echo -n "Invalid Choice......."
	;;
	esac
done

