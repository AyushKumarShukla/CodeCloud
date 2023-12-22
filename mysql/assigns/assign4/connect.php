<?php

$host="localhost";
$user="root";
$pass="";

$conn=mysqli_connect($host,$user,$pass);
if(!$conn)
	echo "<p>Failed</p>";
mysqli_select_db($conn,'college');
?>
