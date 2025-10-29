import math

# Function to find the minimum number of coins required
def min_coins(n):
    coins = [15, 10, 6, 3, 1]
    count = 0
    for coin in coins:
        count += n // coin
        n %= coin
    return count

# Input
t = int(input())
for _ in range(t):
    n = int(input())
    # Output
    print(min_coins(n))