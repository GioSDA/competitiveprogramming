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
    setIO("hps");

    int n;
    cin >> n;

    int h[n+5] = {0};
    int p[n+5] = {0};
    int s[n+5] = {0};

    for (int i = 0; i < n; i++) {
        h[i+1] = h[i];
        p[i+1] = p[i];
        s[i+1] = s[i];

        char c;
        cin >> c;

        if (c == 'H') h[i+1]++;
        else if (c == 'P') p[i+1]++;
        else if (c == 'S') s[i+1]++;
    }

    int maximum = 0;
    //Start with hoof
    for (int i = 0; i < n; i++) {
        maximum = max(h[i] + p[n] - p[i], maximum);
        maximum = max(h[i] + s[n] - s[i], maximum);
    }

    //Start with paper
    for (int i = 0; i < n; i++) {
        maximum = max(p[i] + h[n] - h[i], maximum);
        maximum = max(p[i] + s[n] - s[i], maximum);
    }

    //Start with scissors
    for (int i = 0; i < n; i++) {
        maximum = max(s[i] + p[n] - p[i], maximum);
        maximum = max(s[i] + h[n] - h[i], maximum);
    }

    cout << maximum;

    return 0;
}