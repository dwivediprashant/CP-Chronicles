/*

Submission link: https://codeforces.com/contest/61/submission/356395307

TC- o(n log n)
SC - o(n)

Approach:
Take each element as one by one and treat that element as middle element,count number of elements greater than that element on left side of that element and count
number of elements smaller than that element on right side of that element. 

Use a Fenwick Tree (Binary Indexed Tree) to efficiently count elements in ranges, Since array values can be as large as 10^9, first compress the values to ranks 1..n

Do the left to right pass in Fenwick tree to count number of elements greater than current element on left side.

Reset Fenwick tree and do right to left pass to count number of elements smaller than current element on right side.

Finally, for each element multiply the two counts and sum them up to get the final answer.

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000005;
int n;
int a[N], t[N];
int l_big[N], r_small[N];

void add(int i, int v) {
    for (; i <= n; i += i & -i) t[i] += v;
}

int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += t[i];
    return s;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        int rk = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        l_big[i] = i - sum(rk);
        add(rk, 1);
    }

    memset(t, 0, sizeof(t));

    for (int i = n - 1; i >= 0; i--) {
        int rk = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        r_small[i] = sum(rk - 1);
        add(rk, 1);
    }

    ll total = 0;
    for (int i = 0; i < n; i++) {
        total += (ll)l_big[i] * r_small[i];
    }
    cout << total << endl;

    return 0;
}