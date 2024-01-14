
<style>
	p{
		font-size:2em;
		width:100%;
		text-align:center;
		margin:2% auto;
}	
</style>
<?php
$conn=mysqli_connect('localhost','root','','company');
if(isset($_POST['submit']))
{
	$eid = $_POST['eid'];
	$basic = $_POST['basic'];
	$hra = $_POST['hra'];
	$da = $_POST['da'];
	$tax = $_POST['tax'];
	$insert = "INSERT INTO EMPLOYEE VALUES ('$eid',$basic,'$hra','$da','$tax');";
	$insertres = mysqli_query($conn,$insert);
	if($insertres)
	{
		echo "<p>RECORD INSERTED</p>";
	}
	else
	{
		echo "<p>INSERTION FAILED</p>";
	}
}
else
	echo "No Data Received By Backend";
?>
