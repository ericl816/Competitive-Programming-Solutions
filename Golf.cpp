#include <bits/stdc++.h>
using namespace std;

int d, c, club[100], dist[5900], i;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
	cin >> d >> c;
	for (i=0; i<d + 1; i++) dist[i] = 1000000;
	for (i=0; i<c; i++) {
		cin >> club[i];
		dist[club[i]] = 1;
	}
	for (i=0; i<d; i++) {
		if (dist[i] ^ 1000000) {
			for (int j=0; j<c; j++) {
				if (dist[i] + 1 < dist[i + club[j]]) dist[i + club[j]] = dist[i] + 1;
			}
		}
	}
	if (dist[i] == 1000000) cout << "Roberta acknowledges defeat." << "\n";
	else cout << "Roberta wins in " << dist[d] << " strokes." << "\n";
    return 0;
}