<!-- // TODO: DELETE STUDENT DETAILS
-->
<?php 
include "config.php"; 
if (isset($_GET['id'])) {
    $user_name = $_GET['id'];
    $sql = "DELETE FROM `student` WHERE `studentname`='$user_name'";
    $results = $conn->query($sql);
    $sql = "DELETE FROM `user` WHERE `username`='$user_name'";
    $result = $conn->query($sql);
    if ($results == TRUE && $result== TRUE) {
        echo "<div class=\"alert alert-success\" role=\"alert\">
        <h1> Account Deleted </h1></div>";
	header("Location: view.php");
    }else{
        echo "Error:" . $sql . "<br>" . $conn->error;
    }
} 
?>