#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>w
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
template<typename T>constexpr const T&_min(const T&x,const T&y) {return x<y?x:y;}
template<typename T>constexpr const T&_max(const T&x,const T&y) {return x<y?y:x;}
template<typename T,typename...Ts> constexpr const T&_min(const T&x,const Ts&...xs) {return _min(x,_min(xs...));}
template<typename T,typename...Ts> constexpr const T&_max(const T&x,const Ts&...xs) {return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

struct Node {
    int value, priority, psum, ssum, sum, msum, size, same;
    Node *left, *right;
    bool reverse, make_same;

    inline void initialize(int value, int priority) {
        this->value = psum = ssum = sum = msum = value;
        this->priority = priority;
        reverse = make_same = false;
        size = 1;
        left = right = nullptr;
    }
} *root = nullptr;

inline int size(Node *&node) {
    return node ? node->size : 0;
}

inline void handle_lazy(Node *&node) {
    if (node) {
        if (node->make_same) {
            node->value = node->same;
            node->sum = node->same * node->size;
            node->msum = max(node->value, node->sum);
            node->psum = max(node->value, node->sum);
            node->ssum = max(node->value, node->sum);

            if (node->left) {
                node->left->same = node->same;
                node->left->make_same = true;
            }
            if (node->right) {
                node->right->same = node->same;
                node->right->make_same = true;
            }
            node->make_same = false;
        }

        if (node->reverse) {
            std::swap(node->left, node->right);
            std::swap(node->psum, node->ssum);
            node->reverse = !node->reverse;
            if (node->left) node->left->reverse = !node->left->reverse;
            if (node->right) node->right->reverse = !node->right->reverse;
            node->reverse = false;
        }
    }
}

inline Node *update(Node *&node) {
    handle_lazy(node->left);
    handle_lazy(node->right);
    node->size = size(node->left) + 1 + size(node->right);

    if (node->left && node->right) {
        node->psum = max(node->left->psum, node->left->sum + node->value + max(0, node->right->psum));
        node->ssum = max(max(0, node->left->ssum) + node->value + node->right->sum, node->right->ssum);
        node->sum = node->left->sum + node->value + node->right->sum;
        node->msum = max(node->psum, node->ssum, node->sum, max(0, node->left->ssum) + node->value + max(0, node->right->psum),
                         node->left->msum, node->right->msum);
    } else if (node->left) {
        node->psum = max(node->left->psum, node->left->sum + node->value);
        node->ssum = max(node->left->ssum + node->value, node->value);
        node->sum = node->left->sum + node->value;
        node->msum = max(node->psum, node->ssum, node->sum, node->left->msum);
    } else if (node->right) {
        node->psum = max(node->value, node->value + node->right->psum);
        node->ssum = max(node->value + node->right->sum, node->right->ssum);
        node->sum = node->value + node->right->sum;
        node->msum = max(node->psum, node->ssum, node->sum, node->right->msum);
    } else {
        node->psum = node->ssum = node->sum = node->msum = node->value;
    }

    return node;
}

void split(Node *node, int index, Node *&left, Node *&right) {
    handle_lazy(node);

    if (!node)
        left = right = nullptr;
    else if (size(node->left) + 1 < index)
        split(node->right, index - size(node->left) - 1, node->right, right), left = update(node);
    else
        split(node->left, index, left, node->left), right = update(node);
}

Node *merge(Node *left, Node *right) {
    handle_lazy(left);
    handle_lazy(right);

    if (!left || !right) {
        return left ? left : right;
    } else if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return update(left);
    } else {
        right->left = merge(left, right->left);
        return update(right);
    }
}

Node *insert(Node *&node, Node *ins) {
    if (!node) return ins;
    handle_lazy(node);

    if (ins->priority > node->priority) {
        ins->left = node;
        return update(ins);
    } else {
        node->right = insert(node->right, ins);
    }

    return update(node);
}

int N, M, posi, tot, c, ri;
char buffer[15];
Node *reserved[500000];

inline void reserve(Node *node) {
    reserved[ri++] = node;
}

inline Node *init_node(int key) {
    if (!ri) reserve(new Node());
    Node *ret = reserved[--ri];
    if (ret->left) reserved[ri++] = ret->left;
    if (ret->right) reserved[ri++] = ret->right;
    ret->initialize(key, rand());
    return ret;
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("DATA.in", "r", stdin);
    freopen("DATA.out", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i=0, val; i<N; i++) {
        cin >> val;
        root = insert(root, init_node(val));
    }
    while (M--) {
        cin >> buffer;
        switch (buffer[0]) {
            case 'I': {
                cin >> posi >> tot;
                Node *insertion_point = nullptr, *left, *right;
                while (tot--) {
                    cin >> c;
                    insertion_point = insert(insertion_point, init_node(c));
                }
                split(root, posi + 1, left, right);
                root = merge(merge(left, insertion_point), right);
                break;
            }
            case 'D': {
                cin >> posi >> tot;
                Node *left, *middle, *right;
                split(root, posi, left, middle);
                split(middle, tot + 1, middle, right);
                reserve(middle);
                root = merge(left, right);
                break;
            }
            case 'M': {
                if (buffer[4] == '-') {
                    cin >> posi >> tot >> c;
                    Node *left, *middle, *right;
                    split(root, posi, left, middle);
                    split(middle, tot + 1, middle, right);
                    middle->same = c;
                    middle->make_same = true;
                    handle_lazy(middle);
                    root = merge(merge(left, middle), right);
                }
                else {
                    cout << root->msum << "\n";
                }
                break;
            }
            case 'R': {
                cin >> posi >> tot;
                Node *left, *middle, *right;
                split(root, posi, left, middle);
                split(middle, tot + 1, middle, right);
                middle->reverse = !middle->reverse;
                handle_lazy(middle);
                root = merge(merge(left, middle), right);
                break;
            }
            default: {
                cin >> posi >> tot;
                Node *left, *middle, *right;
                split(root, posi, left, middle);
                split(middle, tot + 1, middle, right);
                cout << (middle ? middle->sum : 0) << "\n";
                root = merge(merge(left, middle), right);
                break;
            }
        }
    }
    return 0;
}

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */