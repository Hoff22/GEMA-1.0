#include <bits/stdc++.h>

using namespace std;

/* O(N). */
int main(){
	string s, t;
	int i, ans;

	cin >> s;
	cin >> t;

	ans = 0;

	// Contando o número de posições em que S é diferente de T.
	for (i = 0; i < (int)s.size(); i++){
		if (s[i] != t[i]){
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}