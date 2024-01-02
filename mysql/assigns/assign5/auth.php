<style>
	body{
		background-color:#83e2ff;
		font-family:consolas;
	}
	table{
		width:50%;
		margin:6% auto;
		border-collapse:collapse;
	}
	td,th{
		border:2px solid black;
		/*width:auto;*/
		white-space:nowrap;
		border-collapse:collapse;
		padding:10px;
	}
	h2{
		width:50%;
		margin:2% auto;
		text-align:center;
		font-size:3rem;
	}
	p{
		width:50%;
		margin:0px auto;
		text-align:center;
		font-weight:bold;
	}
</style>
<html>
<head>
	<title>Student Info</title>
</head>
</html>

<?php
include 'connect.php';

if(isset($_POST['submit']))
{
	$usrname = $_POST['usrname'];
	$password = $_POST['password'];
	$query = "SELECT * FROM LOGIN where username='$usrname' AND password='$password';";
	$res = mysqli_query($conn,$query);
	$rowcnt = mysqli_num_rows($res);
	if($rowcnt != 0)
	{
		echo "<h2>STUDENT TABLE</h2>";
		echo "<p>User Authenticated</p>";
		$q2 = "SELECT * FROM STUDENT NATURAL JOIN LOGIN;";
		$res2 = mysqli_query($conn,$q2);
		
		echo "<table>";
		echo "<tr>";
		echo "<th>" . "NAME" . "</th>";
		echo "<th>" . "ROLL" . "</th>";
		echo "<th>" . "CITY" . "</th>";
		echo "<th>" . "EMAIL" . "</th>";
		echo "<th>" . "DATE OF BIRTH" . "</th>";
		echo "<th>" . "USERNAME" . "</th>";
		echo "<th>" . "PASSWORD" . "</th>";
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
		echo "<h2>User Not Authenticated</h2>";
}

?>
