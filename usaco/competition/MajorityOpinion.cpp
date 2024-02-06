//100%
#include <bits/stdc++.h>

bool checkNum(int *cows, int i, int n) {
	for (int j = 0; j < n-1; j++) {
		if (cows[j] == i && cows[j+1] == i) return true;
		if (j < n-2) {
			if (cows[j] == i && cows[j+2] == i) return true;
		}
	}

	return false;
}

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cows[n] = {0};
		vector<int> solutions;
		unordered_set<int> cache;

		for (int i = 0; i < n; i++) {
			int c;
			cin >> c;
			cows[i] = c;

			if (i >= 2 && cows[i] == cows[i-2] && cache.find(c) == cache.end()) {
				cache.insert(c);
				solutions.push_back(c);
			}

			if (i >= 1 && cows[i] == cows[i-1] && cache.find(c) == cache.end()) {
				cache.insert(c);
				solutions.push_back(c);
			}
		}

		sort(solutions.begin(),solutions.end());


		if (solutions.size() == 0) cout << -1;
		else for (int i = 0; i < solutions.size(); i++) {
			cout << solutions[i];
			if (i != solutions.size()-1) cout << " ";
		}
		cout << endl;
	}
}