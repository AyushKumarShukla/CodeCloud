
is_prime()
{
	flag=1	
	for ((j=2;j<$1;j++))
	do
		if [[ `echo "$1%$j == 0" | bc -l` -eq 0 ]]
		then
			flag=0
			break
		fi
	done
}

prime_in_range()
{
	flag=0
	for ((i=$low;i<$up;i++))
	do
		is_prime $i
		if [ $flag -eq 1 ]
		then
			echo "$i "
		fi
	done
}

echo "To print all the prime numbers in a given range"
read -p 'Enter the lower limit' low
read -p 'Enter the upper limit' up

prime_in_range $low $up
