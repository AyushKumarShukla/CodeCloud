var=`date +"%H"`
if [ $var -ge 4 -a $var -lt 12 ]
then
	echo "GOOD MORNING"
elif [ $var -ge 12 -a $var -le 16 ]
then
	echo "GOOD AFTERNOON"
elif [ $var -ge 17 -a $var -le 22 ]
then
	echo "GOOD EVENING"
else
	echo "GOOD NIGHT"
fi
