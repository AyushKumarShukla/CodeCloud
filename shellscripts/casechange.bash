echo "To convert a file from lowercase to uppercase"
read -p 'Enter the file name: ' file


if [ -f $file ]
then
	
	tr '[A-Z]' '[a-z]' < $file
	echo "After conversion: "
	tr '[a-z]' '[A-Z]' < $file
else
	echo "File Does Not Exist"
fi

