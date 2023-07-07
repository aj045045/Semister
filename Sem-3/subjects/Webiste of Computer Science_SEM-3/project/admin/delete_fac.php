<!-- // TODO: DELETE FACULTY DETAILS
-->
<?php 
include "config.php"; 
if (isset($_GET['id'])) {
    $user_name = $_GET['id'];
        $v_id=0;
    $sql = "SELECT FROM `faculty` WHERE `name`='$user_name";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $v_id=$row['facultyid'];
    
            }
}
    $sql = "DELETE FROM `research` WHERE `faculty_facultyid`='$v_id'";
    $res = $conn->query($sql);
    $sql = "DELETE FROM `faculty` WHERE `name`='$user_name'";
    $results = $conn->query($sql);
    $sql = "DELETE FROM `user` WHERE `username`='$user_name'";
    $result = $conn->query($sql);
    if ($results == TRUE && $result== TRUE && $res==TRUE) {
        echo "<div class=\"alert alert-success\" role=\"alert\">
        <h1> Account Deleted </h1></div>";
	header("Location: view.php");
    }else{
        echo "Error:" . $sql . "<br>" . $conn->error;
    }
} 
?>