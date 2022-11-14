#Program to check if a given number is a perfect number

echo "Enter a number"
read usrnum
temp=usrnum
sum=0
i=1
while [ $i -le $(($temp / 2)) ]
do
	if [ $(($temp % $i)) -eq 0 ]
	then
		sum=$(($sum + $i))
	fi
	i=$(($i + 1))
done
if [ $sum -eq $usrnum ]
then
	echo "$usrnum is a perfect number"
else
	echo "$usrnum is not perfect number"
fi
