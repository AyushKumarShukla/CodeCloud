const express = require('express');
const path = require('path');
const sqlite3 = require('sqlite3').verbose();

const app = express();
const PORT = 3000;

app.use(express.json());
app.use(express.urlencoded({extended: true}));
app.use(express.static('public'));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

// Create/connect to SQLite database
const db = new sqlite3.Database('./database.db', (err) => {
  if (err) {
    console.error('DB connection error:', err);
  } else {
    console.log('Connected to SQLite database');
    
    // Create marks table if it doesn't exist (FIXED: removed extra comma and typo)
    db.run(`CREATE TABLE IF NOT EXISTS marks(
      roll INTEGER PRIMARY KEY,
      PHY INTEGER NOT NULL,
      CHEM INTEGER NOT NULL,
      MATH INTEGER NOT NULL,
      BIOLOGY INTEGER NOT NULL
    )`, (err) => {
      if (err) {
        console.error('Table creation error:', err);
      } else {
        console.log('Marks table ready');
      }
    });
  }
});

// POST route to insert item into SQLite (FIXED: table name and SQL syntax)
app.post('/items', (req, res) => {
  const { roll, phy, chem, math, bio } = req.body;
  
  // Validation
  if (!roll || !phy || !chem || !math || !bio) {
    return res.status(400).json({ error: 'All fields are required' });
  }
  
  const sql = 'INSERT INTO marks (roll, PHY, CHEM, MATH, BIOLOGY) VALUES (?, ?, ?, ?, ?)';

  db.run(sql, [roll, phy, chem, math, bio], function(err) {
    if (err) {
      console.error('Insert error:', err);
      return res.status(500).json({ error: 'Database insert failed: ' + err.message });
    }
    console.log('Inserted marks for roll:', roll); // FIXED: correct variable name
    res.status(201).json({ msg: 'Marks saved to SQLite', id: this.lastID });
  });
});

// GET route to view all marks (optional - for testing)
app.get('/marks', (req, res) => {
  const sql = 'SELECT * FROM marks';
  
  db.all(sql, [], (err, rows) => {
    if (err) {
      console.error('Select error:', err);
      return res.status(500).json({ error: 'Database select failed' });
    }
    res.json(rows);
  });
});

// Graceful shutdown
process.on('SIGINT', () => {
  db.close((err) => {
    if (err) {
      console.error('Error closing database:', err);
    } else {
      console.log('Database connection closed');
    }
    process.exit(0);
  });
});

app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});