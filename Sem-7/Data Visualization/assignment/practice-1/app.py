from flask import Flask, render_template
import io
import base64
import matplotlib.backends
import matplotlib.pyplot as plt
import matplotlib

matplotlib.use('agg')

app = Flask(__name__)

val = ['bar-chart','line-chart','pie-chart']

@app.route("/")
def home():
    return render_template('index.html', valList=val)

@app.route("/graph/<int:valImage>")
def graph(valImage):
    title = f"this is my image {valImage}"
    src =  ""
    if valImage == 1:
        img = io.BytesIO()
        plt.figure(figsize=(12,8))
        plt.bar([10,12,28,8,55],[45,23,12,54,3],color=['orange','green','blue','red','purple'],label=['orange','green','blue','red','purple'])
        plt.xlabel("The X label")
        plt.ylabel("The Y label")
        plt.tight_layout()
        plt.legend()
        plt.savefig(img,format='png')
        plt.close()
        img.seek(0)
        src = base64.b64encode(img.getvalue()).decode('utf-8')
    
    return render_template('graph.html',title=title,src=src)

if __name__ == "__main__":
    app.run(debug=True)