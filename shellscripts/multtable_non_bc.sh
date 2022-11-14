echo "To print the multiplication table of a number"
read -p 'Enter the number: ' num
read -p 'Enter the number of terms required: ' terms

table (){

	i=1;
	while [ $i -le $terms ]
	do
		prod=$(( $num * $i ))
		echo "$num X $i = $prod"
		i=$(($i+1))
	done
}



table $num $terms
