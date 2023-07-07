<!-- // TODO: ADD ADMIN FORM 
-->
<!doctype html>
<html lang="en">
<head>
    <title>SIGN IN</title>
    <!-- Requireds meta tags -->
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
.card-img-top {
            margin: 1ch 30%;
            max-width:150px;
        }
.text-primary:link{
    text-decoration:none;
}
.text-primary:hover{
    text-decoration:underline;
}
.linkers{
  display: block;
  margin-left: auto;
  margin-right: auto;
  width: 60%;
  display: block;
}
</style>
</head>
</head>
<body style="background-color: #eee">
    <section class="vh-100" >
        <div class="container h-100">
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
                                    <p class="text-center h1 fw-bold mb-4 mx-md-3 "> Sign up for Admin </p>
                                    <form class="mx-1 mx-md-4" action="manage.php" method="POST">
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <i class="fas fa-user fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input type="text" id="form3Example1c" class="form-control"
                                                placeholder="User Name" name="name" required autocomplete="off"/>
                                        </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <i class="fas fa-lock fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input type="password" id="form3Example4c" class="form-control"
                                                    placeholder="Password" name="password"  minlength="6" required autocomplete="off"/>
                                            </div>
                                        </div>
                                        <input type="hidden" name="role" value="3">
                                        <div class="d-flex justify-content-center mx-4 mb-3 mb-lg-4">
                                            <input type="submit" class="btn btn-primary " name="sign-up"
                                                value="submit" />
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
