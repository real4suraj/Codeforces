#include <bits/stdc++.h>

#define fo(i, n) for (int i = 0; i < int(n); i++)
#define of(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define Fo(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

#define endl '\n'
#define deb(x) cout << #x << " " << x << endl;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}
template<typename... T>
void write(T&&... args) {
	((cout << args << " "), ...);
}

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

ll a, b, c;
bool check(ll l, ll mid, ll r, ll num)
{
	if (num < l || num < mid || num < r)
		return 0;
	ll x = l + mid + r - (3 * num);
	x *= -1;
	if (x < b)
		return 0;
	return 1;
}


void solve() {
	read(a, b, c);
	ll ans = INF64;
	for (ll a1 = 0; a1 < a + 1; ++a1) {
		for (ll c1 = 0; c1 < c + 1; ++c1) {
			if (a1 && c1) continue;

			ll res;
			ll first = a - a1;
			ll middle = a1 + c1;
			ll last  = c - c1;

			ll hi = b + max(first, max(middle, last));
			ll lo = min(first, min(middle, last));

			while (lo <= hi) {
				ll mid = (lo + hi) / 2;
				if (check(first, middle, last, mid)) {
					res = mid;
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}
			ans = min(res, ans);
		}
	}
	cout << ans << endl;
}

int main() {
	fastIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
//#ifndef ONLINE_JUDGE
//    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
//#endif

	return 0;
}