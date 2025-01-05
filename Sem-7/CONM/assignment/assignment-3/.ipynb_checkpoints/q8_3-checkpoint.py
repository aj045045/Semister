#Write a program to Compute f ′(0) from the data
# Given data
x = [0, 1, 2, 3, 4]
y = [1, 2.718, 7.381, 20.086, 54.598]

# Calculate step size
h = x[1] - x[0]  # assuming uniform spacing

# Manually compute forward differences
n = len(x)
forward_diff = [[0 for _ in range(n)] for _ in range(n)]  # Create an empty table
for i in range(n):
    forward_diff[i][0] = y[i]  # Fill the first column with y values

# Fill the forward difference table
for j in range(1, n):
    for i in range(n - j):
        forward_diff[i][j] = forward_diff[i+1][j-1] - forward_diff[i][j-1]

# Extract required forward differences
delta_y0 = forward_diff[0][1]  # First forward difference
delta2_y0 = forward_diff[0][2]  # Second forward difference

# Compute f'(0) using the forward difference formula
f_prime_0 = (delta_y0 - (delta2_y0 / 2)) / h

# Display the result
print("Forward Difference Table:")
for row in forward_diff:
    print(row)
print("\nf'(0) =", f_prime_0)