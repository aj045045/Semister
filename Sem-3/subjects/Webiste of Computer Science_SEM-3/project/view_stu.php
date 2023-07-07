<!doctype html>
<html lang="en">
<head>
    <title>View </title>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <!-- Bootstrap CSS v5.2.1 -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">
</head>
<style>
.card-img-top {
    margin: 1ch 30%;
    max-width: 150px;
}
</style>
<body>
    <section class="vh-100" style="background-color: #eee;">
        <div class="container h-100">
            <div class="row d-flex justify-content-center align-items-center h-100">
                <div class="col-lg-7 col-xl-6">
                    <div class="card text-black" style="border-radius: 25px;">
                        <img src="image/logos/bgfreelogo.webp" class="card-img-top"
                            alt="department o computer science logos">
                        <h4 class="card-title " style="color: #657388;padding-left:10px">Maharishi pingla, School of
                            advance
                            computing and
                            information technology</h4>
                        <div class="card-body">
                            <div class="row justify-content-center">
                                <div>
                                    <p class="text-center h1 fw-bold mb-2 mx-md-3 ">Account</p>
                                    <?php
include "config.php";
if (isset($_POST['submit'])) {
    $name = $_POST['delete'];
    $sql = "DELETE FROM `student` WHERE `studentname`='$name'";
    $result = $conn->query($sql);
    $sql = "DELETE FROM `user` WHERE `username`='$name'";
    $results = $conn->query($sql);
    if ($result == true && $results == true) {
        session_stop();
        echo "<script>
                                        setTimeout(function() {
                                            window.open('signin.php', '_self');
                                        }, 2000);
                                    </script>
                                        <div class=\"alert alert-info alert-dismissible fade show\" role=\"alert\">
                                        <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
                                        Your account is deleted
                                        </div>";
    } else {
        echo "
                                        <div class=\"alert alert-danger alert-dismissible fade show\" role=\"alert\">
                                        <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
                                        Something went wrong <br> Try after some time to delete your account
                                        </div>";
    }
}
include "config.php";
if (isset($_GET['id'])) {
    $v_id = $_GET['id'];
    $sql = "SELECT * FROM `student`";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $v_name = sha1($row['studentname']);
            if ($v_id == $v_name) {
                ?>
                                    <form class="mx-1 mx-md-4" action=" " method="POST">
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <label for="exampleFormControlInput1" class="form-label">Student
                                                name:</label>
                                            <i class="fas fa-user fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="text"
                                                    value="<?php echo $row['studentname']; ?>"
                                                    aria-label="Disabled input example" disabled readonly>
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <label for="exampleFormControlInput1" class="form-label">Joining
                                                year:</label>
                                            <i class="fas fa-envelope fa-lg me-4 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="text"
                                                    value="<?php echo $row['batch_year']; ?>"
                                                    aria-label="Disabled input example" disabled readonly>
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <label for="exampleFormControlInput1" class="form-label">Semister:</label>
                                            <i class="fas fa-envelope fa-lg me-4 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="text"
                                                    value="<?php echo $row['semister']; ?>"
                                                    aria-label="Disabled input example" disabled readonly>
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <label for="exampleFormControlInput1" class="form-label">E-mail:</label>
                                            <i class="fas fa-lock fa-lg me-5 ps-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="text"
                                                    value="<?php echo $row['email'] ?>"
                                                    aria-label="Disabled input example" disabled readonly>
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <label for="exampleFormControlInput1" class="form-label">Contact no:</label>
                                            <i class="fas fa-envelope fa-lg me-4 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input class="form-control" type="text"
                                                    value="<?php echo $row['contact_no']; ?>"
                                                    aria-label="Disabled input example" disabled readonly>
                                            </div>
                                        </div>
                                        <div class="d-flex justify-content-center mx-4">
                                            <a class="btn btn-primary"
                                                href="update_stu.php?id=<?php echo sha1($row['studentname']); ?>">Edit</a>&nbsp;
                                            <form action="" method="post">
                                                <input type="hidden" value="<?php echo sha1($row['studentname']); ?>"
                                                    name="delete">
                                                <input type="submit" class="btn btn-danger" value="Delete">
                                            </form>
                                        </div>
                                        <div class="row ">
                                            <div class="d-flex col justify-content-center  mx-4 my-2">
                                                <a class="btn btn-outline-danger"
                                                    href="http://localhost/php/department/project/">Sign out</a>
                                            </div>
                                        </div>
                                    </form>
                                    <?php
}
        }
    }
}
?>
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