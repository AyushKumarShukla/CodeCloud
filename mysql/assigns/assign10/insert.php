<?php
$conn = mysqli_connect('localhost','root','','company2');

if(isset($_POST['submit']))
{
	$name = $_POST['name'];
	$add = $_POST['add'];
	$ph = $_POST['ph'];
	$salary = $_POST['salary'];
	$cat = $_POST['cat'];
	$hin = $_POST['hin'];
	$eng = $_POST['eng'];
	$beng = $_POST['beng'];
	$lang="";
	if($hin)
		$lang=$lang."Hindi";
	if($eng)
		$lang=$lang.", "."English";			
	if($beng)
		$lang=$lang.", "."Bengali";		

	$ins = "INSERT INTO EMPLOYEE VALUES('$name','$add',$ph,$salary,'$cat','$lang')";
	$insres = mysqli_query($conn,$ins);
	echo "<h2>RECORD INSERTED SUCCESSFULLY</h2>";
}
?>
