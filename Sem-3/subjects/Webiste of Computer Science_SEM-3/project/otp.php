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
    </style>
</head>

<body style="background-color: #eee">
    <section class="vh-100">
        <div class="container h-100">
            <div class="row d-flex justify-content-center align-items-center h-100 ">
                <div class="col-lg-7 col-xl-6">
                    <div class="card text-black" style="border-radius: 25px;">
                        <div class="card-body">
                            <?php  require_once "manage.php";
                            echo $error;?>
                            <div class="row justify-content-center">
                                <div>
                                    <p class="text-center h1 fw-bold mb-2 mx-md-3 " style="padding-bottom:20px">Code
                                        Verification</p>
                                    <form action="otp.php" method="POST">
                                        <p>To get otp in <i><?php echo $_SESSION['email']?></i> please click send otp</p>
                                    <div class="d-flex flex-row align-items-center mb-2">
                                            <i class="fas fa-lock fa-lg ms-2 fa-fw"></i>
                                            <div class="form-outline flex-fill mb-0">
                                                <input type="number" id="form3Example4c" class="form-control"
                                                    placeholder="Enter verification code that we have mailed" name="otp"
                                                     required autocomplete="off" />
                                            </div>
                                        </div>
                                        <div class="container">
                                            <div class="row">
                                                <div class="col-4">
                                            <div class="d-flex justify-content-end mx-4 mb-2 mb-lg-0">
                                                <input type="submit" class="btn btn-primary " name="otp-verif"
                                                value="submit" />
                                            </div>
                                            </div>
                                                <div class="col-4" style="padding-left:150px">
                                    </form>
                                    <form id="form">
                                        <input type="hidden" name="from_name" id="from_name" value="Department of computer science">
                                        <input type="hidden" name="to_name" id="to_name" value="<?php echo $_SESSION['email']?>">
                                        <input type="hidden" name="message" id="message" value="<?php echo $_SESSION['code']?>">
                                        <input type="hidden" name="reply_to" id="reply_to" values="">
                                        <div class="d-flex justify-content-start mx-4 mb-2 mb-lg-0">
                                            <input type="submit" class="btn btn-primary" id="otp-submit" name="otp-submit" value="Send otp">
                                        </div>
                                    </form>
                                            </div>
                                        </div>
                                    </div>
                                    <script type="text/javascript"
                                        src="https://cdn.jsdelivr.net/npm/@emailjs/browser@3/dist/email.min.js">
                                    </script>
                                    <script type="text/javascript">
                                    emailjs.init('0xJaVX_gNOdYk8Vh_')
                                    </script>
                                    <script>
                                    const btn = document.getElementById('otp-submit');
                                    document.getElementById('form')
                                        .addEventListener('submit', function(event) {
                                            event.preventDefault();
                                            btn.value = 'Sending...';
                                            const serviceID = 'default_service';
                                            const templateID = 'template_gc0zx8g';
                                            emailjs.sendForm(serviceID, templateID, this)
                                                .then(() => {
                                                    btn.value = 'Send Email';
                                                    alert('E-mail Sent!');
                                                }, (err) => {
                                                    btn.value = 'Send Email';
                                                    alert(JSON.stringify(err));
                                                });
                                        });
                                    </script>
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