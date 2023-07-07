<!-- // TODO: ADMIN ADD CODE
-->
<?php
include "config.php";
if(isset($_POST['sign-up']))
{
    $name=$_POST['name'];
    $pass=$_POST['password'];
    $role=$_POST['role'];
    $password=password_hash($pass,PASSWORD_DEFAULT);
    $sql = "INSERT INTO `user`(`username`,`password`,`role_roleid`)values('$name','$password','$role')";
    $result = $conn->query($sql);
    if($result == TRUE){
        session_stop(); 
        header("Location: http://localhost/php/department/project/signin.php");
    }else{
        echo "Error:". $sql . "<br>". $conn->error;
    } 
    $conn->close();
}
?>