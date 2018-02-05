#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 1000010
#define SEED 31
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
using namespace std;

string A, B, ans;
ll idx1, idx2;
int curridx;
ll hashed[MAXN];

/* 
 * Solution is simple: Use a hashing algorithm to get the index at which the suffix of A is equal to the prefix of B
 * After, just combine the two strings - string A with the substring of B at the given index
 */

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	hashed[0] = 1;
	cin >> A >> B;
	for (int i=1; i<min(A.length(), B.length()); i++) hashed[i] = hashed[i - 1] * SEED;
	for (int i=0; i<min(A.length(), B.length()); i++) {
		// Check every character by reversing string A
		idx1 += hashed[i] * (A[A.size() - i - 1] - 'A');
		idx2 *= SEED;
		idx2 += B[i] - 'A'; 
		if (idx1 == idx2) curridx = i + 1;
	}
	cout << A << B.substr(curridx) << endl;
	return 0;
}