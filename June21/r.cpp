//Lord Escanor : Sin Of Pride
//When I was writing this, only God and I knew what the code meant,
//But now, only God knows.
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
long long a[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	long long K = 0;
	for (int i = 0; i < n - 1; i++)
		K = __gcd(K, a[i + 1] - a[i]);
	int y = a[n - 1];
	long long ans = 0;
	for (int i = 0; i < n; i++){
		ans += (y - a[i]) / K;
	}
	cout << ans << ' ' << K;
}
