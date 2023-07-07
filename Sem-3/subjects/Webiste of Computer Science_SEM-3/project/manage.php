<?php
require "config.php";
                    //? SESSION START
session_start();
                    //? GLOABAL VARIABLE
$error = "";
//TODO: USER SIGNIN
if (isset($_POST['sign-in'])) {
                                         //? SELECT QUERY
    $sql = "SELECT * FROM user";
    $result = $conn->query($sql);
    $name = $_POST['name'];
    $password = $_POST['password'];
    $results = false;
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $v_name = $row['username'];
            $v_password = $row['password'];
                                                                                            //! VERIFY
            if (($v_name == $name) && (password_verify($password,$v_password)==true)) {
                $results = true;
                $t_id=$row['username'];
                $v_id=sha1($t_id);
                $role = $row['role_roleid'];
            }
        }
        if ($results == false) {
            $error = "<div class=\"alert alert-danger alert-dismissible fade show\" role=\"alert\">
        <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
        ERROR: You don't have the account  <br> PLEASE SIGN IN</div>";
        } else {
                                        // ? LOAD TO OTHER PAGES USING ELSE IF
                if($role==1)
                {
                    $error = "
                    <script>
                        setTimeout(function() {
                            window.open('view_fac.php?id=$v_id', '_self');
                        }, 2000);
                    </script>
                        <div class=\"alert alert-info alert-dismissible fade show\" role=\"alert\">
                        <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
                        THANK YOU FOR SIGN IN
                        </div>";
                }elseif($role==2){
                    $error = "
                    <script>
                    setTimeout(function() {
                        window.open('view_stu.php?id=$v_id', '_self');
                    }, 2000);
                    </script>
                    <div class=\"alert alert-info alert-dismissible fade show\" role=\"alert\">
                    <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
                    THANK YOU FOR SIGN IN
                    </div>";   
                }
                else{
                    $error="<script>
                    setTimeout(function() {
                        window.open('admin/view.php', '_self');
                    }, 2000);
                </script>
                    <div class=\"alert alert-info alert-dismissible fade show\" role=\"alert\">
                    <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
                    THANK YOU FOR SIGN IN
                    </div>";
                }
        }
        $conn->close();
    } else {
        $error = "
                <div class=\"alert alert-danger\" role=\"alert\">
                    ERRROR: Something went wrong
                </div>";
    }}
// TODO: USER SIGNUP
if (isset($_POST['sign-up'])) {
    $_SESSION['sname'] = $_POST['name'];
    $_SESSION['email'] = $_POST['to_name'];
    $_SESSION['code'] = $_POST['message'];
    $_SESSION['deprole'] = $_POST['role'];
    $_SESSION['depcourse'] = $_POST['course'];
    $_SESSION['password'] = $_POST['password'];
    $_SESSION['contact'] = $_POST['contacts'];
    $cpassword = $_POST['cpassword'];
    if (($_SESSION['password'] == $cpassword)) {
        $ok = true;
                                                //! FETCH DATA FROM TABLE
        $sql = "SELECT * FROM user";
        $results = $conn->query($sql);
        if ($results->num_rows > 0) {
            while ($row = $results->fetch_assoc()) {
                $v_name = $row['username'];
                $v_mail = $row['mail'];
                                                                        // ? CHECK NAME AND EMAIL ID IS EXIST OR NOT
                if (($v_name == $_SESSION['sname']) || ($v_mail == $_SESSION['email'])) {
                    $ok = false;
                }
            } $conn->close();
        }
        if ($ok == false) {
            $error = "<div class=\"alert alert-danger alert-dismissible fade show\" role=\"alert\">
                        <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
                        ERROR: We have same account try to change your user name or use other e-mail id <br>PLEASE TRY AGAIN
                        </div>";
        } else {
            $error = "<script>
                    setTimeout(function() {
                    window.open('otp.php', '_self');
                    }, 100);
                    </script>";
                }
    } else {
        $error = " <div class=\"alert alert-danger alert-dismissible fade show\" role=\"alert\">
                <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
                ERROR: Password and confirm password are not same <br>TRY AGAIN
                </div>";
    }}
            // TODO: OTP CHECK
   if(isset($_POST['otp-verif'])) {
        $otp = $_POST['otp'];
        $name =$_SESSION['sname'];
        $email=$_SESSION['email'];
        $role=$_SESSION['deprole'];
        $course=$_SESSION['depcourse'];
                                                                            //! HASH THE PASSWORD
        $password=password_hash($_SESSION['password'],PASSWORD_DEFAULT);
        $contact=$_SESSION['contact'] ;
        if ($_SESSION['code'] == $otp) {
            $sql = "call insert_user ('$name','$email','$password','$contact','$role','$course')";
            $result = $conn->query($sql);
            $conn->close();
            $error = "<div class=\"alert alert-info alert-dismissible fade show\" role=\"alert\">
                                <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
                                Thank's for registraction
                                </div>
                                <script>
                                setTimeout(function() {
                                window.open('signin.php', '_self');
                                }, 1000);
                                </script>";
        } else {
            $error = " <div class=\"alert alert-danger alert-dismissible fade show\" role=\"alert\">
                                <button type=\"button\" class=\"btn-close \" data-bs-dismiss=\"alert\" aria-label=\"Close\"></button>
                                Verification code doesn't match
                                </div>";
        }}
    
// TODO : SEARCH 
if (isset($_GET['search'])) {
    $username = $_GET['search'];
                        //? SEARCH USING SWITCH CASE
switch ($username) {
  case "download":
    header("Location:download.php");
    break;
  case "event":
    header("Location:event.php");
    break;
  case "faculty":
    header("Location:faculty.php");
    break;
  case "faculty":
    header("Location:faculty.php");
    break;
    default:
    header("Location:error.php");
    
  break;
}
}
?>



