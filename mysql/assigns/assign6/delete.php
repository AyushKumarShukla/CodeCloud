<?php
include 'conn.php';

if(isset($_POST['submit']))
{
	$key=$_POST['key'];
	$query = "DELETE FROM STUDENT WHERE ROLL=$key";
	$res = mysqli_query($conn,$query);
	$resrow = mysqli_affected_rows($conn);
	if($resrow == 1)
		echo "<h2>DELETED SUCCESSFULLY</h2>";
	else
		echo "<h2>FAILED</h2>";	
}
else
	echo "No Data received by backend";
?>
