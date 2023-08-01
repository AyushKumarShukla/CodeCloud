<?php
                  $array = explode(" " , $_GET['array']); //get array from html form text input
                  $count=count($array); //get the length of the entered array
                  for($i=0;$i<$count;$i++)
                  {
                         for($j=0;$j<$count-1-$i;$j++)
                         {
                                  if($array[$j]>$array[$j+1])
				  {
					 //swapping procedure
                                         $temp=$array[$j];
                                         $array[$j]=$array[$j+1];
                                         $array[$j+1]=$temp;
                                  }
                         }
                 }
                 echo "Sorted Array(In Increasing Order): ";
		 echo "<br>";
		 echo "<pre>";
		 print_r($array);
		 echo "</pre>";
?>
