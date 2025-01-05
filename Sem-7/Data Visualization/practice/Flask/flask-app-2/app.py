from flask import Flask, render_template
import matplotlib.pyplot as plt
import numpy as np
import base64
import io

app = Flask(__name__)

@app.route('/')
def index():
    img = io.BytesIO()
    #  Bar chart
    roll_number = [1,2,3,4,5]
    sub1_marks = [10,20,30,40,50]
    sub2_marks = [20,30,40,50,60]
    sub3_marks = [30,40,50,60,70]

    x = np.arange(len(roll_number))

    width = 0.25

    fx, ax = plt.subplots()

    # Bar for each subject

    bars1 = ax.bar(x-width,sub1_marks,width,label="Subject 1")
    bars2 = ax.bar(x,sub2_marks,width,label="Subject 2")
    bars3 = ax.bar(x+width,sub3_marks,width,label="Subject 3")

    ax.set_xlabel("Roll Number")
    ax.set_ylabel("Marks")
    ax.set_title("Marks of Student in Three Subjects")
    ax.set_xticks(x)
    ax.set_xticklabels(roll_number)
    ax.legend()
    plt.savefig(img,format="png")
    img.seek(0)
    plot_url = base64.b64encode(img.getvalue()).decode()
    return render_template('index.html',plt_url=plot_url)

if __name__ == "__main__":
    app.run(debug=True)