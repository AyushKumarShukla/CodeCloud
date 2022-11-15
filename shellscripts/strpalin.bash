str=$1
strlen=${#str}
for((i=strlen,j=1;i>=j;i--,j++));
do
	k=`echo "$str" | cut -c $i`
	l=`echo "$str" | cut -c $j`
	echo "$k $l"
	if [ "$k" != "$l" ]
	then
		echo "$str is not a palindrome"
		exit 1
	fi
done
echo "$str is a palindrome"

