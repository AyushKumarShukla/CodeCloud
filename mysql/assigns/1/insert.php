<?php
include 'connect.php';
$q1 = "CREATE DATABASE IF NOT EXISTS college;";
mysqli_query($conn,$q1);

mysqli_select_db($conn, "college");

$q2 = "CREATE TABLE IF NOT EXISTS student (name varchar(20), roll int(10));";
mysqli_query($conn,$q2);

$name = $_POST["username"];
$id = $_POST["id"];
$city = $_POST["city"];
$email = $_POST["email"];
$dob = $_POST["dob"];

$q3 = "INSERT INTO student VALUES ('$name','$id');";
mysqli_query($conn,$q3);

?>

