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

const int nax = 1e3;
bool board;
int N;
bool isSafe(int row, int col) {
	for (int i = 0; i < col; ++i) if (board[row][i]) return false;
	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) if (board[i][j]) return false;
	for (int i = row, j = col; i < N && j >= 0; ++i, --j) if (board[i][j]) return false;
	return true;
}

bool nQueen(int col) {
	if (col >= N) return true;
	for (int i = 0; i < N; ++i) {
		if (isSafe(i, col)) {
			board[i][col] = true;
			if (nQueen(col + 1)) return true;
			board[i][col] = false;
		}
	}
	return false;
}

void print() {
	printf("For %d X %d board\n", N, N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j]) printf("Q ");
			else printf("_ ");
		}
		puts("");
	}
	puts("");
}

void solve() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			board[i][j] = false;
    }
	}
	if (!nQueen(0)) printf("No solution for %d X %d board\n", N, N);
	else print();

}

int main() {
	fastIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	// t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
