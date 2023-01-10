<!doctype html>
<html lang="en">

<head>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-wEmeIV1mKuiNpC+IOBjI7aAzPcEZeedi5yW5f2yOq55WWLwNGmvvx4Um1vskeMj0" crossorigin="anonymous">
    <link rel="stylesheet" href="styles.css">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-p34f1UUtsS3wqzfto5wAAmdvj+osOnFyQFpp4Ua3gs/ZVWx6oOypYoCJhGGScy+8" crossorigin="anonymous"></script>
    <link rel="shortcut icon" href="image/logos/logo.png" type="image/png">
    <title>Depart. of Computer science</title>
</head>

<body>

    <script>
        setTimeout(function() {
            window.open('home.php', '_self');
        }, 2000);

        $(function () {
    $('img').on("hasFadedOut", fadeInImg);
    $('img').on("hasFadedIn", fadeOutImg);
    fadeOutImg();
})

fadeInImg = function () {
    $('img').fadeIn(500, function () { $('img').trigger("hasFadedIn"); });
};

fadeOutImg = function () {
    $('img').fadeOut(2000, function () { $('img').trigger("hasFadedOut"); });
};
    </script>



    <div id="bgfreelogo" class="center"><img src="image/logos/bgfreelogo.webp" class="d-block">
                <!-- <span></span> -->
    </div>

<style>
#bgfreelogo{
    padding-top: 200px;
max-width: 40%;
max-height: 50%;
  min-height:40%;
 min-width: 30%; 
}
</style>
</body>

</html>