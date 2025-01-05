"""Newton's Divided Difference Interpolation"""

import pandas as pd

def dividedInterpolation(x: list, fx: list,k:list) -> pd.DataFrame:
    if len(x) != len(fx):
        raise ValueError("The length of x and fx must be the same")
    n = len(x)
    data = {'x': x}
    df = pd.DataFrame(data)
    df['f(x)'] = fx
    for j in range(n):
        if j == 0:
            df[f'{j}_dd'] = fx
        else:
            df[f'{j}_dd'] = pd.NA 
    
    for j in range(1, n):
        for i in range(n - j):
            df.at[i, f'{j}_dd'] = (df.at[i + 1, f'{j - 1}_dd'] - df.at[i, f'{j - 1}_dd']) / (x[i + j] - x[i])
        if df[f'{j}_dd'].dropna().tolist().count(0) == n-j:
            break    
    
    df.drop(columns='0_dd',inplace=True)
    df.dropna(how='all',inplace=True,axis=1)
    
    for kv in k:
        total = df['f(x)'][0]
        for j in range(1,len(df)-2):
            cal = [kv-x[ran] for ran in range(j)]
            multiply = 1
            for ran in cal:
                multiply*=ran
            total+=(multiply*df[f'{j}_dd'][0])
        print(f'The interpolation of {kv} is \t{total}')
    return df

if __name__ == "__main__":
    # x = list(map(float,input("Enter the x (space separated): ").split()))
    # fx = list(map(float,input("Enter the f(x) (space separated): ").split()))
    # x = [1,3,4,5,7,10]
    # fx = [3,31,69,131,351,1011]
    # k = [3.5,8.0]
    x = [-1,0,3,6,7]
    fx = [3,-6,39,822,1611]
    k = [2]
    response = dividedInterpolation(x,fx,k)
    print("\n",response)