#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	cout << "100\n";
	for(int i = 0; i < 50; ++i) cout << a << " ";
	for(int i = 50; i < 95; ++i) cout << b << " ";
	for(int i = 95; i < 99; ++i) cout << c << " ";
	cout << c + 1 << "\n";
}
