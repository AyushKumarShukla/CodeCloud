quadratic()
{
	disc=`echo "$B^2-4*$A*$C" | bc -l &2> /dev/null`
	#echo -n "DISC:$disc"
	if [[ $disc < 0 ]];
	then
		echo "Roots are Imaginary"
	elif [[ $disc = 0 ]];
	then
		echo "Roots are equal"
	else
		echo "Roots are distinct"
	fi 
	res1=`echo "(-($B)+sqrt($disc))/(2*$A)" | bc -l`
	res2=`echo "(-($B)-sqrt($disc))/(2*$A)" | bc -l`
	echo "Roots are $res1 and $res2"
}

echo "To solve a quadratic equation of the form Ax^2 + Bx + C = 0"
read -p 'Enter A' A
read -p 'Enter B' B
read -p 'Enter C' C
quadratic $A $B $C 

 
