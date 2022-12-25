insert_rec()
{
	today=`date`
	echo -e "Entry Time: $today\nID\t\tNAME\t\tDESIGNATION\t\tSALARY(In LPA)" >> datafile.txt
	read -p 'Enter Employee ID: ' eid
	read -p 'Enter Employee NAME: ' ename
	read -p 'Enter Employee DESIGNATION: ' edes
	read -p 'Enter Employee SALARY In Lakhs Per Annum: ' esal
	echo -e "$eid\t$ename\t$edes\t\t$esal\n" >> datafile.txt
}

view_rec()
{
	read -p 'Enter the employee ID: ' eid
	grep "$eid" "datafile.txt"
}

echo "Welcome to the employee database:" 
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
		exit 0
	fi
	case $ch in
	1)
		insert_rec
		;;
	2)
		view_rec
		;;
	*)
		echo "Invalid Choice"
		;;
	esac
done

