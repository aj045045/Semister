from flask import Flask, jsonify, render_template

app = Flask(__name__)

# Route for serving the HTML file
@app.route('/')
def index():
    return render_template('d3demo.html')

# Route for providing data to D3.js
@app.route('/data')
def get_data():
    data = [
        {"name": "A", "value": 30},
        {"name": "B", "value": 80},
        {"name": "C", "value": 45},
        {"name": "D", "value": 60},
    ]
    return jsonify(data)

if __name__ == "__main__":
    app.run(debug=True)
