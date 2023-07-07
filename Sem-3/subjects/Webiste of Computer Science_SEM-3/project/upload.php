<?php
include "config.php";
if(isset($_POST['submit']))
{
    $course= $_POST['course'];
    // $year= $_POST['year'];
    $sem= $_POST['sem'];
    $doc= $_POST['docs'];
    $sql = "INSERT INTO `syllabus`(`document`,`semister`,`course_courseid`)values('$doc','$sem','$course')";
    $result = $conn->query($sql);
    // $up="INSERT INTO `course`(`coursename`,`year`)values('$course','$year')";
    // $result = $conn->query($up);
    if($result == TRUE){
        echo"UPLOADED";
    }else{
        echo "Error:". $sql . "<br>". $conn->error;
    } 
    $conn->close();
}
?>
<!DOCTYPE html>
<html>
<body>
<p>Click on the "Choose File" button to upload a file:</p>
<form action="" method="POST">
    <input type="number"  name="course" placeholder="course">
    <!-- <input type="number"  name="year" placeholder="year"> -->
    <input type="number"  name="sem" name="semister"  placeholder="sem">
<input type="file"  name="docs" accept=".pdf">
<input type="submit" name="submit">
</form>
</body>
</html>