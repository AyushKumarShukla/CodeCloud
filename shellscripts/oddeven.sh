echo "Enter a number"
read num
p=`expr $num % 2`
if [ $p -eq 0 ]
then
	echo "EVEN"
else
	echo "ODD"
fi

