const express = require('express');
const sqlite3 = require('sqlite3').verbose();
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3000;

// Middleware
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(express.static('public'));

// Initialize SQLite database
const db = new sqlite3.Database('./orders.db', (err) => {
    if (err) {
        console.error('Error opening database:', err.message);
    } else {
        console.log('Connected to SQLite database');
        
        // Create orders table if it doesn't exist
        db.run(`CREATE TABLE IF NOT EXISTS orders (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            card_id INTEGER NOT NULL,
            item_name TEXT NOT NULL,
            item_description TEXT NOT NULL,
            price REAL NOT NULL,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP
        )`, (err) => {
            if (err) {
                console.error('Error creating table:', err.message);
            } else {
                console.log('Orders table ready');
            }
        });
    }
});

// Routes
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

app.post('/api/orders', (req, res) => {
    const { orders } = req.body;
    
    if (!orders || !Array.isArray(orders)) {
        return res.status(400).json({ error: 'Invalid orders data' });
    }

    // Insert orders sequentially
    const insertPromises = orders.map(order => {
        return new Promise((resolve, reject) => {
            const { id: cardId, itemName, itemDescription, price } = order;
            
            db.run(
                'INSERT INTO orders (card_id, item_name, item_description, price) VALUES (?, ?, ?, ?)',
                [cardId, itemName, itemDescription, price],
                function(err) {
                    if (err) {
                        reject(err);
                    } else {
                        resolve({
                            id: this.lastID,
                            cardId,
                            itemName,
                            itemDescription,
                            price
                        });
                    }
                }
            );
        });
    });

    Promise.all(insertPromises)
        .then(results => {
            console.log('Orders inserted successfully:', results);
            res.json({
                success: true,
                message: 'Orders logged successfully',
                orders: results
            });
        })
        .catch(err => {
            console.error('Error inserting orders:', err);
            res.status(500).json({ error: 'Failed to log orders' });
        });
});

// Get all orders (for testing/viewing)
app.get('/api/orders', (req, res) => {
    db.all('SELECT * FROM orders ORDER BY created_at DESC', [], (err, rows) => {
        if (err) {
            console.error('Error fetching orders:', err);
            res.status(500).json({ error: 'Failed to fetch orders' });
        } else {
            res.json(rows);
        }
    });
});

// Start server
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});

// Graceful shutdown
process.on('SIGINT', () => {
    console.log('\nShutting down gracefully...');
    db.close((err) => {
        if (err) {
            console.error('Error closing database:', err.message);
        } else {
            console.log('Database connection closed');
        }
        process.exit(0);
    });
});