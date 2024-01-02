<?php
include 'conn.php';
error_reporting(-1);
if(isset($_POST['submit']))
{
	$key = $_POST['key'];
	$name = $_POST['name'];
	$roll = $_POST['roll'];
	$city = $_POST['city'];
	$email = $_POST['email'];
	$dob = $_POST['dob'];
	$query = "UPDATE STUDENT SET 
		NAME='$name',
		ROLL=$roll,
		CITY='$city',
		EMAIL='$email',
		DOB='$dob' 
		WHERE ROLL=$key;";
	$res = mysqli_query($conn,$query);
	if($res)
		echo "<h2>UPDATED SUCCESSFULLY</h2>";
	else
		echo "UPDATE FAILED";
}
else
{
	echo "No data received by backend";
}
?>
