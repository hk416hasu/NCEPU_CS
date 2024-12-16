const mysql = require('mysql2');

const connection = mysql.createConnection({
  host: '82.156.207.47',
  user: 'hk416hasu',
  password: '12345678hhh',
  database: 'learn'
});

connection.connect();

connection.query('select * from customers',(error, results, fields) => {
  if (error) throw error;
  console.log(results);
});

connection.end();
