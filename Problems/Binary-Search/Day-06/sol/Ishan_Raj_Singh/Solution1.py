"""
Submission Link: https://codeforces.com/contest/2014/submission/356141020

Approach:
1. If n <= 2, impossible to have more than half unhappy -> return -1
2. Sort the wealth array
3. Calculate current sum
4. Find the median position (n//2)
5. Use mathematical formula: For median person to be unhappy:
   (sum + X) / (2 * n) > a[median]
   Solving: X > 2 * n * a[median] - sum
   Therefore: X = 2 * n * a[median] - sum + 1

"""

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    if n <= 2:
        print(-1)
        return
    
    a.sort()
    
    total_sum = sum(a)
    
    mid = n // 2
    
    current_avg = total_sum / n
    unhappy_count = sum(1 for wealth in a if wealth < current_avg / 2)
    
    if unhappy_count > n / 2:
        print(0)
        return
    
    X = 2 * n * a[mid] - total_sum + 1
    
    if X < 0:
        print(0)
    else:
        print(X)

t = int(input())
for _ in range(t):
    solve()