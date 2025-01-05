"""Froward Interpolation"""

import pandas as pd

def dividedDifference(x:list,fx:list):
    n = len(x)
    data = {'x':x}
    df = pd.DataFrame(data)
    df['f(x)'] = fx
    for i in range(n):
        if i == 0:
            df[f'{i}_f']=fx
        else:
            df[f'{i}_f']=pd.NA
            
    for j in range(1,n):
        for i in range(n-j):
            df.at[i,f'{j}_f'] = (df.at[i+1,f'{j-1}_f'] - df.at[i,f'{j-1}_f'])
        
        if df[f'{j}_f'].dropna().tolist().count(0) == n-j:
            break        
    df.drop(columns='0_f',inplace=True)
    df.dropna(axis=1, how='all',inplace=True)
    return df
    
def forwardInterpolation(x:list,fx:list,k:int,h:int):
    if len(x) != len(fx):
        raise ValueError("The length of x and fx must be the same")
    df = dividedDifference(x,fx)
    result = fx[0] + (k-x[0])*(df['1_f'][0]/h)+(k-x[0])*(k-x[1])*(df['2_f'][0]/2*h**2)
    print(df)
    print("The Newton Forward Difference is: ",result)
    
if __name__ == "__main__":
    x = list(map(float,input("Enter the x for divided difference (space separated): ").split()))
    fx = list(map(float,input("Enter the fx  for divided difference (space separated): ").split()))
    k = float(input("Enter the value of x: "))
    h = float(input("Enter the value of h: "))
    # x = [-2,-1,0,1,2,3]
    # fx = [15,5,1,3,11,25]
    # k = 0.5
    # h = 1
    forwardInterpolation(x,fx,k,h)