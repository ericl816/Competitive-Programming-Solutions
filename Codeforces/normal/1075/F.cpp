#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 200 * 1000 + 7;

map<int, pair<int, int> > p;
map<int, int> w;

void ad(int v) {
    if (!p.count(v)) {
        p[v] = {-1, 0};
        w[v] = 1;
    }
}

pair<int, int> getp(int v) {
    if (p[v].first == -1) {
        return {v, 0};
    }
    auto xr = getp(p[v].first);
    p[v] = make_pair(xr.first, p[v].second ^ xr.second);
    return p[v];
}

void join(int u, int v, int x) {
    auto cu = getp(u);
    auto cv = getp(v);
    assert(cu.first != cv.first);
    if (w[cu.first] < w[cv.first]) {
        swap(u, v);
        swap(cu.first, cv.first);
    }
    w[cu.first] += w[cv.first];
    p[cv.first] = make_pair(cu.first, x ^ cu.second ^ cv.second);
}

int get(int l, int r) {
    auto cl = getp(l);
    auto cr = getp(r);
    if (cl.first != cr.first) {
        return -1;
    } else {
        return cl.second ^ cr.second;
    }
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int q;
    cin >> q;
    int last = 0;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;
            if (l > r) {
                swap(l, r);
            }
            r++;
            ad(l), ad(r);
            if (get(l, r) == -1) {
                join(l, r, x);
            }
        } else {
            int l, r;
            cin >> l >> r;
            l ^= last;
            r ^= last;
            if (l > r) {
                swap(l, r);
            }
            r++;
            ad(l), ad(r);
            int ans = get(l, r);
            if (ans == -1) {
                last = 1;
            } else {
                last = ans;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}