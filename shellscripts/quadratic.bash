quadratic()
{
	disc=`echo "$2^2-4*$1*$3" | bc -l`
	#echo -n "DISC:$disc"
	if [[ "$disc" -lt 0 ]]
	then
		echo "Roots are Imaginary"
		exit 0 
	elif [[ "$disc" -eq 0 ]]
	then
		echo "Roots are equal"
	else
		echo "Roots are distinct"
	fi 
	res1=`echo "scale=3;(-($B)+sqrt($disc))/(2*$A)" | bc -l`
	res2=`echo "scale=3;(-($B)-sqrt($disc))/(2*$A)" | bc -l`
	echo "Roots are $res1 and $res2"
}

echo "To solve a quadratic equation of the form Ax^2 + Bx + C = 0"
read -p 'Enter A: ' A
read -p 'Enter B: ' B
read -p 'Enter C: ' C
quadratic $A $B $C 

 
