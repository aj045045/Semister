from pymongo import MongoClient
import pandas as pd

# Connection with mongodb
client=MongoClient("mongodb://localhost:27017/")

# Select collection / table 
db = client.employee

# User Detail for inserting in database
name = input("Enter the name :")
age = int(input("Enter the age :"))
rollNo = int(input("Enter the roll No :"))
course = input("Enter the course :")
sem = int(input("Enter the sem :"))

obj = {
    "name":name,
    "age":age,
    "rollNo":rollNo,
    "course":course,
    "sem":sem
    }

# Insert one Dictionary in Database
db.user.insert_one(obj)

print("\n\n=============\tDisplay all the data store in user collections\t=============\n\n")

# Access store data from collection using `db.user.find()` and convert it into list
user = list(db.user.find())
df = pd.DataFrame(user)
df.drop('_id', axis=1, inplace=True)
print(df)