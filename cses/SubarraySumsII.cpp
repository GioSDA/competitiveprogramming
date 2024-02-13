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
    int x,n;
    cin >> n >> x;

    vector<int> prefix(n+1);
    for (int i = 0; i < n; i++) {
        cin >> prefix[i+1];
        prefix[i+1] += prefix[i];
    }

    int sum = 0;
    map<int, int> occurences;
    for (int i = n; i >= 0; i--) {
        sum += occurences[prefix[i] + x];

        occurences[prefix[i]]++;
    }

    cout << sum << endl;

    return 0;
}