<?php 
include "config.php"; 
if (isset($_GET['id'])) {
    $research_id = $_GET['id'];
    $sql = "SELECT * FROM `research`WHERE `researchid`='$research_id'";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $ret=sha1($row['faculty_facultyid']);
        }
    }
    $result->close();
    $sql = "DELETE FROM `research` WHERE `researchid`='$research_id'";
    $result = $conn->query($sql);
    if ($result== TRUE) {
        echo "<div class=\"alert alert-success\" role=\"alert\">
        <h1> Account Deleted </h1></div>";
	header("Location: research_fac.php?id=$ret");
    }else{
        echo "Error:" . $sql . "<br>" . $conn->error;
    }
} 
?>