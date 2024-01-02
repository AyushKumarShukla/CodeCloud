
<style>
	p{
		font-size:2em;
		width:100%;
		text-align:center;
		margin:2% auto;
}	
</style>
<?php
include 'conn.php';
if(isset($_POST['submit']))
{
	$name = $_POST['name'];
	$roll = $_POST['roll'];
	$city = $_POST['city'];
	$email = $_POST['email'];
	$dob = $_POST['dob'];
	$insert = "INSERT INTO STUDENT VALUES ('$name',$roll,'$city','$email','$dob');";
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
