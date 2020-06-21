#include<bits/stdc++.h>
using namespace std;
int main() {
	int size, n, res = 0;
	cin >> size >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	int prev, curr; cin >> prev >> curr;  a.push_back(curr);
	bool toLeft = prev - curr > 0 ? true : false;
	auto ptr = [&](int x) {
		a.push_back(x); sort(a.begin(), a.end()); // O(nlogn)
		return lower_bound(a.begin(), a.end(), curr) - a.begin() + 1; //O(logn)
	};
	int loc;
	if (toLeft) {
		loc = ptr(0);
		reverse(a.begin(), a.begin() + loc); // O(n)
	}
	else {
		loc = ptr(size);
		reverse(a.begin(), a.begin() + loc - 1); // O(loc + 1)
		rotate(a.begin(), a.begin() + loc - 1, a.end()); // O(n - loc - 1)
	}
	cout << "Movement : " << curr << "->";
	for (int i = 1; i < n + 2; ++i) res += abs(a[i - 1] - a[i]), cout << a[i] << "->";
	cout << "\nTotal Movement : " << res << endl;
	return 0;
}