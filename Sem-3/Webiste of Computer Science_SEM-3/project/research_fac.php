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
</head>

<body style="background-color: #eee">
    <section class=" mt-5">
        <div class="container h-100">
            <div class="row d-flex justify-content-center align-items-center ">
                <div class="">
                    <div class="card text-black" style="border-radius: 25px;">
                        <div class="card-body">
                            <?php require_once "manage.php"; echo $error;?>
                            <div class="row justify-content-center">
                                <div>
                                    <p class="text-center h2 fw-bold mb-2 mx-md-3 ">Research Detail</p>
                                    <div class="table-responsive">
                                        <table class="table table-hover	table-borderless table-primary align-middle">
                                            <thead>
                                                <tr>
                                                    <th>Title</th>
                                                    <th>Journal</th>
                                                    <th>Period</th>
                                                    <th>Publisher</th>
                                                    <th></th>
                                                </tr>
                                            </thead>
                                            <tbody>
                                                <?php
include "config.php";
if (isset($_GET['id'])) {
    $v_id = $_GET['id'];
    $sql = "SELECT * FROM `research`";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $v_name=sha1($row['faculty_facultyid']);
            if($v_id==$v_name) {
                ?>
                                                <tr class="table">
                                                    <td scope="row"><?php echo $row['title'];?></td>
                                                    <td><?php echo $row['journal'];?></td>
                                                    <td><?php echo $row['researchyear'];?></td>
                                                    <td><?php echo $row['publisher'];?></td>
                                                    <td><a class="btn btn-danger" href="research_del.php?id=<?php echo $row['researchid'];?>">Delete</a>
                                                    </td>
                                                </tr>
                                                <?php
                }
            }
        }
    }                                        
?>
                                            </tbody>
                                        </table>
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