<?php

$host="localhost";
$user="root";
$pass="";

$conn=mysqli_connect($host,$user,$pass);
if(!$conn)
	echo "<p>Failed</p>";
else
	echo "<p>Success</p>";


?>