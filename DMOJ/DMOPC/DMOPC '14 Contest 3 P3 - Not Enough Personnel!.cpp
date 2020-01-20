// DEBUG
#include <bits/stdc++.h>

using namespace std;

string str; int a; int low, high;
struct person{
    int grade; string name; int ind;
};

bool cmp(person p, person q){
    if (p.grade == q.grade) return p.ind < q.ind;
    return p.grade < q.grade;
}

int main()
{
    int N; cin >> N;
    person arr[N];
    for (int i = 0; i < N; i++){
        cin >> str >> a;
        arr[i].grade = a; arr[i].name = str; arr[i].ind = i;
    }
    sort(arr, arr + N, cmp);
    /*
    for (int i = 0; i < N; i++){
        cout << arr[i].grade << " " << arr[i].name << "\n";
    }
    */
    int M; cin >> M;
    for (int i = 0; i < M; i++){
        cin >> low >> high;
        high = low + high;
        bool found = false;
        for (int j = 0; j < N; j++){
            if (arr[j].grade >= low && arr[j].grade <= high){
                cout << arr[j].name << "\n";
                found = true;
                break;
            }
        }
        if (!found){
            cout << "No suitable teacher!\n";
        }
    }
    return 0;
}