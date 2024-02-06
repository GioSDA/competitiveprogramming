#include "bits/stdc++.h"

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define double long double
#define int long long
#define GioSDA int32_t

using namespace std;

void setIO(string name) {
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }

    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
} 

GioSDA main() {
    setIO("");

    int n,q;
    cin >> n >> q;
    int prefixes[n];

    prefixes[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> prefixes[i + 1];
        prefixes[i + 1] += prefixes[i]; 
    }    

    while (q--) {
        int l,r;
        cin >> l >> r;
        cout << prefixes[r] - prefixes[l] << endl;
    }

    return 0;
}