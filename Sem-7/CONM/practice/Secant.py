import pandas as pd

data = {
    "x0" : [],
    "fx0" : [],
    "x1" : [],
    "fx1" : [],
    "x2" : [],
    "fx2" : [],
    "|(fxi-1)-(fxi)|":[],
}

def fMethod(num : float) -> float:
    return num**3 - num -1

def fCal(x:float,y:float) -> float:
    return (y*fMethod(x) - x*fMethod(y)) / (fMethod(x) - fMethod(y)) 

def setOutput(x: float,y: float,c: float,xix:float)->None:
    data["x0"].append(x)
    data["fx0"].append(fMethod(x))
    data["x1"].append(y)
    data["fx1"].append(fMethod(y))
    data["x2"].append(c)
    data["fx2"].append(fMethod(c))
    data["|(fxi-1)-(fxi)|"].append(xix)
    return None

k = 1
x = float(input("Enter the xi value :"))
y = float(input("Enter the xi-1 value :"))
e = float(input("Enter the error value :"))
c = []

while True:
    c.append(fCal(x,y))
    if len(c) >= 2:
        setOutput(x,y,c[-1],abs(c[-1] - c[-2]))
        if abs(c[-1] - c[-2]) < e:
            break
    else:    
        setOutput(x,y,c[-1],0)
    x = y
    y = c[-1]
    k +=1

print(f"\nNumber of iteration :\t{k}\n The Secant Table is :\n")
print(pd.DataFrame(data,index=range(1,len(c)+1)))