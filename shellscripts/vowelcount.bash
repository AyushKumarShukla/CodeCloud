echo "To count the number of vowels in a given file: "
read -p 'Enter the filename: ' file

if [[ -f "$file" ]]
then
	echo -e "Content of the file \"$file\":\n"
	cat "$file"
	echo
	count=`grep -o -i "[a,e,i,o,u]" "$file" | wc -l`
	echo "The number of vowels in the file \"$file\" is = $count"
else
	echo "The file \"$file\" does not exist in the current directory "
fi
