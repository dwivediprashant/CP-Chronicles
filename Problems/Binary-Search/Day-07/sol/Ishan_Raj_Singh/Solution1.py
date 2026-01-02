"""
Approach: Two Pointers approach
Submission Link: https://codeforces.com/problemset/submission/1538/356144559
"""

def solve_two_pointers():
    n, l, r = map(int, input().split())
    a = list(map(int, input().split()))
    
    a.sort()
    count = 0
    
    for i in range(n):
        min_sum = l - a[i]
        max_sum = r - a[i]
        
        left = i + 1
        right = n - 1
        
        lo, hi = i + 1, n
        while lo < hi:
            mid = (lo + hi) // 2
            if a[mid] < min_sum:
                lo = mid + 1
            else:
                hi = mid
        left_bound = lo
        
        lo, hi = i + 1, n
        while lo < hi:
            mid = (lo + hi) // 2
            if a[mid] <= max_sum:
                lo = mid + 1
            else:
                hi = mid
        right_bound = lo - 1
        
        if left_bound < n and right_bound >= i + 1 and left_bound <= right_bound:
            count += (right_bound - left_bound + 1)
    
    print(count)

t = int(input())
for _ in range(t):
    solve_two_pointers()
