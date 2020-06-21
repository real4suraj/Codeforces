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

unordered_map<ll, bool> Mp;
ll n , m;
void solve() {
	read(n , m);
	vi a(n);
	vi b(m);
	for (auto &x : a) read(x);
	for (auto &x : b) read(x);
	reverse(all(b));
	ll pre = 0, ans = 0, last = 0;
	while (sz(b)) {
		ll x = b.back();
		if (Mp[x]) {
			ans++;
			pre++;
		}
		else {
			for (ll i = last; i < n; ++i) {
				if (a[i] == x) {
					ans += (i - pre) * 2 + 1;
					pre++;
					last = i + 1;
					break;
				}
				Mp[a[i]] = true;
			}
		}
		b.pop_back();
	}
	cout << ans << "\n";
	Mp.clear();
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