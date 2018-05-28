#include <bits/stdc++.h>

using namespace std;

/* O(N^2). */
int main(){
	int n, ans, left, right, i, j;
	string str;

	cin >> str;
	n = str.size();

	ans = 0;

	// Para cada posição que houver um 'b'.
	for (i = 0; i < n; i++){
		if (str[i] == 'b'){
			left = right = 0;

			// Contando o número de 'a's a esquerda de str[i].
			for (j = 0; j < i; j++){
				if (str[j] == 'a'){
					left++;
				}
			}

			// Contando o número de 'a's a direita de str[i].
			for (j = i + 1; j < n; j++){
				if (str[j] == 'a'){
					right++;
				}
			}

			// Somando o número de subsequências das quais esse 'b' participa.
			ans += left * right;
		}
	}

	cout << ans << endl;

	return 0;
}