echo "To convert a number from one base to another base: "
read -p 'Enter the source base: ' sbase
read -p 'Enter the destination base: ' tbase
read -p "Enter a number in base $sbase: " num

result=`echo "obase=$tbase ; ibase=$sbase ; $num" | bc -l`
echo "$num in base $tbase is --> $result"
