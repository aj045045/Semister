<!-- //TODO: ADMIN VIEW
-->
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
                                                                                                <!-- // ? ADD ADMIN MEMBER -->
                                                    <a class="btn " href="add.php"><img src="image/logos/add.png" style="width:25px; border-radius:50%"></a>&nbsp;
                                    <p class="text-center h1 fw-bold mb-2 mx-md-3 ">Admin</p>
                                    <div class="d-flex justify-content-center mx-4 mb-3 mb-lg-4">
                                        <div class="container">
                                            <div class="row">
                                                <div class=" col-2 ">
                                                </div>
                                                <div class=" col-4 ">
                                                    <a class="btn btn-primary" href="view_fac.php">View
                                                        Faculty</a>&nbsp;
                                                </div>
                                                <div class="   col-4 ">
                                                    <a class="btn btn-primary" href="view_stu.php">View Student</a>
                                                </div>
                                            </div>
                                                <div class="row ">
                                                                                                                                <!-- //?LOG OUT -->
                                                    <div class="d-flex col justify-content-center  mx-4 my-3 mb-lg-4">
                                                    <a class="btn btn-outline-danger" href="http://localhost/php/department/project/signin.php">Sign out</a>
                                                </div>
                                                </div>
                                        </div>
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