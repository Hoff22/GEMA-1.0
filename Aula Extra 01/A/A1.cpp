#include <bits/stdc++.h>

using namespace std;

/* O(N^3). */
int main(){
	int n, ans, i, j, k;
	string str;

	cin >> str;
	n = str.size();

	ans = 0;

	// Para cada tripla de índices (i, j, k). Isso equivale a (n escolhe 3).
	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			for (k = j + 1; k < n; k++){
				if (str[i] == 'a' and str[j] == 'b' and str[k] == 'a'){
					ans++;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}