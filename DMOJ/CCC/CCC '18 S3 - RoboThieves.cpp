// DEBUG
#include <bits/stdc++.h>
using namespace std;

char arr[101][101];
int N, M;
int stx, sty;
bool vis[101][101], flag[101][101], flag1[101][101];
int dis[101][101];
vector <pair<int, int> > vec;

void check(int x, int y){
    //cout << x << " " << y << "\n";
    // vis[x][y] = true;
    for (int i = y; i < M; i++){
        //cout << arr[x][i] << " ";
        if (arr[x][i] == 'W'){
            break;
        }
        if (flag[x][i] || arr[x][i] == '.' || arr[x][i] == 'S'){
            // vis[x][i] = true;
            flag1[x][i] = true;
        }
    }
    for (int i = y; i >= 0; i--){
        if (arr[x][i] == 'W'){
            break;
        }
        if (flag[x][i] || arr[x][i] == '.' || arr[x][i] == 'S'){
            // vis[x][i] = true;
            flag1[x][i] = true;
        }
    }
    for (int i = x; i < N; i++){
        if (arr[i][y] == 'W'){
            break;
        }
        if (flag[i][y] || arr[i][y] == '.' || arr[i][y] == 'S'){
            // vis[i][y] = true;
            flag1[i][y] = true;
        }
    }
    for (int i = x; i >= 0; i--){
        if (arr[i][y] == 'W'){
            break;
        }
        if (flag[i][y] || arr[i][y] == '.' || arr[i][y] == 'S'){
            // vis[i][y] = true;
            flag1[i][y] = true;
        }
    }
}

void bfs(int s, int t){
    
    priority_queue <pair<int, int> > que;
    pair<int, int> temp;
    if (!flag1[s][t]) que.push({s, t});
    vis[s][t] = true;
    dis[s][t] = 0;
    while (!que.empty()){
        temp = que.top(); que.pop();
        int x = temp.first, y = temp.second;
        //cout << x << y << "\n";
        vis[x][y] = 0;
        bool fuck = arr[x][y] == 'L' || arr[x][y] == 'R' || arr[x][y] == 'U' || arr[x][y] == 'D';
        if (arr[x][y] == '.' || arr[x][y] == 'S' || fuck){
            if (x+1 < N && arr[x + 1][y] != 'W' && !flag1[x + 1][y]){
                int fuckthis = dis[x][y];
                if (!fuck) {
                    fuckthis+=1;
                }
                if (dis[x + 1][y] > fuckthis) {
                    dis[x + 1][y] = fuckthis;
                    if (!vis[x + 1][y]) {
                        vis[x+1][y] = true;
                        que.push({x+1,y});
                    }
                }
            }
            else if (x-1 >= 0 && arr[x - 1][y] != 'W' && !flag1[x - 1][y]){
                int fuckthis = dis[x][y];
                if (!fuck) {
                    fuckthis+=1;
                }
                if (dis[x - 1][y] > fuckthis) {
                    dis[x - 1][y] = fuckthis;
                    if (!vis[x - 1][y]) {
                        vis[x-1][y] = true;
                        que.push({x-1,y});
                    }
                }
            }
            else if (y+1 < M && arr[x][y+1] != 'W' && !flag1[x][y+1]){
                int fuckthis = dis[x][y];
                if (!fuck) {
                    fuckthis+=1;
                }
                if (dis[x][y+1] > fuckthis) {
                    dis[x][y+1] = fuckthis;
                    if (!vis[x][y+1]) {
                        vis[x][y+1] = true;
                        que.push({x,y+1});
                    }
                }
            }
            else if (y-1 >= 0 && arr[x][y-1] != 'W' && !flag1[x][y-1]){
                int fuckthis = dis[x][y];
                if (!fuck) {
                    fuckthis+=1;
                }
                if (dis[x][y-1] > fuckthis) {
                    dis[x][y-1] = fuckthis;
                    if (!vis[x][y-1]) {
                        vis[x][y-1] = true;
                        que.push({x,y-1});
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'C'){
                flag[i][j] = true;
                vec.push_back({i, j});
            }
            if (arr[i][j] == 'W'){
                flag1[i][j] = true;
            }
            else if (arr[i][j] == 'S'){
                stx = i; sty = j;
            }
        }
    }
    for (int i = 0; i < vec.size(); i++){
        int a = vec[i].first, b = vec[i].second;
        check(a, b);
    }
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    bfs(stx, sty);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (arr[i][j] == '.'){
                if (dis[i][j] == 0x3f3f3f3f) cout << -1 << "\n";
                else cout << dis[i][j] << "\n";
            }

        }
    }
    return 0;
}