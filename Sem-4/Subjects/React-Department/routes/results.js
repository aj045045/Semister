var express = require('express');
var router = express.Router();
const mysqlData = require('mysql');

mysql = mysqlData.createConnection({
  host: 'localhost',
  user: 'root',
  password: '',
  database: 'dcsdb'
})

/* GET results listing. */
router.get('/', function (req, res, next) {
  mysql.connect();
  var query = "SELECT * FROM documents WHERE document_category_id = 1";
  mysql.query(query, (err, results) => {
    if (err) throw err;
    res.json(results);
  });
  mysql.end();
});

module.exports = router;
