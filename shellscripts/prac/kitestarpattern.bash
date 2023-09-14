
kite_pattern()
{
	mid=$(($1/2))
	for(( i=0;i<row;i++ ))
	do
		for((j=0;j<row;j++))
		do
			if [ $i -lt $mid -a $((i+j)) -ge $((mid-i)) -a $((i+j)) -le $((mid+i)) ] || [ $i -eq $mid ] || [ $(((i-mid)+j)) -ge $((mid-(i-mid))) -a $(((i-mid)+j)) -le $((mid+(i-mid))) ]
			then
				echo -n " * "
			else
				echo -n " "
			fi
		done
		echo -e "\n"
	done
}

echo "To print a kite star pattern"
read -p 'Enter the number of rows needed' row
if [ $row -lt 1 ]
then
	echo "There must be atleast 1 row"
	exit 1
fi
kite_pattern $row
