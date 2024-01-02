<style>
	table{
		width:60%;
		margin:15px auto;
		border-collapse:collapse;
	}
	h2{
		width:100%;
		text-align:center;
		margin:1% auto;
	}
	td,th{
		border:2px solid black;
		padding:1%;
	}
	#btn{
		position:fixed;
		bottom:10px;
		left:45%;
		display:block;
		width:10%;
		margin:20px auto;
		text-decoration:none;
		border:2px solid black;
		text-align:center;
		border-radius:10px;
		font-size:1rem;
		background-color:#b1ffff;
	}
	form{
		width:50%;
		margin:0px auto;
		text-align:left;
		display:grid;
		grid-template-columns:auto 1fr;
		grid-template-rows:auto 1fr;
		gap:20px;
		
	}
	.inp{
		display:contents;
		font-size:1em;
	}
</style>
<html>
<body>
	<h2>Student Information</h2>
	<table>
		<tr>
			<th>NAME</th>
			<th>ROLL</th>
			<th>CITY</th>
			<th>EMAIL</th>
			<th>DOB</th>
		</tr>
</body>
</html>
<?php
include 'view.php';
?>
<html>
<body>
	<form action="update.php" method="POST">
		<div class="inp">
			<label for="key">Enter Student's Roll No. To Modify Data: </label>
			<input type="number" name="key">
		</div>
		<div class="inp">
			<label for="name">Enter Name: </label>
			<input type="text" name="name">
		</div>
		<div class="inp">
			<label for="roll">Enter Roll Number: </label>
			<input type="number" name="roll">
		</div>
		<div class="inp">
			<label for="city">Enter City: </label>
			<input type="text" name="city">
		</div>
		<div class="inp">
			<label for="email">Enter Email: </label>
			<input type="text" name="email">
		</div>
		<div class="inp">
			<label for="dob">Enter DOB: </label>
			<input type="date" name="dob">
		</div>
		<input type="submit" name="submit" id="btn" value="Update">
	</form>
</body>
</html>
