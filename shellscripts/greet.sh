var=`date +"%H"`
if [ $var -ge 0 -a $var -lt 12 ]
then
	echo "GOOD MORNING"
elif [ $var -ge 12 -a $var -le 16 ]
then
	echo "GOOD AFTERNOON"
else
	echo "GOOD EVENING"
fi
