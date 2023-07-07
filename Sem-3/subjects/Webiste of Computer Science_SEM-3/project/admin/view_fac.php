<!-- // TODO: VIEW FACULTY DETAILS
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
<body class="px-5">
    <p class="h4 py-4">Faculty Record</p>
    <div class="table-responsive">
        <table class="table
        table-hover
        table-primary
        align-middle">
            <thead class="table-primary">
                <tr>
                    <th>Faculty Name</th>
                    <th>E-mail</th>
                    <th>Specialization</th>
                    <th>Designation</th>
                    <th>Experience</th>
                    <th>Contact </th>
                    <th>Edit</th>
                    <th>Delete</th>
                </tr>
            </thead>
            <tbody>
                <?php
include "config.php";
$sql = "select name,email,specialization,designation,experience,contact_no from `faculty`;";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        ?>
                <tr class="table">
                    <td scope="row"><?php echo $row['name']; ?></td>
                    <td><?php echo $row['email']; ?></td>
                    <td><?php echo $row['specialization']; ?></td>
                    <td><?php echo $row['designation']; ?></td>
                    <td><?php echo $row['experience']; ?> </td>
                    <td><?php echo $row['contact_no']; ?></td>
                    <td><a class="btn btn-primary" href="update_fac.php?id=<?php echo sha1($row['name']);?>">Edit</a></td>
                    <td><a class="btn btn-danger" href="delete_fac.php?id=<?php echo $row['name'];?>">Delete</a></td>
                </tr>
                <?php
}
}
?>
            </tbody>
        </table>
    </div>
</body>
</html>