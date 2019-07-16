#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int CYCLE = 720;
int D, TIME = 1200, minutes, hours, ans;

int main () {
	scanf("%d", &D);
	ans += 31 * (D / 720);
	for (int i=0, size = (D % 720); i<size; i++) {
		TIME++;
		minutes = TIME % 100;
		hours = TIME / 100;
		if (minutes >= 60) {
			hours++;
			minutes -= 60;
		}
		if (hours > 12) hours -= 12;
		TIME = 100 * hours + minutes;
		if (TIME >= 1000) {
			int a, b, c, d;
			a = TIME / 1000;
			b = (TIME % 1000) / 100;
			c = (TIME % 100) / 10;
			d = TIME % 10;
			if (a - b == b - c && b - c == c - d) ans++;
		}
		else {
			int a, b, c, d;
			a = TIME / 100;
			b = (TIME % 100) / 10;
			c = TIME % 10;
			if (a - b == b - c) ans++;
		}
	}
	return 0 * printf("%d\n", ans);
}