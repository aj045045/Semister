<!doctype html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-wEmeIV1mKuiNpC+IOBjI7aAzPcEZeedi5yW5f2yOq55WWLwNGmvvx4Um1vskeMj0" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <link rel="stylesheet" href="styles.css">

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-p34f1UUtsS3wqzfto5wAAmdvj+osOnFyQFpp4Ua3gs/ZVWx6oOypYoCJhGGScy+8"
        crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.9.4/Chart.js"></script>
    <link rel="shortcut icon" href="image/logos/logo.webp" type="image/webp">
    <title>Depart. of Computer science</title>

    <style>
        .scroll::-webkit-scrollbar {
            height: 5px;
        }
        .scroll:hover::-webkit-scrollbar-thumb {
            border-radius: 50px;
            background-color:grey;
        }
    </style>
</head>

<body>
    <button onclick="topFunction()" id="myBtn" title="Go to top">TOP</button>

    <script defer src="footer & header.js"></script>
    <!-- Header -->
    <header id="header"></header>

    <ul class="breadcrumb" style="padding-top:130px;padding-left: 7%;">
        <li>Home</li>
    </ul>
    <div id="carouselId" class="carousel slide" data-bs-ride="carousel">
        <ol class="carousel-indicators">
            <li data-bs-target="#carouselId" data-bs-slide-to="0" class="active" aria-current="true"
                aria-label="First slide"></li>
            <li data-bs-target="#carouselId" data-bs-slide-to="1" aria-label="First slide"></li>
            <li data-bs-target="#carouselId" data-bs-slide-to="2" aria-label="Second slide"></li>
            <li data-bs-target="#carouselId" data-bs-slide-to="3" aria-label="Third slide"></li>
            <li data-bs-target="#carouselId" data-bs-slide-to="4" aria-label="Fourth slide"></li>
        </ol>
        <div class="carousel-inner" role="listbox">
            <div class="carousel-item">
                <img src="image/slideshows/1slide.webp" alt="Firstslide" class="d-block">
            </div>
            <div class="carousel-item active">
                <img src="image/slideshows/3slide.webp" alt="Second slide" class="d-block">
            </div>
            <div class="carousel-item">
                <img src="image/slideshows/2slide.webp" alt="Third slide" class="d-block">
            </div>

            <div class="carousel-item">
                <img src="image/slideshows/4slide.webp" alt="Fourth slide" class="d-block">
            </div>
            <div class="carousel-item">
                <img src="image/slideshows/5slide.webp" alt="Fifth slide" class="d-block">
            </div>


        </div>

        <button class="carousel-control-prev" type="button" data-bs-target="#carouselId" data-bs-slide="prev">
            <span class="carousel-control-prev-icon" aria-hidden="true"></span>
        </button>
        <button class="carousel-control-next" type="button" data-bs-target="#carouselId" data-bs-slide="next">
            <span class="carousel-control-next-icon" aria-hidden="true"></span>
        </button>
    </div>
    <div style="padding-right:7%; padding-left: 7%;">
        <div class="container-fluid mt-3">
            <br>

            <!-- AIM-->
            <div class="container-fluid mt-3">
                <div class="pill"> AIM</div>
                <br>
                <ul class="westside">
                    <li>Quality software professionalism relevant and useful to the Industry, Business and Other
                        organization. </li>
                    <li>To expose the students to the real world issues, encourage them.</li>
                    <li>Course that fits one’s career goals and prepare them to prove themselves in any
                        national/international scenario.</li>
                    <li>Nation's finest in nurturing a future generation of competent, credible and ethical forensic
                        scientists.</li>
                    <li>Adopting innovative teaching methods that promote learning, creativity and critical thinking
                        skills.
                    </li>
                    <li>Reviewing regularly the curriculum, courses and programs offered to meet the changing needs of
                        the
                        forensic science profession.</li>
                </ul>
                <br>
                <div class="pill"> Total Student </div>
                <br>
                <div class="piechart"><canvas id="doughnutChart"></canvas>
                </div>

                <!-- OVERVIEW -->
                <div class="pill "> OVERVIEW</div>
                <br>
                <p class="Moreless">Department of Computer Science, Gujarat University is the most popular,
                    well sought and best resourced Computer Science Department in Gujarat.
                    Ever since its inception, Department of Computer Science has maintained and
                    sustained its legacy as a premium institute in providing high quality education to produce
                    personnel with professional and personal success as well as high ethics and social conduct.
                    The resources at the department are well supported by extensive networked Computer facilities
                    and software aids well along with skilled and experienced faculties.
                    A pioneer institute in initiating and successfully running MCA and PGDCSA since 1982,
                    the Department initiated M.Tech.(Networking and Administration)
                    , M.Tech.(Web Technologies) and PGDNA in 2010<span id="dots">.</span><span id="more">The aim of
                        initiating these programs is to produce professionals
                        ready to meet the current market needs as well as skilled in research capabilities.
                        Understanding that Intelligent Computing is the future of computing, the department
                        initiated yet another post graduate course in Intelligent Computing. The course M.Sc.
                        (Artificial Intelligence & Machine Learning) aims to provide M.Sc. degree in Artificial
                        Intelligence and Machine Learning. This program offers a solid awareness of the key concepts
                        of Artificial Intelligence. The students would be able to develop strong basis of
                        machine learning and data mining. The students would have best career prospects in
                        scientific, business and financial sectors. Further to leverage the versatile system
                        to train Computer professionals department has started 5 Year Integrated M. Sc.
                        (Computer Science) in 2021
                        To promote and facilitate research in Computer Science and other interdisciplinary subjects,
                        Department offers doctoral courses like Ph.D. (Computer science) under well-experienced guides.
                        The Department also takes the responsibility to the fullest of training the educators.
                        It has organized in recent past UGC short courses and international workshops imparting
                        theoretical and practical training to various colleges and universities teachers at state
                        level and national level</span>
                    <button onclick="myFunction()" id="buttonreadmore">Read more</button>
                </p>
                <br>

            </div>
        </div>
        <div class="pill "> collaborators</div><br>
        <div class="scroll">
            <img class="img" src="image/collaborators/1scr.webp">
            <img class="img" style="max-width:200px" src="image/collaborators/2scr.webp">
            <img class="img" src="image/collaborators/3scr.webp">
            <img class="img" src="image/collaborators/4scr.webp">
            <img class="img" src="image/collaborators/5scr.webp">
            <img class="img" src="image/collaborators/6scr.webp">
            <img class="img" src="image/collaborators/7scr.webp">
            <img class="img" src="image/collaborators/8scr.webp">
            <img class="img" src="image/collaborators/9scr.webp">
            <img class="img" src="image/collaborators/10scr.webp">
            <img class="img" src="image/collaborators/11scr.webp">
            <img class="img" src="image/collaborators/12scr.webp">
            <img class="img" src="image/collaborators/13scr.webp">
        </div>
    </div>
    <br>

    <!-- Footer -->
    <footer id="footer"></footer>
</body>

</html>
