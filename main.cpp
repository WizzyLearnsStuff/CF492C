#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int main() {
	long long int n, r, av;
	cin >> n >> r >> av;

	long long int sum = av * n;

	vector<pair<int, int>> v(n);
	for (auto &e : v) {
		cin >> e.first >> e.second;
		sum -= e.first;
		e.first = r - e.first;
	}

	if (sum <= 0) {
		cout << '0';
		return 0;
	}

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	});

	unsigned long long int essays = 0;
	for (auto e : v) {
		long long int a = min((long long int)e.first, sum);
		sum -= a;
		essays += a * e.second; 
		if (sum == 0) break;
	}

	cout << essays;
}
