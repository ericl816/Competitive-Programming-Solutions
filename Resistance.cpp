#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include <algorithm>   
#include <iostream>   
#include <sstream>   
#include <string>   
#include <vector>   
#include <queue>   
#include <set>   
#include <map>   
#include <cstdio>   
#include <cstdlib>   
#include <cctype>   
#include <cmath>   
#include <cstring> 
#include <list>   
#include <cassert> 
#include <climits> 
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

class Resistance {
public:
	vector<double> spyProbability (int P, int S, vector<string> missions) {
		vi num(P, 0);
		int denom = 0;
		for (int i=0; i<(1 << P); i++) {
			int cnt_spy = 0;
			for (int j=0; j<P; j++) if (i & (1 << j)) ++cnt_spy;
			// cout << cnt_spy << endl;
			if (cnt_spy != S) continue;
			bool flag = 1; 	
			for (int j=0; j<missions.size(); j++) {
				if (missions[j][0] == 'S') continue;
				bool flag1 = 0;
				for (int k=0; k<P; k++) if (missions[j][k + 1] == '1' && (i & (1 << k)) > 0) flag1 = 1;
				if (!flag1) flag = 0;
			}
			if (flag) {
				++denom;
				for (int j=0; j<P; j++) if (i & (1 << j)) ++num[j];
			}
		}
		if (denom == 0) return vector<double>();
        vector<double> prob(P);
		for (int i=0; i<P; i++) {
			prob[i] = 1.0 * num[i] / denom;
		}
		return prob;
	}
};