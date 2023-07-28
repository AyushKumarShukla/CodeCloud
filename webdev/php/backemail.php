<?php
if (isset($_GET['name']) && isset($_GET['email'])) {
    $name = $_GET['name'];
    $email = $_GET['email'];

    // Send the email
    $to = 'spositive123@gmail.com'; // Replace with your email address
    $subject = 'Form Submission';
    $message = "Name: $name\nEmail: $email";
    $headers = 'From: ayushCoder' . "\r\n" .
               'Reply-To: ayushCoder' . "\r\n" .
               'X-Mailer: PHP/' . phpversion();

    // Use mail() function to send the email
    mail($to, $subject, $message, $headers);

    // Output the submitted data on the page
    echo "<h1>Submitted Form Data</h1>";
    echo "<p>Name: $name</p>";
    echo "<p>Email: $email</p>";
} else {
    echo "<p>No form data submitted.</p>";
}
?>

