//#Submission Link: https://codeforces.com/contest/2098/submission/356258492

/*
If n-k is odd, the median is a single specific element in the middle of the subset. So, we calculate median by taking first(n-k) 
houses and then last (n-k) houses. All houses betwen them an them are possible. so ans is 
(median of last n-k)-(median of first n-k)+1.
Similarly for even case, but in this case we have two medians so we take bigger one for last n-k and smaller one for first n-k.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--) {
        long long n, k;
        cin>>n>>k;
        vector<long long> a(n+1);
        for(int i=1; i<=n; i++) cin>>a[i];
        sort(a.begin(), a.end());
        if((n-k)%2!=0) cout<<a[(n+k+1)/2]-a[(n-k+1)/2]+1<<endl;
        else cout<<a[(n+k)/2+1]-a[(n-k)/2]+1<<endl;
    }
}
