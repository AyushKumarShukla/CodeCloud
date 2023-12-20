<?php
include 'connect.php';
mysqli_select_db($conn,"college");
$q = "select * from student";
$res = mysqli_query($conn,$q);
$rows = mysqli_num_rows($res);

?>
<style>
	table, th, tr, td { border-collapse: collapse; border: 1px solid; padding: 1.2em; }
</style>
<h1>Student Details</h1>
<?php
if($rows != 0)
{
	echo "<table>";
	echo "<tr>";
	echo "<th>" . "NAME" . "</th>";
	echo "<th>" . "ROLL" . "</th>";
	echo "<th>" . "CITY" . "</th>";
	echo "<th>" . "EMAIL" . "</th>";	
	echo "<th>" . "DOB" . "</th>";
	echo "</tr>";

	while($r=mysqli_fetch_assoc($res))
	{
		echo "<tr>";
		foreach ($r as $val)
		{
			echo "<td>".$val."</td>";
		}
		echo "</tr>";
	}
	echo "</table>";	
}
else
	echo "No Result Found";
?>