#include <bits/stdc++.h>

#define fo(i, n) for (int i = 0; i < int(n); i++)
#define of(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define Fo(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size)
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


struct LCA {
	vi segtree, height, euler, first;
	vector<bool> visited;
	int n;

	LCA(vector<vector<int>> &adj, int root = 0) {
		n = sz(adj);
		height.resize(n);
		first.resize(n);
		euler.reserve(2 * n);
		visited.assign(n , false); 
		dfs(adj, root);
		int m = sz(euler);
		segtree.resize(4 * m);
		build(1, 0, m - 1);
	}

	void dfs(vector<vector<int>> &adj, int node , int h = 0) {
		visited[node] = true;
		first[node] = sz(euler);
		height[node] = h;
		euler.pb(node);
		for (auto to : adj[node]) {
			if (!visited[to]) {
				dfs(adj, to, h + 1);
				euler.pb(node);
			}
		}
	}

	void build(int node, int l, int r) {
		if (l == r) {
			segtree[node] = euler[l];
		}
		else {
			int mid = (l + r) / 2;
			build(node << 1, l, mid);
			build(node << 1 | 1, mid + 1, r);
			int p1 = segtree[node << 1];
			int p2 = segtree[node << 1 | 1];
			segtree[node] = height[p1] < height[p2] ? p1 : p2;
		}
	}

	int query(int node, int l, int r, int i, int j) {
		if (l > j || r < i) return -1;
		if (l >= i && r <= j) return segtree[node];

		int mid = (l + r) >> 1;
		int left = query(node << 1, l, mid, i, j);
		int right = query(node << 1 | 1, mid + 1, r, i, j);

		if (left == -1) return right;
		if (right == -1) return left;

		return height[left] < height[right] ? left : right;
	}

	int lca(int u, int v) {
		int left = first[u];
		int right = first[v];
		if (left > right) swap(left, right);
		return query(1, 0, sz(euler) - 1, left, right);
	}
};


void solve() {
  
}

int main() {
	fastIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
//#ifndef ONLINE_JUDGE
   // cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
//#endif

	return 0;
}

