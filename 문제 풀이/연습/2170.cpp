#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> line;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		line.push_back({ a, b });
	}

	sort(line.begin(), line.end());

	int x = line[0].first;
	int y = line[0].second;
	long long ans = 0;
	for (int i = 1; i < line.size(); i++) {
		if (y >= line[i].first) {
			y = max(y, line[i].second);
		}
		else {
			ans += (y - x);
			x = line[i].first;
			y = line[i].second;
		}
	}
	ans += (y - x);
	cout << ans;
}