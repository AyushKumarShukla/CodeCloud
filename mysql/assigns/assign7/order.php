<style>
	h2{
		width:50%;
		margin:2% auto;
		text-align:center;
	}
	.bill, .bill2{
		width:50%;
		margin:4% auto;
		text-align:center;
		border:2px solid black;
		padding:2%;
		font-size:25px;
	}
</style>
<?php
$conn = mysqli_connect("localhost","root","","eatery");
if(!$conn)
        echo "CONNECTION FAILED";

if(isset($_POST['submit']))
{
	$q = "SELECT PRICE FROM MENU;";
	$prices = mysqli_query($conn,$q);
	$bill = [];
	$index = 0;
	while($row=mysqli_fetch_row($prices))
	{
		$bill[$index] = $row[0] * $_POST['item'.($index+1)];
		$index++;
	}
	$total=0;
	echo "<h2>BILL SUMMARY</h2>";
	echo "<div class=bill>";
	for($i=0;$i<count($bill);$i++)
	{
		echo "ITEM ".($i+1)." PRICE:\t".$bill[$i];
		$total += $bill[$i];
		echo "<br>";
	}
	echo str_repeat('-',50);
	echo "<br>";
	echo "TOTAL AMOUNT: ".$total."<br>";
	echo "</div>";
	echo "<h2>PAYABLE AMOUNT</h2>";
	echo "<div class='bill2'>";
	
	$tax = $total * (15.0/100.0);
	echo "GST ON TOTAL AMOUNT: ".$tax."<br>";;
	$payable = $total + $tax;
	echo "PAYABLE AMOUNT: ".$payable;
	echo "</div>";
}
?>

