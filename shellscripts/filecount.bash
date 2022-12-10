echo "To count the number of words, lines and characters of a given file"
read -p 'Enter the file name: ' file

if [ -f $file ]
then
	echo "Content Of File: "
	cat $file
	words=`wc -w < $file`
	spaces=`grep -o ' ' $file | wc -l`
	lines=`wc -l < $file`
	chars=$((`wc -m < $file` - $spaces - $lines))
	echo -e "\nCharacter Count:$chars\nWord Count:$words\nLine Count:$lines\nSpace Count:$spaces"
else
	echo "File Does Not Exist"
	exit 1
fi
