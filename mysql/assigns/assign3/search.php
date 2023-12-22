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
</style>
<html>
<head>
	<title>Student Info</title>
</head>
<body>
	<h2>STUDENT TABLE</h2>
</body>
</html>
<?php
include 'connect.php';
if(isset($_POST['submit']))
{
	$mail = $_POST['email'];
	$query = "SELECT * FROM STUDENT WHERE email = '$mail'";
	$res = mysqli_query($conn,$query);
	$rowcnt = mysqli_num_rows($res);
	if($rowcnt != 0)
	{
		echo "<div class=output>";
		echo "<table>";
		echo "<tr>";
		echo "<th>" . "NAME" . "</th>";
		echo "<th>" . "ROLL" . "</th>";
		echo "<th>" . "CITY" . "</th>";
		echo "<th>" . "EMAIL" . "</th>";
		echo "<th>" . "DOB" . "</th>";
		echo "</tr>";
		echo "<tr>";
		while($row = mysqli_fetch_assoc($res))
		{
			foreach($row as $val)
			{
				echo "<td>".$val."</td>";
			}
			echo "</tr>";
		}
		echo "</div>";
	}
}
?>
