#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int N;
    cin>>N;
    int result=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=i;k++){
                for(int l=1;l<=j;l++){
                    int x=(__gcd(k,i))*(__gcd(l,j))*(__gcd(i,j));
                    result+=x;
                }
            }
        }
    }
    cout<<result<<endl;
}
