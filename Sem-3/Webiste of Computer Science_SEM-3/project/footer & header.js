// TODO:Header
let appHeader = `
    <nav class="navbar navbar-expand-sm navbar-dark  " id="back-color">
        <div class="container flex-start">
            <a class="navbar-brand" href="home.php">
                <img src="image/logos/logo1.webp" alt="Avatar Logo" style="width:65px;border-radius: 50%;"> 
            </a>
            <button class="navbar-toggler d-lg-none" type="button" style="color: aliceblue;" data-bs-toggle="collapse"data-bs-target="#collapsibleNavId" aria-controls="collapsibleNavId" aria-expanded="false"aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="collapsibleNavId">
                <ul class="navbar-nav me-auto mt-2 mt-lg-0">
                    <!--Add index.php-->
                    <li class="nav-item">
                        <a class="nav-link  text-light" href="home.php"><b>HOME</b></a>
                    </li>
                    <!--Add index.php-->
                    <li class="nav-item">
                        <a class="nav-link text-light" href="academics.php"><b>ACADEMICS</b></a>
                    </li>
                    <!--Add index.php-->
                    <li class="nav-item">
                        <a class="nav-link text-light" href="faculty.php"><b>FACULTY</b></a>
                    </li>
                    <!--Add index.php-->
                    <li class="nav-item">
                        <a class="nav-link text-light" href="event.php"><b>EVENTS</b></a>
                    </li>
                    <!--Add index.php-->
                    <li class="nav-item">
                        <a class="nav-link text-light" href="download.php"><b>SYLLABUS</b></a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link text-light" href="about.php"><b>ABOUT</b></a>
                    </li>
                </ul>
                <div class="top-header hidden-xs" style="padding:0px">
                  <a  class="nav-link text-light p-2 ms-lg-5" href="signin.php" target="_self">
                  <b>SIGN IN</b></a>
                    <form  action="manage.php" style="padding-top:0px">
                        <input type="text"  name="search">
                        <input type="submit" value="Search" autocomplete="off">
                    </form>
                </div>
    </nav>
`;
document.getElementById("header").innerHTML = appHeader;
//TODO:  Footer
let appFooter = ` 
<div class="footer">
<div class="container">
    <div class="row">
        <div class="col-lg-8 col-md-6 footer-links">
            <h6>Quick Links</h6>
            <div class="row small">
                <div class="col-lg-6 col-md-6 footer-link text-start">
                    <b>Academics</b>
                    <ul style="font-size: smaller;">
                        <li><a href="phd.php">Ph.D</a></li>
                        <li><a href="mca.php">MCA</a></li>
                        <li><a href="pgdca.php">PGDCA</a></li>
                        <li><a href="aiml.php">M.sc AI & ML</a></li>
                        <li><a href="aimld.php">M.Sc AI & ML & D</a></li>
                        <li><i class="bx bx-chevron-right"></i> <a href="msccs.php">5 Years Integrated M.Sc-CS</a></li>
                        <!-- <li><i class="bx bx-chevron-right"></i> <a href="#">M.Sc AI & ML & D</a></li> -->
                    </ul>
                </div>
                <div class="col-lg-6 col-md-6 footer-links text-start">
                    <b>Download</b>
                    <ul style="font-size: smaller;">
                    <li><a
                    href="https://www1.gujaratuniversity.ac.in/custom/student/syllabus">Syllabus</a>
                    </li>
                    </ul>
                    <b>Faculties</b>
                    <ul style="font-size: smaller;">
                    <li><a
                                href="faculty.php">Faculties</a>
                    </li>
                    </ul>
                </div>
            </div>
        </div>
        <div class="col-lg-4 col-md-6 footer-links">
            <h6>CONTACT US</h6>
            <div class="tdrow">
                <img src="image/logos/imap.webp" height="20px">|
                Gujarat University, Near Ambedkar Gate, University Area, Ahmedabad, Gujarat 380009
            </div>
            <div class="tdrow">📞| 09727797105</div>
            <div class="tdrow">📧| admissions.dcs@gmail.com</div>
            <div class="tdrow">
                <table>
                    <tr>
                        <td><a rel="noreferrer"
                                href="https://www.facebook.com/M-Sc-Artificial-Intelligence-Machine-Learning-at-Rollwala-GU-654124395030598/"
                                target="_blank"><img class="nav-img" src="image/logos/flogo.png"></a>
                        </td>
                        <td><a rel="noreferrer"
                                href="https://www.instagram.com/msc_computerscience_gu/?next=%2F"
                                target="_blank"><img class="nav-img" src="image/logos/insta.png"></a>
                        </td>
                        <td>
                            <a rel="noreferrer"
                                href="https://www.google.com/maps/place/Department+of+Computer+Science,+Maharshi+Pingal+-+School+of+Advanced+Computing+and+Information+Technology/@23.0362486,72.545091,19.77z/data=!4m5!3m4!1s0x395e859c09adf79f:0xe1d87bc33ed48fe7!8m2!3d23.0360673!4d72.5452956"
                                target="_blank"><img class="nav-img" src="image/logos/imap.webp"></a>
                    </tr>
                    </tr>
                </table>
            </div>
        </div>
    </div>
</div>
</div>
`;
document.getElementById("footer").innerHTML = appFooter;
// PIE CHART  (> home)
var ctxD = document.getElementById("doughnutChart").getContext("2d");
var myLineChart = new Chart(ctxD, {
  type: "doughnut",
  data: {
    labels: [
      "Computer Science",
      "MCA",
      "PGDCSA",
      "M.Sc AI & ML",
      "M.Sc AI & ML & Defence",
      "Integrated M.Sc(computer science)",
    ],
    datasets: [
      {
        data: [40, 49, 44, 24, 15, 15],
        backgroundColor: [
          "#F7464A",
          "#46BFBD",
          "#FDB45C",
          "#949FB1",
          "#4D5360",
          "#fa8072",
        ],
        hoverBackgroundColor: [
          "#FF5A5E",
          "#5AD3D1",
          "#FFC870",
          "#A8B3C5",
          "#616774",
          "#f6a298",
        ],
      },
    ],
  },
});
// TODO:Initialize tooltips
var tooltipTriggerList = [].slice.call(
  document.querySelectorAll('[data-bs-toggle="tooltip"]')
);
var tooltipList = tooltipTriggerList.map(function (tooltipTriggerEl) {
  return new bootstrap.Tooltip(tooltipTriggerEl);
});
//TODO:scroll up button
// Get the button
let mybutton = document.getElementById("myBtn");
// When the user scrolls down 20px from the top of the document, show the button
window.onscroll = function () { scrollFunction() };
function scrollFunction() {
  if (document.body.scrollTop > 20 || document.documentElement.scrollTop > 20) {
    mybutton.style.display = "block";
  } else {
    mybutton.style.display = "none";
  }
}
// When the user clicks on the button, scroll to the top of the document
function topFunction() {
  document.body.scrollTop = 0;
  document.documentElement.scrollTop = 0;
}
