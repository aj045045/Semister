<!doctype html>
<html lang="en">

<head>
    <title>Sign up</title>
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
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.1/jquery.min.js"></script>
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

    .text-primary:link {
        text-decoration: none;
    }

    .text-primary:hover {
        text-decoration: underline;
    }

    .linkers {
        display: block;
        margin-left: auto;
        margin-right: auto;
        width: 60%;
        display: block;
    }
    </style>
    <script>
       
$(document).ready(function(){
  $("#hide").hover(function(){
    $("#option").hide();
  });
  $("#show").click(function(){
    $("#option").show();
  });
  $("#forcehide").click(function(){
    $("#option").hide();
  });

});
</script>
</head>

<body style="background-color: #eee" id="hide">
    <section class="vh-100">
        <div class="container h-100">
            <div class="row d-flex justify-content-center align-items-center h-100 ">
                <div class="col-lg-7 col-xl-6">
                    <div class="card text-black" style="border-radius: 25px;">
                        <img src="image/logos/bgfreelogo.webp" class="card-img-top"
                            alt="department o computer science logos">
                        <h4 class="card-title " style="color: #657388;padding-left:10px;">Maharishi pingla, School of
                            advance
                            computing and
                            information technology</h4>
                        <div class="card-body">
                            <?php require_once "manage.php";
echo $error;?>
                            <div class="row justify-content-center">
                                <div>
                                    <p class="text-center h1 fw-bold mb-2 mx-md-3 ">Sign up</p>
                                    <!--TODO: Form for sign-up -->
                                    <form action="regist.php" method="POST" id="form">
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <i class="fas fa-user fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input type="text" id="form3Example1c" class="form-control"
                                                    placeholder="User Name" name="name" minlength="4" required
                                                    autocomplete="off" />
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <i class="fas fa-envelope fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input type="email" id="to_name" name="to_name" class="form-control"
                                                    placeholder="Mail" required autocomplete="off" />
                                            </div>
                                        </div>
                                        <!-- reply_to -->
                                        <input type="hidden" name="message" id="message"
                                            value="<?php echo (rand(00000, 99999)); ?>">
                                        <div class="row ms-3 mb-2">
                                            User is a:<div>
                                            </div>
                                            <div class="row">
                                                <div class="col-1"></div>
                                                <div class="col-3">
                                                    <input class="form-check-input" type="radio" id="forcehide" value="1" name="role">
                                                    Faculty
                                                    <br>
                                                    <input class="form-check-input" type="radio" id="show" value="2" name="role">
                                                    Student <div class="d-flex flex-row mb-2">
                                                        <div class="form-outline flex-fill mb-0" >
                                                            <select class="form-select" required  id="option" style="display:none" autocomplete="off" name="course">
                                                                <option selected disabled value="0" id="option">Course</option>
                                                                <option value="1">Doctor of Philosophy [ PHD ]</option>
                                                                <option value="2">Master of Science in Computer Science [ MSC(cs) ]</option>
                                                                <option value="3">Artificial Intelligence & Machine Learning [ AIML ]</option>
                                                                <option value="4">M. Tech in Networking & Communication [ M.TECH NC ]</option>
                                                                <option value="5">M. Tech in Web Technology [ M.TECH WT ]</option>
                                                                <option value="6">Masters in Computer Application [ MCA ]</option>
                                                                <option value="7"> Post Graduate Diploma in Computer Science and Applications [ PGDCSA ]</option>
                                                            </select>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <i class="fas fa-lock fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input type="password" class="form-control" placeholder="Password"
                                                    name="password" minlength="6" maxlength="10" required
                                                    autocomplete="off" />
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <i class="fas fa-lock fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input type="password" class="form-control" placeholder="Confirm your password"
                                                    name="cpassword" minlength="6" maxlength="10" required
                                                    autocomplete="off" />
                                            </div>
                                        </div>
                                        <div class="d-flex flex-row align-items-center mb-2">
                                            <i class="fas fa-lock fa-lg me-3 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input type="number" class="form-control" placeholder="Contact number"
                                                    name="contacts"  required autocomplete="off" />
                                            </div>
                                        </div>
                                        <div class="d-flex justify-content-center mx-4 mb-2 mb-lg-0">
                                            <input type="submit" class="btn btn-primary" name="sign-up"
                                                value="Submit" />
                                        </div>
                                        <div class="linkers">Already have an account?<a class="text-primary"
                                                href="signin.php" target="_self"> Signin now</a></div>
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