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
</head>
<body>
    <!-- Scroll button -->
    <script defer src="footer & header.js"></script>
    <!-- Header -->
    <header id="header"></header>
    <div style="padding-right:7%;padding-left:7%;">
        <ul class="breadcrumb" style="padding-top:150px">
            <li><a href="home.html">Home</a></li>
            <li><a href="faculty.html">Faculty</a></li>
            <li>Dr. Hardik Joshi</li>
        </ul>
        <div class="container-fluid">
            <div class="bg_img">
                <img class="center" src="image/logos/logo.webp" style="height: auto;width: 90px; padding-bottom: 60px;">
                <img class="center" src="image/logos/admin.webp" style="border-radius:50%;">
                <h4 class="pr_center">Dr. HARDIK JOSHI</h4>
                <p class="pr_center">Professor & Lecturer</p>
                <p class="pr_center">B.Sc.(Computer Science), M. Sc.(Computer Science), Ph. D.(Computer Science)</p>
            </div><br><br>
            <div class="fd-center">
            <!-- Experinc-->
            <div class=" pill ">
                <h5>Teaching Experience</h5>
            </div><br>
            <table class="table table-borderless table-inverse table-responsive">
                <thead class="thead-inverse" style="background-color:cadetblue;color:white;">
                    <tr>
                        <th>YEAR</th>
                        <th>ORGANIZATION</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td scope="row"> 2005 </td>
                        <td>
                            <dd>
                            <dt>LECTURER & HEAD OF THE DEPARTMENT</dt>
                            <dl>Parul University</dl>
                            </dd>
                        </td>
                        <td></td>
                    </tr>
                    <tr>
                        <td scope="row"> 2005 </td>
                        <td>
                            <dd>
                            <dt>ASSISTANT PROFESSOR</dt>
                            <dl>Gujarat University</dl>
                            </dd>
                        </td>
                        <td></td>
                    </tr>
                    <tr>
                        <td scope="row"> 2004 </td>
                        <td>
                            <dd>
                            <dt>Teaching Assistant</dt>
                            <dl>Bhavnagar University</dl>
                            </dd>
                        </td>
                        <td></td>
                    </tr>
                    <tr>
                        <td scope="row"> 2005 </td>
                        <td>
                            <dd>
                            <dt>LECTURER (AFFILICATED)</dt>
                            <dl>Saurashtra University</dl>
                            </dd>
                        </td>
                        <td></td>
                    </tr>
                </tbody>
            </table>
            <br><br>
            <!-- AWARDS -->
<!-- AWARDS -->
            <div class="pill ">
                <h5>Awards</h5>
            </div><br>
            <table class="table table-borderless table-responsive">
                <thead class="thead-inverse" style="background-color:cadetblue;color:white;">
                    <tr>
                        <th>ORGANIZATION</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td scope="row">March 2014 </td>
                        <td>
                            <dd>
                            <dt>NIXI FELLOWSHIP</dt>
                            <dl>New Delhi</dl>
                            </dd>
                        </td>
                        <td></td>
                    </tr>
                    <tr>
                        <td scope="row">October 2018 </td>
                        <td>
                            <dd>
                            <dt>JURY-NATIONAL LEVEL</dt>
                            <dl>New Delhi</dl>
                            </dd>
                        </td>
                        <td></td>
                    </tr>
                    <tr>
                        <td scope="row"> 2015-2016 </td>
                        <td>
                            <dd>
                            <dt>TREASURER</dt>
                            <dl>Gandhinagar</dl>
                            </dd>
                        </td>
                        <td></td>
                    </tr>
                    <tr>
                        <td scope="row"> 2017-19 </td>
                        <td>
                            <dd>
                            <dt>VICE CHAIR</dt>
                            <dl>Gandhinagar</dl>
                            </dd>
                        </td>
                        <td></td>
                    </tr>
                </tbody>
            </table>
            <br><br>
<?php
include "config.php";
$sql = "SELECT count(`title`) as paper FROM `research` where `faculty_facultyid` =4";
$result = $conn->query($sql);
$total = 2;
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $paper = $row['paper'];
        $total = $paper;
    }
}
?>
                <!-- RESEARCH -->
                <div class="pill "> Research Works</div>
                <br>
                <table class="table table-borderless table-responsive">
                    <thead class="thead-inverse" style="background-color:cadetblue;color:white;">
                        <tr>
                            <th>CATEGORY</th>
                            <th></th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr>
                            <td colspan="2" style="text-align:center;">No of Publication <span
                                    class="badge bg-danger"><?php echo $total; ?></span></td>
                        </tr>
                        <tr>
                            <td scope="row">Research paper</td>
                            <td><b><?php echo $paper ?></b></td>
                        </tr>
                        <tr>
                            <td scope="row">Books</td>
                            <td><b>0</b></td>
                        </tr>
                        <tr>
                            <td scope="row">Books Chapter</td>
                            <td><b>0</b></td>
                        </tr>
                    </tbody>
                </table>
            <br><br>
        </div>
    </div>
</div>
    <br><br><br>
    <footer id="footer"></footer>
</body>
</html>