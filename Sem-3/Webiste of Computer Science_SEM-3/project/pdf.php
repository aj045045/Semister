<?php
// TODO:For downloading pdf
if (isset($_POST['download-pdf'])) {
    $course = $_POST['course'];
    $sem = $_POST['sem'];
    $sql = "SELECT `document` FROM `syllabus`  where  `semister`='$sem' and `course_courseid`='$course'";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $id = $row['syllabusid'];
            header("Content-Type: application/octet-stream");
            $path = $row['document'] . ".pdf";
            echo base64_decode($row['document']);
            //! DOWNLOAD PDF CODE
            header("Content-Disposition: attachment; filename=" . urlencode($path));
            header("Content-Type: application/download");
            header("Content-Description: File Transfer");
            header("Content-Length: " . filesize($path));
            flush();
            $fp = fopen($path, "r");
            while (!feof($fp)) {
                echo fread($fp, 65536);
                flush();
            }
            fclose($fp);
        }
    }
}
?>