//10/15
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long a[n] = {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long iterations = 0; 
	for (int i = 0; i < n; i++) {
		long long diff1 = -a[i];
		long long diff =  -a[i];
		iterations += abs(diff);
		for (int j = i; j < n; j++) {
			a[j] += diff;
			diff += diff1;
		}

		// for (auto &it : a) cout << it << " ";
		// cout << endl;
	}

	cout << iterations;
}