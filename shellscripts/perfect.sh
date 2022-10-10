is_perfect ()
{
	local i=1
	local factsum=0
	while [ $i -le $(( $1 / 2 )) ]
	do
		if [ $(($1 % $i)) -eq 0 ]
		then
			factsum=$(($factsum + $i))
		fi
		i=$(($i+1))
	done
	if [ $factsum -eq $1 ]
	then
		echo "The number $1 is a perfect number"
	else
		echo "The number $1 is not a perfect number"
	fi

}

echo "To Check Whether A Number Is Armstrong Or Not"
read -p 'Enter a number: ' usrnum
is_perfect $usrnum



