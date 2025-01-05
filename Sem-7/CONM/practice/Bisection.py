import pandas as pd

data = {
    "a":[],
    "f(a)":[],
    "b":[],
    "f(b)":[],
    "c":[],
    "f(c)":[],
    "|Ck-Ck-1|":[],
}

def fMethod(num:int)->int:
    return num**3 - num - 1

def setOutput(a: float,b: float,c: float,ci: float)->None:
    data["a"].append(a)
    data["f(a)"].append(fMethod(a))
    data["b"].append(b)
    data["f(b)"].append(fMethod(b))
    data["c"].append(c)
    data["f(c)"].append(fMethod(c))
    data["|Ck-Ck-1|"].append(ci)
    return None

c = []
k = 1
a = float(input("Enter a :"))
b = float(input("Enter b :"))
e = float(input("Enter e :"))
c.append((a+b)/2)
setOutput(a,b,c[-1],0)

if  fMethod(a) * fMethod(b) < 0:
    k += 1
    
while True:
    if fMethod(a) * fMethod(c[-1])<0:
        b = c[-1]
    elif fMethod(a) * fMethod(c[-1])>0:
        a = c[-1]
    else:
        break
    c.append((a+b)/2)
    
    if len(c) >= 2:
        setOutput(a,b,c[-1],abs(c[-1]-c[-2]))
    else:
        setOutput(a,b,c[-1],0)
        
    if abs(c[-1]- c[-2])<e:
        break
    else:
        k +=1
    
print(f"\nRoot of the equation is: {c[-1]}")
print(f"Number of iterations: {k}\nThe Bisection method:")
print(pd.DataFrame(data,index=range(1,len(c)+1)))
