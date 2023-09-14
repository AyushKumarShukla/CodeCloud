echo "To convert a file from lowercase to uppercase"
read -p 'Enter the file name: ' file


if [ -f $file ]
then
	echo -e "Before conversion: \n"
	tr '[A-Z]' '[a-z]' < $file
	echo -e "\nAfter conversion: \n"
	tr '[a-z]' '[A-Z]' < $file
else
	echo "File Does Not Exist In The Current Directory"
fi

