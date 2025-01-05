from flask import Flask, render_template, session, request, flash, redirect, url_for
from source import JSONHandler,ImagePlot
import pandas as pd
import matplotlib
matplotlib.use('Agg')  # Use a non-GUI backend before importing pyplot
import matplotlib.pyplot as plt
import seaborn as sns

app = Flask(__name__)
app.secret_key = "development"

def plot_athlete_bio_1(abDf):
    gender_bar = [abDf[abDf['sex'] == 'Male']['sex'].count(), abDf[abDf['sex'] == 'Female']['sex'].count()]
    labels = ['Male', 'Female']
    plt.title("Total Participation by Gender")
    plt.bar(labels, gender_bar,color=['orange','green'])
    plt.xlabel('Gender')
    plt.ylabel('Count')

def plot_athlete_bio_2(abDf):
    value_counts = abDf['country_noc'].value_counts()
    top_10 = value_counts.head(10)
    top_10.plot(kind='bar', color='skyblue')
    plt.title('Top 10 Country NOC')
    plt.xlabel(' Values')
    plt.ylabel('Count')
    plt.xticks(rotation=45)
    plt.grid(axis='y')
    plt.tight_layout()

def plot_athlete_bio_3(abDf):
    value_counts = abDf['height'].value_counts()
    top_10 = value_counts.head(10)
    top_10.plot(kind='bar', color='skyblue')
    plt.title('Top 10  Height')
    plt.xlabel(' Values')
    plt.ylabel('Count')
    plt.xticks(rotation=45)
    plt.grid(axis='y')
    plt.tight_layout()

def plot_athlete_bio_4(abDf):
    value_counts = abDf['weight'].value_counts()
    top_10 = value_counts.head(10)
    top_10.plot(kind='bar', color='skyblue')
    plt.title('Top 10 Weight')
    plt.xlabel('Values')
    plt.ylabel('Count')
    plt.xticks(rotation=45)
    plt.grid(axis='y')
    plt.tight_layout()

def plot_games_1(gmDf):
    # Assuming gmDf is your DataFrame and it's already defined
    unique_sorted = sorted(gmDf['edition_id'].unique(), reverse=True)
    data = pd.DataFrame()
    for i in unique_sorted[:5]:
        value_counts = gmDf[gmDf['edition_id'] == i]['edition_id'].value_counts()
        data[f'{gmDf[gmDf['edition_id'] == i ]['year'].unique()[0]} ({value_counts.values[0]})'] = value_counts.values 
    data = data.T
    data = data.fillna(0)
    data.plot(kind='bar', color='green')
    plt.title('No of country participate in the games')
    plt.xlabel('Values (Edition ID)')
    plt.ylabel('Count')
    plt.xticks(rotation=0)
    plt.tight_layout()

def plot_games_2(gmDf,medal_type):
    """Total Medal win by the top 5 country"""

    medal = gmDf[gmDf.year == 2022]
    total = medal.sort_values(by='total',ascending=False)
    gold = medal.sort_values(by='gold',ascending=False)
    silver = medal.sort_values(by='silver',ascending=False)
    bronze = medal.sort_values(by='bronze',ascending=False)

    for i in [(total,"Total"),(gold,"Gold"),(silver,"Silver"),(bronze,"Bronze")]:
        if i[1] == medal_type :
            x = i[0].head(5)['country'].tolist()
            y = i[0].head(5)['total'].tolist()
            plt.title(f"{i[1]} medal in 2022")
            plt.bar(x,y)
            plt.xlabel("Country")
            plt.ylabel("No. of Medal")

def plot_result_1(rDf):
    sport = rDf['sport'].value_counts()
    plt.barh(sport.index, sport.values, color='skyblue')
    plt.xlabel('Count')
    plt.ylabel('Sport')
    plt.title('Sport Participation Counts')
    plt.grid(axis='x')
    plt.tight_layout()

def plot_athlete_event_2():
    file_path = './olympic/janvi/Olympic_Athlete_Event_Results.csv' 
    df = pd.read_csv(file_path)
    gold_medals = df[df['medal'] == 'Gold']
    gold_medals_by_country = gold_medals['country_noc'].value_counts().reset_index()
    gold_medals_by_country.columns = ['Country', 'Gold Medals']
    colors = ['Blue','Pink','Yellow','red','purple','lavender','Indigo']
    sns.barplot(x='Gold Medals', y='Country', data=gold_medals_by_country.head(10), palette=colors)
    plt.title('Top 10 Countries by Number of Gold Medals', fontsize=14)
    plt.xlabel('Gold Medals', fontsize=12)
    plt.ylabel('Country', fontsize=12)
    plt.tight_layout()
    plt.legend()

def plot_athlete_event_3():
    file_path = './olympic/janvi/Olympic_Athlete_Event_Results.csv'  
    df = pd.read_csv(file_path)
    medal_winners = df[df['medal'].notna()]
    total_medals_by_country = medal_winners['country_noc'].value_counts().reset_index()
    total_medals_by_country.columns = ['Country', 'Total Medals']
    sns.barplot(x='Total Medals', y='Country', data=total_medals_by_country.head(10), color='c')
    plt.title('Top 10 Countries by Total Medals', fontsize=14)
    plt.xlabel('Total Medals', fontsize=12)
    plt.ylabel('Country', fontsize=12)
    plt.tight_layout()


def plot_athlete_event_4():
    file_path_new_data = './olympic/janvi/Olympic_Athlete_Event_Results.csv'
    olympic_athlete_event_results = pd.read_csv(file_path_new_data)
    sport_counts = olympic_athlete_event_results['sport'].value_counts()
    sport_counts = sport_counts.head(10)
    plt.bar(sport_counts.index, sport_counts.values, color='skyblue')
    plt.title('Count of Events by Sport')
    plt.xlabel('Sport')
    plt.ylabel('Number of Events')
    plt.xticks(rotation=90)
    plt.tight_layout()

def plot_athlete_event_5():
    file_path_new_data = './olympic/janvi/Olympic_Athlete_Event_Results.csv'
    olympic_athlete_event_results = pd.read_csv(file_path_new_data)
    team_sport_counts = olympic_athlete_event_results['isTeamSport'].value_counts()
    plt.pie(team_sport_counts, labels=['Individual Sport', 'Team Sport'], autopct='%1.1f%%', startangle=90, colors=['lightcoral', 'skyblue'])
    plt.title('Proportion of Individual vs. Team Sports')

def plot_athlete_event_6():
    data = pd.read_csv('./olympic/janvi/Olympic_Athlete_Event_Results.csv')
    men_count = data['event'].str.count('Men').sum()
    women_count = data['event'].str.count('Women').sum()
    mixed_count = data['event'].str.count('Mixed').sum()
    open_count = data['event'].str.count('Open').sum()
    event_counts = [men_count, women_count, mixed_count, open_count]
    event_labels = ['Men', 'Women', 'Mixed', 'Open']
    plt.pie(event_counts, labels=event_labels, autopct='%1.1f%%')
    plt.title('Athletes by Event Type')

def plot_games_j_1():
    file_path_new = './olympic/janvi/Olympics_Games.csv'
    olympic_games_data = pd.read_csv(file_path_new)
    country_counts = olympic_games_data['country_noc'].value_counts()
    plt.bar(country_counts.index, country_counts.values, color='lightgreen')
    plt.title('Olympic Games by Host Country')
    plt.xlabel('Country NOC')
    plt.ylabel('Number of Games')
    plt.xticks(rotation=90)
    plt.tight_layout()

def plot_games_j_3():
    file_path_new = './olympic/janvi/Olympics_Games.csv'
    olympic_games_data = pd.read_csv(file_path_new)
    year_counts = olympic_games_data['year'].value_counts().sort_index()
    plt.plot(year_counts.index, year_counts.values, marker='o', color='b')
    plt.title('Number of Olympic Games Over Time')
    plt.xlabel('Year')
    plt.ylabel('Number of Games')
    plt.grid(True)

def navBar():
    return ['Athlete Bio','Athlete Event Result','Games Medal','Games','Results']
    
@app.context_processor
def utility_processor():
    return dict(navBar=navBar)

"""
Route Handler for index

This handle the route to render welcome html page
"""
@app.route("/")
def index():
    ab = ["No. Of Participation by Gender in Olympic","Top 10 country participation in olympic","Top 10 height of athlete in olympic","Top 10 weight of athlete in olympic"]
    aer = ["Top 10 Countries by Number of Gold medal","Top 10 Countries by Total Medals ","Count of Events by Sport","Proportion of Individual vs Team Sports","Athletes by Event Type"]
    gm = ["No. Of Country Participate in games","Top 5 total medal win by country in 2022","Top 5 Gold medal win by country in 2022","Top 5 Silver medal win by country in 2022","Top 5 Bronze medal win by country in 2022"]
    g = ["Olympic Games by Host Country","Number of Olympic Games Over Time"]
    r = ["No. Of of Player Participation in sports"]
    return render_template('welcome.html',ab=ab,aer=aer,gm=gm,g=g,r=r)

@app.route('/sign-up', methods=['GET', 'POST'])
def sign_up():
    if request.method == 'POST':
        json = JSONHandler()
        json._userName = request.form.get('userName')
        json._emailId = request.form.get('emailId')
        json._password = request.form.get('password')
        if json._emailId and json._password and json._userName:
            data = json.read_file()
            if any(entry['emailId'] == json._emailId for entry in data):
                flash({'title': "Account exists", 'message': "Looks like your account have been already exists in the system, Try to sign in"}, 'error')
            else:
                json.write_file()
                flash({'title': "Sign Up", 'message': 'Your account has successfully created, Try to sign In.'}, 'success')
            return redirect(url_for('sign_in'))
    
    return render_template('sign_up.html')

@app.route('/sign-in', methods=['GET', 'POST'])
def sign_in():
    if request.method == 'POST':
        emailId = request.form.get('emailId')
        password = request.form.get('password')
        users = JSONHandler().read_file()  # Get the list of users
        
        for user in users:
            if user['emailId'] == emailId and user['password'] == password: 
                session['emailId'] = emailId 
                flash({'title': "Sign In", 'message': "You have successfully Sign In in the system, Thanks for Sign In."}, 'success')
                
                return redirect(url_for('index'))
        
        flash({'title': "Create new account", 'message': "Looks like you don't have an account, Try to create a new one."}, 'error')
    
    return render_template('sign_in.html')

@app.route('/logout')
def logout():
    session.pop('emailId', None)
    flash({'title': "Log out", 'message': "You have successfully log out from the system, Please visit us again."}, 'success')
    return redirect(url_for('index'))

@app.route('/bar/<int:question_id>')
def bar(question_id):
    label = []
    image = []
    if question_id == 1:
        abDf = pd.read_csv("./olympic/Olympic_Athlete_Bio.csv")
        abDf.head()
        abDf = abDf.drop(columns=['description','special_notes'])
        list_abDf = ['athlete_id','height','weight']
        abDf[list_abDf] = abDf[list_abDf].apply(pd.to_numeric, errors='coerce')
        abDf.fillna(abDf.select_dtypes(include=['number']).mean().round(1), inplace=True)
        abDf.dropna(inplace=True)
        # Append label and image
        image.append(ImagePlot.plot_image(plot_athlete_bio_1,abDf))
        label.append("Total no. of participation by Gender in olympic")
        # Append label and image
        image.append(ImagePlot.plot_image(plot_athlete_bio_2,abDf))
        label.append("Top 10 country participation in olympic")
        # Append label and image
        image.append(ImagePlot.plot_image(plot_athlete_bio_3,abDf))
        label.append("Top 10 height of athlete in olympic")
        # Append label and image
        image.append(ImagePlot.plot_image(plot_athlete_bio_4,abDf))
        label.append("Top 10 weight of athlete in olympic")
    
    elif question_id == 2:
        # Append label and image
        image.append(ImagePlot.plot_image(plot_athlete_event_2))
        label.append("Top 10 Countries by Number of Gold medal ")
        # Append label and image
        image.append(ImagePlot.plot_image(plot_athlete_event_3))
        label.append("Top 10 Countries by Total Medals")
        # Append label and image
        image.append(ImagePlot.plot_image(plot_athlete_event_4))
        label.append("Count of Events by Sport")
        # Append label and image
        image.append(ImagePlot.plot_image(plot_athlete_event_5))
        label.append("Proportion of Individual vs. Team Sports")
        # Append label and image
        image.append(ImagePlot.plot_image(plot_athlete_event_6))
        label.append("Athletes by Event Type")
        
    elif question_id == 3:
        gmDf = pd.read_csv("./olympic/Olympic_Games_Medal_Tally.csv")
        image.append(ImagePlot.plot_image(plot_games_1,gmDf))
        label.append("No. Of Country Participate in games")
        image.append(ImagePlot.plot_image(plot_games_2,gmDf,"Total"))
        label.append("Top 5 total medal win by country in 2022")
        image.append(ImagePlot.plot_image(plot_games_2,gmDf,"Gold"))
        label.append("Top 5 Gold medal win by country in 2022")
        image.append(ImagePlot.plot_image(plot_games_2,gmDf,"Silver"))
        label.append("Top 5 Silver medal win by country in 2022")
        image.append(ImagePlot.plot_image(plot_games_2,gmDf,"Bronze"))
        label.append("Top 5 Bronze medal win by country in 2022")
    
    elif question_id == 4:
        image.append(ImagePlot.plot_image(plot_games_j_1))
        label.append("Olympic Games by Host Country")
        image.append(ImagePlot.plot_image(plot_games_j_3))
        label.append("Number of Olympic Games Over Time")
    
    elif question_id == 5:
        rDf = pd.read_csv("./olympic/Olympic_Results.csv")
        # Drop Row if it contains `na` in columns `result_format`, `result_detail` and `result_description`
        for i in ['result_format','result_detail','result_description']:
            rDf = rDf[rDf[i] != 'na']
        rDf = rDf.drop(columns=['sport_url','edition','edition_id'])
        # Remove duplicates and keep first
        rDf = rDf.drop_duplicates(subset='event_title',keep='first')
        image.append(ImagePlot.plot_image(plot_result_1,rDf))
        label.append("No. Of of Player Participation in sports")
    return render_template('bar.html',label=label,image=image)

@app.route('/graph', methods=['POST'])
def graph():
    title = request.form.get('title')
    src = request.form.get('src')
    return render_template('graph.html', title=title, src=src)

@app.errorhandler(Exception)
def errorHandler(error):
    flash({'title': "Error Occurred", 'message': str(error)}, 'error')
    return redirect(url_for('index'))

if __name__ == "__main__":
    app.run(debug=True)
