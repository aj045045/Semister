from flask import Flask, render_template
import io
import matplotlib.pyplot as plt
import base64

app = Flask(__name__)

plt.switch_backend('Agg')

@app.route('/')
def index():
    img1 = io.BytesIO()
    plt.bar(['A', 'B', 'C', 'D'], [3, 7, 2, 5])
    plt.savefig(img1, format='png')
    plt.close()  
    img1.seek(0)
    plot_url1 = base64.b64encode(img1.getvalue()).decode('utf-8')

    img2 = io.BytesIO()
    plt.plot([1, 2, 3, 4], [10, 20, 25, 30])
    plt.savefig(img2, format='png')
    plt.close()  
    img2.seek(0)
    plot_url2 = base64.b64encode(img2.getvalue()).decode('utf-8')

    return render_template('index.html', plot_url1=plot_url1, plot_url2=plot_url2)

if __name__ == '__main__':
    app.run(debug=True)