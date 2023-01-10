<!-- // TODO: UPDATE FACULTY DETAILS
 -->
<!doctype html>
<html lang="en">
<head>
    <title>UPDATE</title>
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
            max-width:150px;
        }
</style>
</head>
<body style="background-color: #eee;">
    <div class="container vh-100">
            <div class="row d-flex justify-content-center align-items-center h-100">
                <div class="col-lg-7 col-xl-6">
                    <div class="card text-black" style="border-radius: 25px;">
                    <img src="image/logos/bgfreelogo.webp" class="card-img-top"
                    alt="department o computer science logos">
                    <h4 class="card-title " style="color: #657388;padding-left:10px">Maharishi pingla, School of advance
                        computing and
                        information technology</h4>
                        <div class="card-body">
                            <div class="row justify-content-center">
                                <div>
                                    <p class="text-center h1 fw-bold mb-2 mx-md-3 ">Edit</p>
                                    <form class="mx-1 mx-md-4" action="" method="POST">
                                    <?php
include "config.php";
if (isset($_POST['update'])) {
    $name = $_POST['name'];
    $year = $_POST['year'];
    $special = $_POST['special'];
    $post = $_POST['post'];
    $email = $_POST['email'];
    $contact = $_POST['contact'];
    $role="1"; 
    $sem="0"; 
    $v_id=sha1($name);
    $sql = "call update_user('$name','$year','$special','$post','$email','$contact','$role','$sem')";
    $result = $conn->query($sql);
    if ($result == true) {
        echo " <div class=\"alert alert-info\" role=\"alert\">
        ACCOUNT  UPDATED  <br> YOUR CHANGES ARE PERMANENT</div>";
        header("Location: view_fac.php");
        } else {
            echo "Error:" . $sql . "<br>" . $conn->error;
        }
    }

if (isset($_GET['id'])) {
    $v_id = $_GET['id'];
    $sql = "SELECT * FROM `faculty`";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $v_name = sha1($row['name']);
            if ($v_id == $v_name) {
                ?>
                                    <section class="vh-20" >
                                    <div class="d-flex flex-row align-items-center mb-2">
                                            <label for="exampleFormControlInput1" class="form-label">Faculty name:</label>
                                            <i class="fas fa-user fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="text" name="name" value="<?php echo $row['name']; ?>"  >
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <label for="exampleFormControlInput1" class="form-label">Experience:</label>
                                            <i class="fas fa-user fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="number" name="year" value="<?php echo $row['experience']; ?>"  >
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <label for="exampleFormControlInput1" class="form-label">Specialization:</label>
                                            <i class="fas fa-user fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="text" name="special" value="<?php echo $row['specialization']; ?>"  >
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <label for="exampleFormControlInput1" class="form-label">Designation</label>
                                            <i class="fas fa-user fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="text" name="post" value="<?php echo $row['designation']; ?>"  >
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                        <label for="exampleFormControlInput1" class="form-label">E-mail:</label>
                                            <i class="fas fa-envelope fa-lg me-5 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="email" name="email" value="<?php echo $row['email']; ?>"  >
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                        <label for="exampleFormControlInput1" class="form-label">Contact no:</label>
                                            <i class="fas fa-envelope fa-lg me-5 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="number" name="contact"  value="<?php echo $row['contact_no']; ?>"  >
                                            </div>
                                        </div>
                                        <?php
}
        }
    }
}
?>
                                        </div>
                                        <div class="d-flex justify-content-center mx-4 mb-2 mb-lg-0">
                                            <input type="submit" class="btn btn-primary" name="update"
                                                value="Submit" />
                                        </div>
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
