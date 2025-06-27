const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('./database.db');

function getRandomMark() {
  return Math.floor(Math.random() * 101); // 0 to 100
}

db.serialize(() => {
  for (let i = 1; i <= 40; i++) {
    const roll = i;
    const PHY = getRandomMark();
    const CHEM = getRandomMark();
    const MATH = getRandomMark();
    const BIOLOGY = getRandomMark();

    db.run(
      `INSERT INTO marks (roll, PHY, CHEM, MATH, BIOLOGY) VALUES (?, ?, ?, ?, ?)`,
      [roll, PHY, CHEM, MATH, BIOLOGY],
      function (err) {
        if (err) {
          console.error(`Error inserting roll ${roll}:`, err.message);
        } else {
          console.log(`Inserted roll ${roll}`);
        }
      }
    );
  }
});

db.close(() => {
  console.log('Database closed after seeding');
});
