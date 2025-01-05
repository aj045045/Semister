import pandas as pd

def bCal(data,guess: float)->None:
    val = data["ai"][len(data["bi"])] + (data["bi"][-1] * guess)
    data["bi"].append(val)
    return None

def cCal(data,guess: float)->None:
    val = data["bi"][len(data["ci"])] + (data["ci"][-1] * guess)
    data["ci"].append(val)
    return None

#TODO - Take input
coefficient = str(input("Enter the coefficients (eg : -2,3,-121) :"))
guess = float(input("Enter the initial guess :"))
listCoefficient = [float(val) for val in coefficient.split(",")]
outputList = []
k = 0
while True:
    data = {
        "ai":[],
        "bi":[],
        "ci":[],
    }
    
    #NOTE - Convert string input into number
    data["ai"] = listCoefficient
    data["bi"].append(listCoefficient[0])
    data["ci"].append(listCoefficient[0])

    while True:
        bCal(data,guess)
        cCal(data,guess)
        if len(data["ai"]) == len(data["bi"]) == len(data["ci"]):
            guess = guess - (data["bi"][-1]/data["ci"][-2])
            break
    outputList.append(data)
    k+=1
    if k > 3:
        break

print(f"\nNumber of Iteration {k}\nThe BirgeVieta Table:")
for i in outputList:
    print(pd.DataFrame(i,range(1,len(i["ai"])+1)))
    print()