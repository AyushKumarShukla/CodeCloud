<?php
include 'connect.php';
$num=$_POST['num'];
$q = "SELECT * FROM student LIMIT $num;";
$res=mysqli_query($conn,$q);
echo "exec";
echo "<table border='1'>
	<tr>
		<th>Name</th>
		<th>Roll</th>
	</tr>
	";

while($row = mysqli_fetch_assoc($res))
{
	echo "<tr>
		<td> ".$row['name']." </td>
		<td> ".$row['roll']." </td>
	      </tr>
		";
}
echo "</table>";
?>
