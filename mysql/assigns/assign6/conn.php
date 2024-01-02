<?php
$host="localhost";
$user="root";
$pass="";
$db="college";

$conn = mysqli_connect($host,$user,$pass,$db);
if(!$conn)
	echo "connection failed";
?>

