echo "To print all the prime numbers in a given range "
read -p 'Enter the lower limit: ' low
read -p 'Enter the upper limit: ' up

if [ $up -lt $low ]
then
	echo "Invalid Input"
	exit 1
fi

is_prime (){
	i=2
	flag=1
	while [ $i -lt $1 ]
	do
		if [ $(( $1 % $i )) -eq 0 ]
		then
			flag=0
		fi
		i=$(($i+1))
	done
}

prime_in_range (){
	i=$1
	while [ $i -le $2 ]
	do
		is_prime $i
		if [ $flag -eq 1 ]
		then
			echo -n "$i "
		fi
		i=$(($i+1))
	done
}
prime_in_range $low $up
echo
