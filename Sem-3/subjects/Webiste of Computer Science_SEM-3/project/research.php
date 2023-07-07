<?php
include "config.php";
if (isset($_GET['id'])) {
    $v_id = $_GET['id'];
    $sql = "SELECT * FROM `faculty`";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $v_name=sha1($row['name']);
            if($v_id==$v_name) {
                $_SESSION['fac_id']=$row['facultyid'];
                $_SESSION['fac_name']=$row['name'];
                $ers=sha1($_SESSION['fac_id']);
            }
        }
        }
    }
if(isset($_POST['research'])){
    $title=$_POST['title'];
    $journal=$_POST['journal'];
    $year=$_POST['year'];
    $publisher=$_POST['publisher'];
    $fac=$_SESSION['fac_id'];
    $sql="INSERT INTO `research`(`researchyear`,`title`,`journal`,`publisher`,`faculty_facultyid`) values('$year','$title','$journal','$publisher','$fac')";
    $result = $conn->query($sql);
    $conn->close();
}
    ?>
<!doctype html>
<html lang="en">
<head>
    <title>Title</title>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <!-- Bootstrap CSS v5.2.1 -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">
    <!-- Bootstrap JavaScript Libraries -->
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.6/dist/umd/popper.min.js"
        integrity="sha384-oBqDVmMz9ATKxIep9tiCxS/Z9fNfEXiDAYTujMAeBAsjFuCZSmKbSSUnQlmh/jp3" crossorigin="anonymous">
    </script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.min.js"
        integrity="sha384-7VPbUDkoPSGFnVtYi0QogXtr74QeVeeIs99Qfg5YCF+TidwNdjvaKZX19NZ/e6oz" crossorigin="anonymous">
    </script>
    <style>
    input[type=number]::-webkit-outer-spin-button,
    input[type=number]::-webkit-inner-spin-button {
        -webkit-appearance: none;
        margin: 0;
    }
    .card-img-top {
        margin: 1ch 30%;
        max-width: 150px;
    }
    </style>

</head>
<body style="background-color: #eee">
    <section class="v-100 p-3" >
        <div class="container h-100">
            <div class="row d-flex justify-content-center align-items-center h-100 ">
                <div class="col-lg-7 col-xl-6">
                    <div class="card text-black" style="border-radius: 25px; ">
                        <img src="image/logos/bgfreelogo.webp" class="card-img-top" 
                            alt="department of computer science logos">
                        <h4 class="card-title " style="color: #657388;padding-left:10px;">Maharishi pingla, School of
                            advance
                            computing and
                            information technology</h4>
                        <div class="card-body">
                            <?php require_once "manage.php";
echo $error;?>
                            <div class="row justify-content-center">
                                <div>
                                <a class="primary ms-1 " href="research_fac.php?id=<?php echo $ers;?>">Research Details</a> <p class="text-center h1 fw-bold mb-2 mx-md-3 ">Add research </p>
                                    <!--TODO: Form for sign-up -->
                                    <form action="" method="post">
                                        <div class="w-75 ms-lg-5 ps-lg-5 mt-4 mb-2 align-content-center">
                                            <input type="text" class="form-control" name="title" placeholder="Title of the research" maxlength="50" required
                                                autocomplete="off" />
                                        </div>
                                        <div class="w-75 ms-lg-5 ps-lg-5 mb-2 align-content-center">
                                            <input type="text" class="form-control" name="journal" placeholder="Detail of research" maxlength="100"
                                                required autocomplete="off" />
                                        </div>
                                        <div class="w-75 ms-lg-5 ps-lg-5 mb-2 align-content-center">
                                            <input type="number" class="form-control" name="year" placeholder="Period in years" 
                                                required autocomplete="off" />
                                        </div>
                                        <div class="w-75 ms-lg-5 ps-lg-5 mb-2 align-content-center">
                                            <input type="text" class="form-control" name="publisher" placeholder="Name of publisher" maxlength="100"
                                                required autocomplete="off" />
                                        </div>
                                        <input type="hidden" name="fac" value="">
                                        <div class="d-flex justify-content-center mx-4 mb-0 mb-lg-0">
                                            <input type="submit" class="btn btn-primary" name="research"
                                                value="Submit" />
                                        </div>
                                    </form>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>
</body>
</html>