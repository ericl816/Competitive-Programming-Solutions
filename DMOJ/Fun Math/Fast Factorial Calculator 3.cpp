#include <bits/stdc++.h>
#define ull long long
using namespace std;

ull N, MOD;

struct ModInt {
    ull x;

    ModInt() : x(0) {}

    ModInt(ull y) : x(y >= 0 ? y % MOD : (MOD - (-y) % MOD) % MOD) {}
    ModInt& operator+=(const ModInt& p) {
        if ((x += p.x) >= MOD) x -= MOD;
        return *this;
    }

    ModInt& operator-=(const ModInt& p) {
        if ((x += MOD - p.x) >= MOD) x -= MOD;
        return *this;
    }

    ModInt& operator*=(const ModInt& p) {
        x = (__int128_t) x * p.x % MOD;
        return *this;
    }

    ModInt& operator/=(const ModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt& p) const { return x == p.x; }

    bool operator!=(const ModInt& p) const { return x != p.x; }

    ModInt inverse() const {
        ull a = x, b = MOD, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(ull n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const ModInt& p) {
        return os << p.x;
    }

    friend istream& operator>>(istream& is, ModInt& a){
        ull t;
        is >> t;
        a = ModInt(t);
        return is;
    }

    static ull get_mod() { return MOD; }
};
 
using modint = ModInt;
 
namespace FastFourierTransform {
    using real = long double;
    struct C {
        real x, y;

        C() : x(0), y(0) {}

        C(real x, real y) : x(x), y(y) {}

        inline C operator+(const C& c) const { return C(x + c.x, y + c.y); }

        inline C operator-(const C& c) const { return C(x - c.x, y - c.y); }

        inline C operator*(const C& c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }

        inline C conj() const { return C(x, -y); }
    };

    const real TAU = 2 * acosl(-1);
    int base = 1;
    vector<C> rts = { { 0, 0 }, { 1, 0 } };
    vector<int> rev = { 0, 1 };

    void ensure_base(int nbase) {
        if (nbase <= base) return;
        rev.resize(1 << nbase);
        rts.resize(1 << nbase);

        for (int i = 0; i < (1 << nbase); i++)
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

        while (base < nbase) {
            real angle = TAU / (1 << (base + 1));
            for (int i = 1 << (base - 1); i < (1 << base); i++) {
                rts[i << 1] = rts[i];
                real angle_i = angle * (2 * i + 1 - (1 << base));
                rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
            }
            ++base;
        }
    }

    void fft(vector<C>& a, int n) {
        assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;

        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    C z = a[i + j + k] * rts[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
            }
        }
    }

    vector<ull> multiply(const vector<int>& a, const vector<int>& b) {
        int need = a.size() + b.size() - 1, nbase = 1;
        while ((1 << nbase) < need) ++nbase;
        ensure_base(nbase);
        int sz = 1 << nbase;

        vector< C > fa(sz);
        for (int i = 0; i < sz; i++) {
            int x = (i < a.size() ? a[i] : 0), y = (i < b.size() ? b[i] : 0);
            fa[i] = C(x, y);
        }

        fft(fa, sz);
        C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);

        for (int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
            fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
            fa[i] = z;
        }

        for (int i = 0; i < (sz >> 1); i++) {
            C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
            C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
            fa[i] = A0 + A1 * s;
        }

        fft(fa, sz >> 1);
        vector< ull > ret(need);

        for (int i = 0; i < need; i++) ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
        return ret;
    }
};

template<typename T>
struct ArbitraryModConvolution {
    using real = FastFourierTransform::real;
    using C = FastFourierTransform::C;

    ArbitraryModConvolution() = default;

    vector<T> multiply(const vector<T>& a, const vector<T>& b, int need = -1) {
        if (need == -1) need = a.size() + b.size() - 1;
        int nbase = 0;
        while ((1 << nbase) < need) nbase++;
        FastFourierTransform::ensure_base(nbase);
        int sz = 1 << nbase;
        vector<C> fa(sz);
        for (int i = 0; i < a.size(); i++)
            fa[i] = C(a[i].x & ((1 << 19) - 1), a[i].x >> 19);

        fft(fa, sz);
        vector<C> fb(sz);
        if (a == b) fb = fa;
        else {
            for (int i = 0; i < b.size(); i++)
                fb[i] = C(b[i].x & ((1 << 19) - 1), b[i].x >> 19);
            fft(fb, sz);
        }
        real ratio = 0.25 / sz;
        C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
        for (int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            C a1 = (fa[i] + fa[j].conj());
            C a2 = (fa[i] - fa[j].conj()) * r2;
            C b1 = (fb[i] + fb[j].conj()) * r3;
            C b2 = (fb[i] - fb[j].conj()) * r4;

            if (i != j) {
                C c1 = (fa[j] + fa[i].conj());
                C c2 = (fa[j] - fa[i].conj()) * r2;
                C d1 = (fb[j] + fb[i].conj()) * r3;
                C d2 = (fb[j] - fb[i].conj()) * r4;
                fa[i] = c1 * d1 + c2 * d2 * r5;
                fb[i] = c1 * d2 + c2 * d1;
            }
            fa[j] = a1 * b1 + a2 * b2 * r5;
            fb[j] = a1 * b2 + a2 * b1;
        }
        fft(fa, sz);
        fft(fb, sz);
        vector<T> ret(need);
        auto mul1 = T(2).pow(19), mul2 = T(2).pow(38);

        for (int i = 0; i < need; i++) {
            ull aa = llround(fa[i].x);
            ull bb = llround(fb[i].x);
            ull cc = llround(fa[i].y);
            aa = T(aa).x, bb = T(bb).x, cc = T(cc).x;
            ret[i] = (mul1 * bb) + (mul2 * cc) + aa;
        }
        return ret;
    }
};

template<typename T>
struct Combination {
    vector<T> _fact, _rfact, _inv;
 
    Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
        _fact[0] = _rfact[sz] = _inv[0] = 1;
        for (int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
        _rfact[sz] /= _fact[sz];
        for (int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
        for (int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
    }

    inline T fact(int k) const { return _fact[k]; }

    inline T rfact(int k) const { return _rfact[k]; }

    inline T inv(int k) const { return _inv[k]; }

    T P(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact(n) * rfact(n - r);
    }

    T C(int p, int q) const {
        if (q < 0 || p < q) return 0;
        return fact(p) * rfact(q) * rfact(p - q);
    }

    T H(int n, int r) const {
        if (n < 0 || r < 0) return 0;
        return r ? C(n + r - 1, r) : 1;
    }
};

template<typename T>
T factorial(ull n) {
    if (n >= T::get_mod()) return 0;
    if (n == 0) return 1;

    const ull sn = sqrt(n);
    const T sn_inv = T(1) / sn;

    Combination<modint> comb(sn);
    using P = vector<T>;
    ArbitraryModConvolution<modint> fft;

    auto shift = [&] (const P &f, T dx) {
        int n = f.size();
        T a = dx * sn_inv;
        auto p1 = P(f);
        for (int i = 0; i < n; i++) {
            T d = comb.rfact(i) * comb.rfact((n - 1) - i);
            if ((n - 1 - i) & 1) d = -d;
            p1[i] *= d;
        }
        auto p2 = P(2 * n);
        for (int i = 0; i < p2.size(); i++) p2[i] = (a.x + i - n) <= 0 ? 1 : a + i - n;

        for (int i = 1; i < p2.size(); i++) p2[i] *= p2[i - 1];

        T prod = p2[2 * n - 1], prod_inv = T(1) / prod;
        for (int i = 2 * n - 1; i > 0; i--) {
            p2[i] = prod_inv * p2[i - 1];
            prod_inv *= a + i - n;
        }
        p2[0] = prod_inv;
        auto p3 = fft.multiply(p1, p2, (int) p2.size());
        p1 = P(p3.begin() + p1.size(), p3.begin() + p2.size());

        prod = 1;
        for (int i = 0; i < n; i++) prod *= a + n - 1 - i;
        for (int i = n - 1; i >= 0; i--) {
            p1[i] *= prod;
            prod *= p2[n + i] * (a + i - n);
        }
        return p1;
    };
    
    function<P(int)> rec = [&] (ull n) {
        if (n == 1) return P({1, 1 + sn});
        ull nh = n >> 1;
        auto a1 = rec(nh);
        auto a2 = shift(a1, nh);
        auto b1 = shift(a1, sn * nh);
        auto b2 = shift(a1, sn * nh + nh);

        for (int i = 0; i <= nh; i++) a1[i] *= a2[i];
        for (int i = 1; i <= nh; i++) a1.emplace_back(b1[i] * b2[i]);
        
        if (n & 1) {
            for (ull i = 0; i < n; i++) a1[i] *= n + 1LL * sn * i;
            T prod = 1;
            for (ull i = 1LL * n * sn; i < 1LL * n * sn + n; i++) prod *= (i + 1);
            a1.push_back(prod);
        }
        return a1;
    };

    auto vs = rec(sn);
    T ret = 1;
    for (ull i = 0; i < sn; i++) ret *= vs[i];
    for (ull i = 1LL * sn * sn + 1; i <= n; i++) ret *= i;
    return ret;
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> MOD;
    cout << (N < MOD ? factorial<modint>(N) : 0) << "\n";
    return 0;
}