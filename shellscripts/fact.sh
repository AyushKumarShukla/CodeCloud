echo "To find the factorial of a given number" 
read -p 'Enter the number: ' num
fact (){
	local temp=$num
	local i=1
	prod=1
	while [ $temp -gt 0 ]
	do
		prod=$(( $prod*$temp ))
		temp=$(($temp-1))
	done
}

if [ $num -lt 0 ]
then
	echo "Invalid Input"
else
	fact $num
	echo "The factorial of $num is $prod"
fi
