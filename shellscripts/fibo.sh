echo "To print the fibonacci series: "
read -p 'Enter the number of terms needed in the series: ' terms

fibo (){

	prevterm=0
	currterm=1
	i=0
	echo -n "$prevterm $currterm " 
	while [ $i -lt $(($terms-2)) ]
	do
		newval=$(( $prevterm + $currterm ))
		echo -n "$newval "
		prevterm=$currterm
		currterm=$newval
		i=$(($i+1))
	done
	echo
}
if [ $terms -le 0 ]
then
	echo "Invalid input, there must be atleast 1 term in the sequence"
elif [ $terms -eq 1 ]
then
	echo "0"
else
	fibo $terms
fi
