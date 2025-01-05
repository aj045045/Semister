"""Backward Interpolation"""
import pandas as pd

def dividedDifference(x:list,fx:list):
    n = len(x)
    data = {'x':x}
    df = pd.DataFrame(data)
    df['f(x)'] = fx
    
    for i in range(n):
        if i == 0:
            df[f'{i}_f'] = fx
        else:
            df[f'{i}_f'] = pd.NA
    
    for i in range(1,n):
        for j in range(n-i):
            df.at[j,f'{i}_f'] = (df.at[j + 1, f'{i - 1}_f'] - df.at[j, f'{i - 1}_f'])
        if df[f'{i}_f'].dropna().tolist().count(0) == n-i:
            break    
    df.drop(columns='0_f',inplace=True)
    df.dropna(axis=1, how='all',inplace=True)
    return df

def backwardInterpolation(x:list,fx:list,h:int,kl:list):
    if len(x) != len(fx):
        raise ValueError("The length of x and fx is not same")
    df = dividedDifference(x,fx)
    f1 = df[f'1_f'].dropna().tolist()
    f2 = df[f'2_f'].dropna().tolist()
    print(df)
    for k in kl:
        result = fx[-1] + (k-x[-1])*(f1[-1]/h)+(k-x[-1])*(k-x[-2])*(f2[-1]/2*h**2)
        print(f"The Newton Forward Difference of {k} is: ",result)
if __name__ == "__main__":
    
    x =  list(map(float,input("Enter the x for the divided difference (space separated): ").split()))
    fx = list(map(float,input("Enter the fx for the divided difference (space separated): ").split())) 
    k =  list(map(float,input("Enter the x (space separated): ").split()))
    h =  float(input("Enter the h: "))
    # x = [0.1,0.2,0.3,0.4,0.5]
    # fx = [1.40,1.56,1.76,2.00,2.28]
    # k = [0.25,0.35]
    # h = 0.1
    backwardInterpolation(x,fx,h,k)