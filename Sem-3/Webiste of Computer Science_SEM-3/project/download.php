<!-- //TODO: DOWNLOAD PDF DOCUMENT
-->
<?php
// TODO:For downloading pdf
if (isset($_POST['download-pdf'])) {
    $course = $_POST['course'];
    $sem = $_POST['sem'];
    $sql = "SELECT * FROM `syllabus`  where  `semister`='$sem' and `course_courseid`='$course'";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $id = $row['syllabusid'];
            header("Content-Type: application/octet-stream");
            $path = $row['document'] . ".pdf";
            echo base64_decode($row['document']);

// TODO: PDF DOWNLAOD
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

}
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-wEmeIV1mKuiNpC+IOBjI7aAzPcEZeedi5yW5f2yOq55WWLwNGmvvx4Um1vskeMj0" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <link rel="stylesheet" href="styles.css">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-p34f1UUtsS3wqzfto5wAAmdvj+osOnFyQFpp4Ua3gs/ZVWx6oOypYoCJhGGScy+8"
        crossorigin="anonymous"></script>
    <link rel="shortcut icon" href="image/logos/logo.webp" type="image/webp">
    <title>Depart. of Computer science</title>
    <style>
        th {
            text-align: center;
        }
    .btn-outline-primary{
        max-height:35px;
        color: #002147;;
    }
    .icon-input-btn{
        display:inline-block;
        position: relative;
    }
    .icon-input-btn input[type="submit"]{
        padding-left: 2em;
    }
    .icon-input-btn .fa{
        display: inline-block;
        position: absolute;
        left: 0.30em;
        top: 30%;
    }
    .view{
        padding:3% 10%;
    }
    @media only screen and (min-width: 800px) {
    .view{
        padding:2% 30%;
    }
}
    </style>
    <script>
        $(document).ready(function(){
            $(".icon-input-btn").each(function(){
                var btnFont = $(this).find(".btn").css("font-size");
                var btnColor = $(this).find(".btn").css("color");
                $(this).find(".fa").css({'font-size': btnFont, 'color': btnColor});
            });
        });
        </script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
<body>
    <!-- Scroll button -->
    <script defer src="footer & header.js"></script>
    <!-- Header -->
    <header id="header"></header>
    <div class="view">
        <br>
        <ul class="breadcrumb" style="padding-top:100px;">
            <li><a href="home.html">Home</a></li>
            <li>  Syllabus</li>
        </ul>
        <div class="pill">  Syllabus</div><br>
        <table class="table table-borderless">
            <thead class="thead-inverse" style="background-color:#034087;color:white;">
                <tr>
                    <th colspan="2">Doctor Of Philosophy (Ph.D)</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td class="row"><b>Semister 1 Syllabus :
                        <form action="">
                        <input type="hidden" name="course" value="1">
                        <input type="hidden" name="sem" value="1">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 2 Syllabus :<form action="">
                        <input type="hidden" name="course" value="1">
                        <input type="hidden" name="sem" value="2">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 3 Syllabus :<form action="">
                        <input type="hidden" name="course" value="1">
                        <input type="hidden" name="sem" value="3">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
            </tbody>
        </table>
        <table class="table table-borderless">
            <thead class="thead-inverse" style="background-color:#034087;color:white;">
                <tr>
                    <th colspan="2">M.Sc in Computer Science (M.Sc(cs))</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td class="row"><b>Semister 1 Syllabus :
                        <form action="">
                            <input type="hidden" name="course" value="2">
                            <input type="hidden" name="sem" value="1">
                            <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span>
                        </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 2 Syllabus :
                        <form action="">
                            <input type="hidden" name="course" value="2">
                            <input type="hidden" name="sem" value="2">
                            <form action="">
                        <input type="hidden" name="course" value="msc(cs)">
                        <input type="hidden" name="sem" value="3">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                        </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 3 Syllabus :
                        <form action="">
                        <input type="hidden" name="course" value="2">
                        <input type="hidden" name="sem" value="3">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
            </tbody>
        </table>
        <table class="table table-borderless">
            <thead class="thead-inverse" style="background-color:#034087;color:white;">
                <tr>
                    <th colspan="2">
                        M.Sc in Artificial Intelligence & Machine Learning (M.Sc(AI & ML))</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td class="row"><b>Semister 1 Syllabus :<form action="">
                        <input type="hidden" name="course" value="3">
                        <input type="hidden" name="sem" value="1">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 2 Syllabus :<form action="">
                        <input type="hidden" name="course" value="3">
                        <input type="hidden" name="sem" value="2">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 3 Syllabus :<form action="">
                        <input type="hidden" name="course" value="3">
                        <input type="hidden" name="sem" value="3">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
            </tbody>
        </table>
        <br><br><br>
        <table class="table table-borderless">
            <thead class="thead-inverse" style="background-color:#034087;color:white;">
                <tr>
                    <th colspan="2">
                        Master of Technology in network & communication (M.tech-nc)</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td class="row"><b>Semister 1 Syllabus :<form action="">
                        <input type="hidden" name="course" value="4">
                        <input type="hidden" name="sem" value="1">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 2 Syllabus :<form action="">
                        <input type="hidden" name="course" value="4">
                        <input type="hidden" name="sem" value="2">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 3 Syllabus :<form action="">
                        <input type="hidden" name="course" value="4">
                        <input type="hidden" name="sem" value="3">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
            </tbody>
        </table>
        <br><br><br>
        <table class="table table-borderless">
            <thead class="thead-inverse" style="background-color:#034087;color:white;">
                <tr>
                    <th colspan="2">
                        Master of Technology in web Technology (M.tech-wt)</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td class="row"><b>Semister 1 Syllabus :<form action="">
                        <input type="hidden" name="course" value="5">
                        <input type="hidden" name="sem" value="1">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 2 Syllabus :<form action="">
                        <input type="hidden" name="course" value="5">
                        <input type="hidden" name="sem" value="2">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 3 Syllabus :<form action="">
                        <input type="hidden" name="course" value="5">
                        <input type="hidden" name="sem" value="3">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
            </tbody>
        </table>
        <br><br><br>
        <table class="table table-borderless">
            <thead class="thead-inverse" style="background-color:#034087;color:white;">
                <tr>
                    <th colspan="2">
                        Master Of Computer Applications (MCA)</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td class="row"><b>Semister 1 Syllabus :<form action="">
                        <input type="hidden" name="course" value="6">
                        <input type="hidden" name="sem" value="1">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 2 Syllabus :<form action="">
                        <input type="hidden" name="course" value="6">
                        <input type="hidden" name="sem" value="2">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 3 Syllabus :<form action="">
                        <input type="hidden" name="course" value="6">
                        <input type="hidden" name="sem" value="3">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
            </tbody>
        </table>
        <br><br><br>
        <table class="table table-borderless">
            <thead class="thead-inverse" style="background-color:#034087;color:white;">
                <tr>
                    <th colspan="2">
                        Post Graduate Diploma in Computer Science & Applications (PGDCSA)</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td class="row"><b>Semister 1 Syllabus :<form action="">
                        <input type="hidden" name="course" value="7">
                        <input type="hidden" name="sem" value="1">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
                <tr>
                    <td class="row"><b>Semister 2 Syllabus :<form action="">
                        <input type="hidden" name="course" value="7">
                        <input type="hidden" name="sem" value="2">
                        <span class="icon-input-btn"><i class="fa fa-download"></i>
                        <input type="submit" class="btn btn-outline-primary" name="download-pdf" value="  Downloads"></b></td>
                            </span></b></td>
                    </form>
                    <td></td>
                </tr>
            </tbody>
        </table>
        <br><br><br>
    </div>
    <footer id="footer"></footer>
</body>
</html>
