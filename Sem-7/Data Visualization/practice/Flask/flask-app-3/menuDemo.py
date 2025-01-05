from flask import Flask, render_template
import matplotlib
import matplotlib.pyplot as plt
import io
import base64

# Use the Agg backend for non-interactive plotting
matplotlib.use('Agg')

app = Flask(__name__)

# Function to generate a base64 encoded image from a matplotlib plot
def create_plot():
    img = io.BytesIO()
    plt.savefig(img, format='png')
    img.seek(0)
    plot_url = base64.b64encode(img.getvalue()).decode('utf8')
    plt.clf()  # Clear the plot for future use
    return plot_url

@app.route('/')
def home():
    return render_template('home.html')

@app.route('/graph1')
def graph1():
    plt.bar([1, 2, 3], [10, 20, 30])
    plot_url = create_plot()
    return render_template('graph.html', plot_url=plot_url, title="Graph 1")

@app.route('/graph2')
def graph2():
    plt.plot([1, 2, 3], [30, 20, 10])
    plot_url = create_plot()
    return render_template('graph.html', plot_url=plot_url, title="Graph 2")

@app.route('/graph3')
def graph3():
    plt.scatter([1, 2, 3], [30, 20, 10])
    plot_url = create_plot()
    return render_template('graph.html', plot_url=plot_url, title="Graph 3")

@app.route('/graph4')
def graph4():
    plt.pie([10, 20, 30], labels=["A", "B", "C"])
    plot_url = create_plot()
    return render_template('graph.html', plot_url=plot_url, title="Graph 4")

@app.route('/graph5')
def graph5():
    data = [1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4]
    plt.hist(data, bins=4)
    plot_url = create_plot()
    return render_template('graph.html', plot_url=plot_url, title="Graph 5")

if __name__ == '__main__':
    app.run(debug=True,port=5001)
