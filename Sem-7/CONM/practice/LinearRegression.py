"""Linear Regression"""
import pandas as pd

def linerRegression(x:list,y:list):
    data = {'x':x,'y':y}
    df = pd.DataFrame(data)
    xMean = sum(x)/len(x)
    yMean = sum(y)/len(y)
    n = len(x)
    
    # Find x^2
    df['x^2'] = [value**2 for value in x]
    
    # Find x*y
    df['xy'] = [x[i]*y[i] for i in range(n)]
    
    # Find yi-yMean
    df['(y-yMean)^2'] = [(y[i]-yMean)**2 for i in range(n)]

    # Find a1
    a1 = ((n*sum(df['xy']))-sum(x)*sum(y))/((n*sum(df['x^2']))-sum(x)**2)
    
    # Find a0
    a0 = yMean - a1*xMean

    # Find (yi-a0-a1x1)^2
    df['(y-a0-a1x)^2'] = [(y[i] - a0 - (a1*x[i]))**2 for i in range(n)]
    
    # Add Total to display
    
    sum_y_min_yMean = sum(df['(y-yMean)^2'])
    sum_y_a0_a1x_2 = sum(df['(y-a0-a1x)^2'])
    space = ["" for _ in range(len(df['xy']))]
    df.index = space
    df.loc['Total'] = df.sum()
    print(df)
    
    # Find Correlation Coefficient 
    coefficient = (sum_y_min_yMean-sum_y_a0_a1x_2)/(sum_y_min_yMean)
    print(f"\nThe correlation coefficient is: {coefficient:.4}")
    
    # The standard deviation
    sy = (sum_y_min_yMean/(n-1))**0.5
    print(f"The standard deviation sy is: {sy:.4}")
    
    # The standard error estimation
    syx = (sum_y_a0_a1x_2/(n-2))**0.5
    print(f"The standard error estimation sy/x is: {syx:.4}")
    
    # The linear regression model
    r = (sum_y_min_yMean-sum_y_a0_a1x_2)/sum_y_min_yMean
    r2  = ((sum_y_min_yMean-sum_y_a0_a1x_2)/sum_y_min_yMean)**0.5
    print(f"The linear regression model r^2 is: {r:.4}")
    print(f"The linear regression model r is: {r2:.4}")
    
    # The least square fit 
    print(f"The least square fit y is {a0:.4} + {a1:.4}^2")
    
    
if __name__ == "__main__":
    x = list(map(float,input("Enter the x (space separated): ").split()))
    y = list(map(float,input("Enter the y (space separated): ").split()))
    # x = [1,2,3,4,5]
    # y = [0.6,2.4,3.5,4.8,5.7]
    linerRegression(x,y)