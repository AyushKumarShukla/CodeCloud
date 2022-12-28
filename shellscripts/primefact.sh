
is_prime (){
	local i=2
	flag=1
	while [ $i -lt $1 ]
	do
		if [ $(($1%$i)) -eq 0 ]
		then
			flag=0
		fi
		i=$(($i+1))
	done
}

primefact (){
	local i=2
	exists=0
	while [ $i -le $(($1/2)) ]
	do
		if [ $(($1 % $i)) -eq 0 ]
		then
			is_prime $i
			if [ $flag -eq 1 ]
			then
				exists=1
				echo -n "$i "
			fi
		fi
		i=$(($i+1))
	done
}
echo "To print the list of prime factors of a number: "
read -p 'Enter the number: ' num
if [ $num -le 0 ]
then
	echo "Invalid Input"
	exit 1
fi
echo "Prime Factors: "
primefact $num
if [ $exists -eq 0 ]
then
	echo -n "None,$num is prime"
fi
echo
