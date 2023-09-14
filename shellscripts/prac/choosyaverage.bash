sum=0
total=0
flag=0
if [ $# -eq 0 ]
then
	echo "No arguments supplied"
	exit 0
fi
while [ $# -gt 0 ]
do
	if [[ $1 -ge 10 ]]
	then
		sum=$((sum+$1))
		total=$((total+1))
		flag=1
	fi
	shift
done
if [ $flag -eq 0 ]
then
	echo "No argument is greater than or equal to 10"
	exit 0
fi
avg=`echo " scale=2 ; $sum/$total" | bc -l`
echo "CHOOSY AVERAGE: $avg"

