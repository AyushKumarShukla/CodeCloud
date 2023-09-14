insert_rec()
{
	today=`date`
	echo -e "\nEntry Time: $today\n" >> $1
	printf "%-10s %-20s %-20s %-20s\n" "ID" "NAME" "DESIGNATION" "SALARY (LPA)" >> $1
	read -p 'Enter employee ID' eid
	read -p 'Enter employee name' ename
	read -p 'Enter employee designation' edes
	read -p 'Enter employee salary' esal
	printf "%-10s %-20s %-20s %-20s" "$eid" "$ename" "$edes" "$esal" >> $1
}

display_rec()
{
	grep -q "$2" "$1"
	if [ $? -ne 0 ]
	then
		echo "No such entry exists"
	else
		printf "%-10s %-20s %-20s %-20s\n" "ID" "NAME" "DESIGNATION" "SALARY (LPA)"
		grep "$2" "$1"
	fi 
}

echo "Welcome to the employee database"
read -p 'Enter the filename ' database
if test -e "$database"
then
while :
do
cat << EOF
1.INSERT DATA
2.VIEW DATA
3.EXIT
EOF
	read -p 'Enter your choice' ch
	case "$ch" in 
	1)
		insert_rec $database
		;;
	2)
		read -p 'Enter employee ID to search' arg
		display_rec $database $arg
		;;
	3)
		exit 0
		;;
	*)
		echo "Invalid Choice..Try Again"
		;;
	esac
done
else
	echo "No such file exists"
	exit 1
fi
