echo "To concatenate two files into a third file: "
read -p 'Enter the first filename: ' file1
read -p 'Enter the second filename: ' file2

if ([ -f "$file1" ] && [ -f "$file2"  ])
then
	read -p 'Enter the name of the output file: ' catout
	cat "$file1" "$file2" > "$catout"
else
	echo "The given file combination does not exist"
fi
