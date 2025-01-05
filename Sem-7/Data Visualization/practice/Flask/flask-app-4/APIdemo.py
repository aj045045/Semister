from flask import Flask, jsonify, request, abort
from flask_cors import CORS
app = Flask(__name__)
CORS(app)


users = [
    {"id": 1, "name": "Ekata", "email": "ekata@gmail.com"},
    {"id": 2, "name": "Kishan", "email": "kishan@gmail.com"}
]

# Helper function to find user by ID
def find_user(user_id):
    return next((user for user in users if user["id"] == user_id), None)

# GET /users - Retrieve all users
@app.route('/users', methods=['GET'])
def get_users():
    return jsonify(users), 200

# # GET /users/<id> - Retrieve a single user by ID
# @app.route('/users/<int:id>', methods=['GET'])
# def get_user(id):
#     user = find_user(id)
#     if user:
#         return jsonify(user), 200
#     return jsonify({"error": "User not found"}), 404

# POST /users - Create a new user
@app.route('/users', methods=['POST'])
def create_user():
    if not request.json or not 'name' in request.json:
        abort(400)  # Bad request
    new_user = {
        "id": users[-1]["id"] + 1 if users else 1,  # Generate new ID
        "name": request.json['name'],
        "email": request.json.get('email', '')
    }
    users.append(new_user)
    return jsonify(new_user), 201

# # PUT /users/<id> - Update an existing user by ID
# @app.route('/users/<int:id>', methods=['PUT'])
# def update_user(id):
#     user = find_user(id)
#     if not user:
#         return jsonify({"error": "User not found"}), 404
#     if not request.json:
#         abort(400)  # Bad request
#     user["name"] = request.json.get('name', user["name"])
#     user["email"] = request.json.get('email', user["email"])
#     return jsonify(user), 200

# DELETE /users/<id> - Delete a user by ID
@app.route('/users/<int:id>', methods=['DELETE'])
def delete_user(id):
    user = find_user(id)
    if not user:
        return jsonify({"error": "User not found"}), 404
    users.remove(user)
    return jsonify({"result": "User deleted"}), 200

# Run the Flask app
if __name__ == '__main__':
    app.run(debug=True)
