<style>
	
</style>
<?php
include 'connect.php';
if(isset($_POST['submit']))
{
	$mail = $_POST['email'];
	$query = "SELECT name,roll,email FROM STUDENT WHERE email = '$mail'";
	$res = mysqli_query($conn,$query);
	$rowcnt = mysqli_num_rows($res);
	if($rowcnt != 0)
	{
		echo "<table>";
		echo "<tr>";
		echo "<th>" . "NAME" . "</th>";
		echo "<th>" . "ROLL" . "</th>";
		echo "<th>" . "EMAIL" . "</th>";
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
	}
}
?>