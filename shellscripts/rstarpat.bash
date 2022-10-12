pattern()
{
	for ((i=0;i<$1;i++));
	do
		for ((j=0;j<$1;j++));
		do
			if [[ $j -le $i ]]
			then
				echo -n "*"
			else
				echo -n " "
			fi
		done
		echo
	done
		

}


echo -n "Enter the number of lines needed in the pattern: "
read usrnum
if [[ $usrnum -le 0 ]]
then
	echo "There must be atleast one line"
else
	pattern $usrnum
fi
