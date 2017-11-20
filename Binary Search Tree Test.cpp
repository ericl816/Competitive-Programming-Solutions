#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

template <class Value>
struct SplayTree {
    struct Node {
        Value val;
        // L and R subtrees
        Node *left = NULL, *right = NULL; 
        int size;
        Node (Value val, int size) {
            this->val = val;
            this->size = size;
        }
    };

private:
    Node *root = NULL;
    int Size (Node *&x) {
        if (x == NULL) return 0;
        return x->size;
    }
    
    void Update (Node *&x) {
        if (x == NULL) return;
        x->size = Size(x->left) + Size(x->right) + 1;
    }

    Node *RotateRight (Node *&x) {
        Node *y = x->left;
        x->left = y->right;
        y->right = x;
        Update(x);
        Update(y);
        return y;
    }

    Node *RotateLeft (Node *&x) {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        Update(x);
        Update(y);
        return y;
    }

    Node *Select (Node *&x, int k) {
        if (x == NULL) return NULL;
        int t = Size(x->left);
        if (t > k) return Select(x->left, k);
        else if (t < k) return Select(x->right, k - t - 1);
        return x;
    }

    int Rank (Node *&x, Value val) {
        if (x == NULL) return 0;
        if (val <= x->val) return Rank(x->left, val);
        else return Size(x->left) + Rank(x->right, val) + 1;
    }

    void Traverse (Node *&x, vector<Value> &v) {
        if (x == NULL) return;
        Traverse(x->left, v);
        v.push_back(x->val);
        Traverse(x->right, v);
    }

     Node *Splay (Node *&x, Value val) {
         if (x == NULL) return NULL;
         if (val < x->val) {
             if (x->left == NULL) return x;
             if (val < x->left->val) {
                 x->left->left = Splay(x->left->left, val);
                 x = RotateRight(x);
             } 
             else if (val > x->left->val) {
                 x->left->right = Splay(x->left->right, val);
                 if (x->left->right != NULL) x->left = RotateLeft(x->left);
             }
             if (x->left == NULL) return x;
             else return RotateRight(x);
         } 
         else if (val > x->val) {
             if (x->right == NULL) return x;
             if (val < x->right->val) {
                 x->right->left = Splay(x->right->left, val);
                 if (x->right->left != NULL) x->right = RotateRight(x->right);
             } 
             else if (val > x->right->val) {
                 x->right->right = Splay(x->right->right, val);
                 x = RotateLeft(x);
             }
             if (x->right == NULL) return x;
             else return RotateLeft(x);
         } 
         else return x;
     }

public:
    SplayTree () {}

    int Size () {
        return Size(root);
    }

    bool Contains (Value val) {
        if (root == NULL) return 0;
        root = Splay(root, val);
        return val == root->val;
    }
    
    Value Select (int k) {
        return Select(root, k)->val;
    }

    int Rank (Value val) {
        root = Splay(root, val);
        return Rank(root, val);
    }
    
    void Add (Value val) {
        if (root == NULL) {
            root = new Node(val, 1);
            return;
        }
        root = Splay(root, val);
        if (val < root->val) {
            Node *n = new Node(val, 1);
            n->left = root->left;
            n->right = root;
            root->left = NULL;
            Update(root);
            root = n;
        }
        else {
            Node *n = new Node(val, 1);
            n->right = root->right;
            n->left = root;
            root->right = NULL;
            Update(root);
            root = n;
        }
        Update(root);
    }

    void Del (Value val) {
        if (root == NULL) return;
        root = Splay(root, val);
        if (val == root->val) {
            if (root->left == NULL) root = root->right;
            else {
                Node *x = root->right;
                root = Splay(root->left, val);
                root->right = x;
            }
            Update(root);
        }
    }

    vector<Value> GetValues () {
        vector<Value> v;
        Traverse(root, v);
        return v;
    }
    
    void Display () {
      for (int next : GetValues()) printf("%d ", next);
    }
};

SplayTree<int> st;
int N, M, lastAns, x, v, arr[MAXN];
char C;

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
      scanf("%d", &arr[i]);
      st.Add(arr[i]);
    }
    for (int i=0; i<M; i++) {
        scanf( "%c %d", &C, &x);
        x ^= lastAns;
        if (C == 'I') st.Add(x);
        else if (C == 'R') st.Del(x);
        else if (C == 'S') {
            lastAns = st.Select(x - 1);
            printf("%d\n", lastAns);
        } 
        else if (C == 'L') {
            if (st.Contains(x)) lastAns = st.Rank(x) + 1;
            else lastAns = -1;
            printf("%d\n", lastAns);
        }
        else i--;
    }
    st.Display();
    return 0;
}