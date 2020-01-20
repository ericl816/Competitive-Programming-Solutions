// DEBUG
#include <bits/stdc++.h>

using namespace std;

struct box{
    int a; int b; int c; uint64_t v;
};

struct item{
    int a; int b; int c;
};

bool cmpb(box x, box y){
    if (x.v != y.v) return x.v < y.v;
    else {
        if (x.a != y.a) return x.a < y.a;
        if (x.b != y.b) return x.b < y.b;
        if (x.c != y.c) return x.c < y.c;
    }
}

int main()
{
    int N; cin >> N;
    box bx[N];
    for (int i = 0; i < N; i++){
        int arr[3];
        for (int i = 0; i < 3; i++){
            cin >> arr[i];
        }
        sort(arr, arr + 3);
        bx[i].a = arr[0];
        bx[i].b = arr[1];
        bx[i].c = arr[2];
        bx[i].v = (uint64_t)arr[0] * arr[1] * arr[2];
        //cout << bx[i].len <<" "<< bx[i].wid <<" "<< bx[i].hei << "\n";
    }
    sort(bx, bx + N, cmpb);
    int M; cin >> M;
    item it[M];
    for (int i = 0; i < M; i++){
        int arr[3];
        for (int i = 0; i < 3; i++){
            cin >> arr[i];
        }
        sort(arr, arr + 3);
        it[i].a = arr[0];
        it[i].b = arr[1];
        it[i].c = arr[2];
    }
    //cout << "\n";
    //for (int i = 0; i < N; i++){
        //cout << bx[i].len <<" "<< bx[i].wid <<" "<< bx[i].hei << "\n";
    //}
    //cout << M << " " << N << "\n";
    for (int i = 0; i < M; i++){
        bool found = false;
        for (int j = 0; j < N; j++){
            if (bx[j].a >= it[i].a && bx[j].b >= it[i].b && bx[j].c >= it[i].c){
                uint64_t minvol = 8000000001;
                for (int k = j; k < N; k++){
                    minvol = min(minvol, bx[k].v);
                }
                cout << minvol << "\n";
                found = true;
                break;
            }
        }
        if (!found){
            cout << "Item does not fit.\n";
        }
    }
    return 0;
}