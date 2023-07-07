var express = require('express');
var router = express.Router();

router.get('?id=', function (req, res, next) {
    console.log(req.originalUrl);
    console.log(req.query.id);
});

module.exports = router;
