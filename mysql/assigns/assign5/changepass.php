<style>
	h2,a{
		width:70%;
		margin:1% auto;
		text-align:center;
	}
</style>
<?php
include 'connect.php';
error_reporting(E_ALL);
ini_set('display_errors',1);
if(isset($_POST['submit']))
{
	$olduser = $_POST['oldusr'];
	$oldpass = $_POST['oldpass'];
	$newuser = $_POST['newusr'];
	$newpass = $_POST['newpass'];
	$check = "SELECT * FROM LOGIN WHERE USERNAME='$olduser' AND PASSWORD='$oldpass';";
	$checkres = mysqli_query($conn,$check);
	$checknumrows = mysqli_num_rows($checkres);
	if($checknumrows != 0) //if user exists
	{
		$update = "UPDATE LOGIN SET PASSWORD='$newpass',USERNAME='$newuser' WHERE USERNAME='$olduser' AND PASSWORD='$oldpass';";
		$updateres = mysqli_query($conn,$update); //change password
		if($updateres)
		{
			echo "<h2>CREDENTIALS UPDATED SUCCESSFULLY</h2>";
			echo "<a href='userview.html'>" . "Go Back To Login Page" . "</a>";
		}
		else
			echo "<h2>CREDENTIAL UPDATE FAILED</h2>";
	}
	else
		echo "<h2>NO RECORD FOUND</h2>";
}

?>
