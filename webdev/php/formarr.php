<?php
		$list = explode(' ', $_GET['array']);
		sort($list);	
		echo "<pre>";
		print_r($list);
		echo "</pre>";	
?>
