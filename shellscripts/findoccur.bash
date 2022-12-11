echo "To count the number of occurences of a word in a file: "
read -p 'Enter the name of the file: ' file

if [[ -f "$file" ]]
then
	echo -e "Contents Of the File Are:\n"
	cat "$file"
	echo
	read -p 'Enter the word to be count: ' word
	count=`grep -o -i "$word" "$file" | wc -l`
else
	echo "Entered file does not exist in the current directory"
	exit 1
fi

echo -e "\nNumber of occurences of \"$word\" in file \"$file\" is $count"
