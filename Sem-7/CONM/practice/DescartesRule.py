
def countSignChange(coefficient: list):
    """Count Number of sign changes in the list of coefficient"""
    signChanges = 0
    prevSign = None
    for coeff in coefficient:
        if coeff != 0:
            currentSign = coeff > 0
            if prevSign is not None and currentSign != prevSign:
                signChanges +=1
            prevSign = currentSign
    return signChanges
    
    
def descartesRule(coefficient:list):
    """Apply descartes rule of sign to determine the possible number of positive and negative roots"""
    positiveSignChange = countSignChange(coefficient)
    
    negativeCoefficient = [(-1)**i * coeff for i, coeff in enumerate(coefficient)]
    negativeSignChange = countSignChange(negativeCoefficient)
    
    positivePossibleRoot = list(range(positiveSignChange,-1,-2))
    negativePossibleRoot = list(range(negativeSignChange,-1,-2))
    
    return positiveSignChange, positivePossibleRoot, negativeSignChange, negativePossibleRoot

if __name__ == "__main__":
    coefficient = list(map(float,input("Enter the coefficients of the polynomial (higher degree first separated by space): ").split()))
    positiveSignChange,positivePossibleRoot, negativeSignChange,negativePossibleRoot = descartesRule(coefficient)
    
    print(f"\nNumber of sign changes for positive roots: {positiveSignChange}")
    print(f"Possible number of positive real roots: {positivePossibleRoot}")
    print(f"Number of sign changes for negative roots: {negativeSignChange}")
    print(f"Possible number of negative real roots: {negativePossibleRoot}")
