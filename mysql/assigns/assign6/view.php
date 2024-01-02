<?php
include 'conn.php';

$view = "SELECT * FROM STUDENT;";
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
