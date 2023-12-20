<?php
include 'connect.php';

$q1="CREATE DATABASE IF NOT EXISTS college;";
if(!mysqli_query($conn,$q1))
	echo "<p>q1 failed</p>";
else
	echo "<p>q1 success</p>";
//it is important to select a database first
mysqli_select_db($conn,"college");

$q2="CREATE TABLE IF NOT EXISTS student 
	(name varchar(50), 
	roll int,
	city varchar(50),
	email varchar(50),
	dob DATE,
	PRIMARY KEY(roll));";

if(!mysqli_query($conn,$q2))
	echo "q2 failed\n";
else
	echo "q2 success\n";

// var_dump($_POST);

// if ($_SERVER['REQUEST_METHOD'] == 'POST')
if(isset($_POST['submit']))
{
	$name = $_POST['name'];
	$roll = $_POST['roll'];
	$city = $_POST['city'];
	$email = $_POST['email'];
	$dob = $_POST['dob'];
	$i1 = "INSERT INTO STUDENT VALUES ('$name','$roll','$city','$email','$dob');";
	$out = mysqli_query($conn,$i1);

	if(!$out)
		echo "Insertion failed";
	else
		echo "Inserted successfully";
}	
else
	echo "No input provided";
 ?>