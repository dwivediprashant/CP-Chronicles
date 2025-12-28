#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        if ((c <= abs(b - a) * 2) && (abs(b - a) >= min(a, b)))
        {
            if (c + abs(b - a) <= abs(b - a) * 2)
            {
                cout << c + abs(b - a) << endl;
            }
            else
            {
                cout << c - abs(b - a) << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}