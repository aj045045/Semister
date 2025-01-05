import pandas as pd

data = {
    "a":[],
    "f(a)":[],
    "b":[],
    "f(b)":[],
    "c":[],
    "f(c)":[],
    "|Ck-ck-1|":[],

}

def fMethod(num:int)->int:
    return num**3 - 4*num - 9

def cCal(a:int,b:int)->int:
    d1 = a*fMethod(b) - b*fMethod(a)
    d2 = fMethod(b) - fMethod(a)
    return d1 / d2

def setOutput(a: float,b: float,c: float,ck:float)->None:
    data["a"].append(a)
    data["f(a)"].append(fMethod(a))
    data["b"].append(b)
    data["f(b)"].append(fMethod(b))
    data["c"].append(c)
    data["f(c)"].append(fMethod(c))
    data["|Ck-ck-1|"].append(ck)
    return None

a = float(input("Enter a :"))
b = float(input("Enter b :"))
e = float(input("Enter e :"))
c = []
k = 0

if fMethod(a) * fMethod(b) < 0:
    k += 1

c.append(cCal(a,b))
setOutput(a,b,c[-1],0)

while True:
    if fMethod(a)*fMethod(c[-1])<0:
        b = c[-1]
    elif fMethod(a)* fMethod(c[-1])>0:
        a = c[-1]
    else:
        break

    c.append(cCal(a,b))
    if len(c) >= 2:
        setOutput(a,b,c[-1],abs(c[-1]-c[-2]))
    else:
        setOutput(a,b,c[-1],0)
    if c[-1] - c[-2] < e:
        break
    else:
        k +=1

print(f"\nRoot of the equation is: {c[-1]}")        
print(f"Number of iterations is: {k}\nThe FalsePosition Table:")        
print(pd.DataFrame(data,index=range(1,len(c)+1)))