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

int N, M, a, x, ans;
char c;

struct node {
    int val,p,sz;
    node *ch[2];
    node(int i):val(i),p(rand()),sz(1){ch[0]=ch[1]=0;}
}*root;

inline int sz (node *n) {
    return n?n->sz:0;
}

inline void upd_sz (node *n) {
    if(n) n->sz=sz(n->ch[0])+1+sz(n->ch[1]);
}

void Rotate (node *&n,bool b) {
    node *tmp=n->ch[b];
    n->ch[b]=tmp->ch[!b];
    tmp->ch[!b]=n;
    upd_sz(n);
    upd_sz(tmp);
    n=tmp;
}

void Insert (node *&n, node *i) {
    if(!n)
        n=i;
    else {
        bool b=n->val<i->val;
        Insert(n->ch[b],i);
        if(n->ch[b]->p>n->p)
            Rotate(n,b);
    }
    upd_sz(n);
}

void Delete (node *&n, int i) {
    if(!n) return;
    if(n->val==i) {
        if(!n->ch[0]||!n->ch[1]) {
            n=n->ch[0]?n->ch[0]:n->ch[1];
        } else {
            bool b=n->ch[1]->p>n->ch[0]->p;
            Rotate(n,b);
            Delete(n->ch[!b],i);
        }
    } else
        Delete(n->ch[n->val<i],i);
    upd_sz(n);
}

int Select (node *n,int i) {
    if(sz(n->ch[0])+1==i) return n->val;
    else if(sz(n->ch[0])+1<i) return Select(n->ch[1],i-sz(n->ch[0])-1);
    else return Select (n->ch[0],i);
}

int Rank (node *n,int i,int s=0) {
    if(!n) return -1;
    if(n->val==i) {
        int tmp=Rank(n->ch[0],i,s);
        return ~tmp?tmp:s+sz(n->ch[0])+1;
    } else if(n->val<i) return Rank(n->ch[1],i,s+1+sz(n->ch[0]));
    else return Rank(n->ch[0],i,s);
}

void Display (node *n) {
    if(!n) return;
    Display(n->ch[0]);
    printf("%d ",n->val);
    Display(n->ch[1]);
}

int main () {
    scanf("%d %d", &N, &M);
    for (int i=0,a; i<N; i++) {
        scanf("%d", &a);
        Insert(root, new node(a));
    }
    for (int i=0,x;i<M;++i) {
        scanf(" %c %d", &c, &x);
        x ^= ans;
        switch (c) {
            case 'I':
                Insert(root, new node(x));
                break;
            case 'R':
                Delete(root,x);
                break;
            case 'S':
                printf("%d\n", ans=Select(root,x));
                break;
            case 'L':
                printf("%d\n", ans=Rank(root,x));
                break;
        }
    }
    Display(root);
    return 0;
}