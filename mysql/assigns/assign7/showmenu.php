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
			padding:2%;
			border:2px solid black;
			text-align:left;
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
	<h2>CHECKOUT</h2>
	<form action='order.php' method='POST'>
	<table>
	<tr>
	<th>ITEM</th>
	<th>PRICE</th>
	<th>QUANTITY</th>
	</tr>
</body>
</html>
<?php
$conn = mysqli_connect("localhost","root","","eatery");
if(!$conn)
	echo "CONNECTION FAILED";

$show = "SELECT * FROM MENU;";
$res = mysqli_query($conn,$show);
$rows = mysqli_num_rows($res);
$cnt=1;
if($rows != 0)
{
	while($row = mysqli_fetch_assoc($res))
	{
		echo "<tr>\n";
		echo "<td>".$row['ITEM']."</td>";
		echo "<td>".$row['PRICE']."</td>";
		$name = "item".$cnt;
		echo "<td>"."<input type='number' min='0' max='10' value='0' name='$name'>"."</td>\n";
		echo "</tr>\n";
		$cnt = $cnt + 1;
	}
	echo "</table>\n";
	echo "Enter Your Name: <input type='text' name='cname'>";
	echo "<input type='submit' value='Order Now!' name='submit'>";
	echo "</form>\n";
}
?>
