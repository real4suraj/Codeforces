#include<bits/stdc++.h>
using namespace std;

int main() {
	int size, n, res = 0;
	cin >> size >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	int prev, curr; cin >> prev >> curr;
	a.push_back(curr);
	bool toLeft = prev - curr > 0 ? true : false;
	auto ptr = [&](int x) {
		sort(a.begin(), a.end());
		return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
	};
	int loc = ptr(curr);
	if (toLeft) {
		reverse(a.begin(), a.begin() + loc);
		reverse(a.begin() + loc, a.end());
	}
	else {
		rotate(a.begin(), a.begin() + loc - 1, a.end());
	}
	cout << "Movement : " << curr << "->";
	for (int i = 1; i <= n; ++i) res += abs(a[i - 1] - a[i]), cout << a[i] << "->";
	cout << "\nTotal Movement : " << res << endl;
	return 0;
}