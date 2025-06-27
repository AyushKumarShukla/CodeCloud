const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('./database.db');

db.run('DELETE FROM marks', function(err) {
  if (err) {
    return console.error('Error clearing table:', err.message);
  }
  console.log('All records deleted from "marks" table.');
});

db.close();
