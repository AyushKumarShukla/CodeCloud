#!/usr/bin/bash
insert_rec()
{
	today=`date`
	echo  "Entry Time: $today " >> $1
	printf "%-10s %-20s %-20s %-10s" "ID" "NAME" "DESIGNATION" "SALARY(In LPA)" >> $1
	read -p 'Enter Employee ID: ' eid
	read -p 'Enter Employee NAME: ' ename
	read -p 'Enter Employee DESIGNATION: ' edes
	read -p 'Enter Employee SALARY In Lakhs Per Annum: ' esal
	echo >> $1
	printf "%-10s %-20s %-20s %-10s\n" "$eid" "$ename" "$edes" "$esal" >> $1
}

view_rec()
{
	read -p 'Enter the Employee ID: ' eid
	grep -q "$eid" "$1"
	if [ $? -ne 0 ]
	then
		echo "No entry with Employee ID $eid"
	else
		printf "%-10s %-20s %-20s %-10s\n" "ID" "NAME" "DESIGNATION" "SALARY(In LPA)"
	fi
	grep "$eid" "$1"

}

echo "Welcome to the employee database:"
read -p 'Enter the filename of database file: ' database
dir=`pwd`
if test -e "$database"
then
while :
do
cat << EOF
MENU:
1. INSERT EMPLOYEE RECORD
2. VIEW EMPLOYEE RECORD
3. EXIT
EOF
		read -p 'Enter your choice: ' ch
		if [ $ch -eq 3 ]
		then
			echo "The entries have been stored in the file $database in path $dir"
			exit 0
		fi
		case $ch in
		1)
			insert_rec $database
			;;
		2)
			view_rec $database
			;;
		*)
			echo "Invalid Choice"
			;;
		esac
done
else
	echo "The file $database does not exist in the current path $dir"
fi
