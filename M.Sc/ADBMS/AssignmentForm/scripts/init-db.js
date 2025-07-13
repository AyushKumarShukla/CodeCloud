// scripts/init-db.js
const sqlite3 = require('sqlite3').verbose();

const db = new sqlite3.Database('./orders.db');

db.serialize(() => {
    // Create orders table
    db.run(`
        CREATE TABLE IF NOT EXISTS orders (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            order_session_id TEXT NOT NULL,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            total_amount REAL NOT NULL,
            status TEXT DEFAULT 'pending'
        )
    `, (err) => {
        if (err) {
            console.error('Error creating orders table:', err.message);
        } else {
            console.log('Orders table created successfully.');
        }
    });

    // Create order_items table
    db.run(`
        CREATE TABLE IF NOT EXISTS order_items (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            order_session_id TEXT NOT NULL,
            item_name TEXT NOT NULL,
            item_id TEXT NOT NULL,
            item_description TEXT NOT NULL,
            price_per_dish REAL NOT NULL,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (order_session_id) REFERENCES orders (order_session_id)
        )
    `, (err) => {
        if (err) {
            console.error('Error creating order_items table:', err.message);
        } else {
            console.log('Order items table created successfully.');
        }
    });
});

db.close((err) => {
    if (err) {
        console.error('Error closing database:', err.message);
    } else {
        console.log('Database initialization completed.');
    }
});