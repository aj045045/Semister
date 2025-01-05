"""Lagrange Interpolation"""

def lagrangeInterpolation(x:list,fx:list,r:int):
    if len(x) != len(fx):
        raise ValueError("The length of x and fx must be the same")
    val = []
    for i in range(len(x)):
        numerator = 1
        denominator = 1
        for k in range(len(x)):
            if k != i:
                numerator*=r-x[k]
                denominator*=x[i]-x[k]
        val.append(numerator*fx[i]/denominator)
    print(f"\nThe Interpolation of {r} is: {sum(val)}")
    
if __name__ == "__main__":
    x = list(map(float,input("Enter the x (space separated): ").split()))
    fx = list(map(float,input("Enter the fx (space separated): ").split()))
    k = float(input("Enter the interpolation value: "))
    # x = [-1,1,4,7]
    # fx = [-2,0,63,342]
    # k = 5
    lagrangeInterpolation(x,fx,k)