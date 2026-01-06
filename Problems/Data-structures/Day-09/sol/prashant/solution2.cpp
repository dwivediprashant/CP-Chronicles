// ----------------------------------------------------------------------
//                   ██████╗ ██████╗ ██████╗ ███████╗
//                  ██╔════╝██╔═══██╗██╔══██╗██╔════╝
//                  ██║     ██║   ██║██║  ██║█████╗
//                  ██║     ██║   ██║██║  ██║██╔══╝
//                  ╚██████╗╚██████╔╝██████╔╝███████╗
//                   ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
// ----------------------------------------------------------------------
//                       Prashant'S CP TEMPLATE
//                       "Think. Code. Conquer."
// ----------------------------------------------------------------------
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<bit>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<iterator>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstdint>
#include<cstdlib>
using namespace std;
#define ll long long
#define int long long
#define MOD 1000000007
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(x) (int)(x).size()
#define srt(v) sort(v.begin(),v.end())
#define Rsrt(v) sort(v.begin(),v.end(),greater<int>())
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define umap unordered_map
#define mii map<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i>b;i--)
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
class FenwickTree{
    public:
    vi tree;
    int n;
    FenwickTree(int size){
        n=size;
        tree.assign(n+1,0);
    }
    void update(int idx,int val){
        while(idx<=n){
            tree[idx]+=val;
            idx+=idx&(-idx);
        }
    }
    int query(int idx){
        int sum=0;
        while(idx>0){
            sum+=tree[idx];
            idx-=idx&(-idx);
        }
        return sum;
    }
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    fr(i,0,n) cin>>a[i];
    vi sorted_a=a;
    srt(sorted_a);
    map<int,int> compress;
    fr(i,0,n){
        compress[sorted_a[i]]=i+1;
    }
    vi compressed(n);
    fr(i,0,n){
        compressed[i]=compress[a[i]];
    }
    vi leftGreater(n);
    FenwickTree ft1(n);
    fr(i,0,n){
        leftGreater[i]=i-ft1.query(compressed[i]);
        ft1.update(compressed[i],1);
    }
    vi rightSmaller(n);
    FenwickTree ft2(n);
    frr(i,n-1,-1){
        rightSmaller[i]=ft2.query(compressed[i]-1);
        ft2.update(compressed[i],1);
    }
    int answer=0;
    fr(i,0,n){
        answer+=leftGreater[i]*rightSmaller[i];
    }
    cout<<answer<<endl;
    return 0;
}
