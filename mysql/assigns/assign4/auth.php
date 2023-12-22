<?php
include 'connect.php';

if(isset($_POST['submit']))
{
	$usrname = $_POST['usrname'];
	$password = $_POST['password'];
	$query = "SELECT * FROM login where username='$usrname' AND password='$password';";
	$res = mysqli_query($conn,$query);
	$rowcnt = mysqli_num_rows($res);
	if($rowcnt != 0)
	{
		echo "<p>User Authenticated</p>";
		$q2 = "SELECT * FROM student;";
		$res2 = mysqli_query($conn,$q2);
		
		echo "<table>";
		echo "<tr>";
		echo "<th>" . "NAME" . "</th>";
		echo "<th>" . "ROLL" . "</th>";
		echo "<th>" . "CITY" . "</th>";
		echo "<th>" . "EMAIL" . "</th>";
		echo "<th>" . "DATE OF BIRTH" . "</th>";
		echo "</tr>";
		echo "<tr>";
		while($row = mysqli_fetch_assoc($res2))
		{
			foreach($row as $val)
			{
				echo "<td>".$val."</td>";
			}
			echo "</tr>";
		}
		
	}
	else
		echo "<p>User Not Authenticated</p>";
}

?>