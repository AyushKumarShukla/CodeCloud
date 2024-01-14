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
		text-align:center;
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
	<h2>SALARY INFORMATION</h2>
	<table>
		<tr>
			<th>EID</th>
			<th>BASIC</th>
			<th>HRA%</th>
			<th>DA%</th>
			<th>TAX%</th>
			<th>HRA</th>
			<th>DA</th>
			<th>TAX</th>
		</tr>
</body>
</html>
<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
$conn = mysqli_connect('localhost','root','','company');
mysqli_query($conn,"TRUNCATE TABLE SALARY");

$input = "SELECT * FROM EMPLOYEE;";
$inputres = mysqli_query($conn,$input);

while($row=mysqli_fetch_row($inputres))
{
	$eid=$row[0];
	$basic=$row[1];
	$HRAP=$row[2];
	$DAP=$row[3];
	$TAXP=$row[4];

	$hra = ($basic * $HRAP)/100;
	$da = ($basic * $DAP)/100;
	$tax = (($basic+$hra+$da) * $TAXP)/100;

	$output = "INSERT INTO SALARY VALUES($eid,$basic,$HRAP,$DAP,$TAXP,$hra,$da,$tax);";
	mysqli_query($conn,$output);

}


$view = "SELECT * FROM SALARY;";
$viewres = mysqli_query($conn,$view);
$viewresrows = mysqli_num_rows($viewres);
if($viewresrows!=0)
{
        while($row=mysqli_fetch_assoc($viewres))
        {
                echo "<tr>";
                foreach($row as $value)
                {
                        echo "<td>"."$value"."</td>";
                }
                echo "</tr>";
        }
        echo "</table>";
}
else
        echo "No Records Found";
?>
