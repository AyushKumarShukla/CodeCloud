
is_leapyear()
{
	if [ `expr $1 % 4` -eq 0 ] &&  [ `expr $1 % 100` -ne 0 ] || [ `expr $1 % 400` -eq 0 ]
	then
		echo "$year is a leap year"
	else
		echo "$year is NOT a leap year"
	fi
}

echo "To check whether a year is a leapyear "
read -p 'Enter a year: ' year

#input validation on a pre-assumed range of years
if [ $year -lt 1000 ] || [ $year -gt 9999 ]
then
	echo "Invalid year"
	exit 1
fi
is_leapyear $year

