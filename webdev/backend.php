<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $data = $_POST['data'];
    $file = fopen('data.txt', 'a');
    fwrite($file, $data . PHP_EOL);
    fclose($file);
    echo 'Data saved successfully!';
}
?>
