//93C
#include <bits/stdc++.h>

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

	int t;
	cin >> t;
	while (t--) {
		int n;
		string arr;
		cin >> n >> arr;

		int prefix[n+1];
		prefix[0] = 0;
		for (int i = 0; i < n; i++) {
			prefix[i + 1] = arr[i] - '0';
			prefix[i + 1] += prefix[i];
		}

		unordered_map<int, int> goodParts;
		for (int i = 0; i <= n; i++) {
			goodParts[prefix[i] - i]++;
		}

		int sum = 0;
		for (auto &it : goodParts) {
			sum += (it.second * (it.second - 1))/2;
		}

		cout << sum << endl;
	}

    return 0;
}