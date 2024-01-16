<html>
<head>
	<title>MENU</title>
	<style>
		h2{
			width:100%;
			text-align:center;
			font-family:consolas;
			margin:4% auto;
		}
		form{
			width:50%;
			margin:2% auto;
		}
		table{
			width:100%;
			border-collapse:collapse;
		}
		th{
			background-color:gray;
		}
		th,td{
			padding:2% 0%;
			border:2px solid black;
			text-align:center;
		}
		input[type="submit"]{
			width:20%;
			margin:4% 40%;
		}	
		#cname{
			text-align:center;
		}
	</style>
</head>
<body>
	<h2>EMPLOYEE DETAILS</h2>
	<table>
		<tr>
		<th>NAME</th>
		<th>ADDRESS</th>
		<th>PHONE</th>
		<th>SALARY</th>
		<th>CATEGORY</th>
		<th>LANGUAGE</th>
	</tr>
</body>
</html>

<?php
$conn = mysqli_connect('localhost','root','','company2');
$orderby = $_POST['order'];
$view = "SELECT * FROM EMPLOYEE ORDER BY $orderby;";
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

