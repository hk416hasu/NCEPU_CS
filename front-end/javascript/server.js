// Load the built-in HTTP module
const http = require('http');

// Create an HTTP server
const server = http.createServer((req, res) => {
    res.statusCode = 200; // HTTP Status: OK
    res.setHeader('Content-Type', 'text/plain');
    res.end('Hello, World from Node.js!\n');
});

// Start the server on port 3000
server.listen(3000, '127.0.0.1', () => {
    console.log('Server running at http://127.0.0.1:3000/');
});

