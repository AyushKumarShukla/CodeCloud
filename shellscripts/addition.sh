echo "Enter the first number"
read a
echo "Enter the second number"
read b

sum=$(( $a + $b )) #space sensitive
diff=`expr $a - $b`
echo "SUM: $sum"
echo "DIFF: $diff"
