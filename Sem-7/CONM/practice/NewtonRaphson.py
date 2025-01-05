import pandas as pd

data ={
    "xi":[],
    "f(xi)":[],
    "f'(xi)":[],
    "xi+1":[],
    "|Ck-Ck-1|":[],
}

def fMethod(num:float)-> float:
    return num**3 - 4*num - 9

def fNotMethod(num: float)-> float:
    return 3*num**2 - 4

def setOutput(x: float) -> None:
    fx = fMethod(x)
    fnx = fNotMethod(x)
    xi = x - (fx/fnx)
    data["xi"].append(x)
    data["f(xi)"].append(fx)
    data["f'(xi)"].append(fnx)
    data["xi+1"].append(xi)
    if len(data["xi+1"]) >= 2:
        data["|Ck-Ck-1|"].append(abs(data['xi+1'][-2] - data["xi+1"][-1]))
    else:
        data["|Ck-Ck-1|"].append(0)
    return None

x = float(input("Enter the x value :"))
e = float(input("Enter the e value :"))

while True:
    setOutput(x)
    if data["|Ck-Ck-1|"][-1] < e and len(data["|Ck-Ck-1|"]) >= 2:
        break
    x = data["xi+1"][-1]
    
print(pd.DataFrame(data,index=range(1,len(data["|Ck-Ck-1|"])+1)))