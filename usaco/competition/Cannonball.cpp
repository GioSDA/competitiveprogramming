//100%
#include <bits/stdc++.h>

using namespace std;

struct tile {
	int type;
	int value;
};

int main() {
	int n,pos;
	cin >> n >> pos;

	pos--;
	int power = 1;
	int dir = 1;

	vector<tile> line;
	for (int i = 0; i < n; ++i)
	{
		tile a;
		cin >> a.type >> a.value;
		line.push_back(a);
	}

	int targetsBroken = 0;
	int loopCheck = 0;
	while (pos >= 0 && pos < n) {
		if (line[pos].type == 0) {
			dir = -dir;
			power += line[pos].value;
		} else if (line[pos].type == 1) {
			if (power >= line[pos].value) {
				targetsBroken++;
				line[pos].type = 2;
			}
		}

		loopCheck++;
		if (loopCheck > n*10) break;
		pos += power * dir;
	}

	cout << targetsBroken;
}