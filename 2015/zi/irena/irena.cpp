#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n;
vector<string> V;

int dist[2002][2002];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

long long bfs(int px, int py, int kx, int ky){
    queue<int> Q;
    Q.push(px);
    Q.push(py);

    memset(dist, -1, sizeof(dist));
    dist[px][py] = 0;

    while (!Q.empty()){
        int cx = Q.front(); Q.pop();
        int cy = Q.front(); Q.pop();

        for (int d = 0; d < 4; ++d){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (nx < 0 || nx >=n || ny < 0 || ny >= n || V[nx][ny] == '*' || dist[nx][ny] != -1)continue;
            dist[nx][ny] = dist[cx][cy] + 1;
            Q.push(nx);
            Q.push(ny);
        }
    }

    int d = dist[kx][ky];
    long long x = d;

    return x * (x + 1) / 2;
}

int main(void){
    cin >> n;
    for (int i = 0; i < n; ++i){
        string x;
        cin >> x;
        V.push_back(x);
    }

    int px, py;
    int kx, ky;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (V[i][j] == 'I')
                {px = i; py = j;}
            else if (V[i][j] == 'F')
                {kx = i; ky = j;}

    cout << bfs(px, py, kx, ky) << endl;

    return 0;
}
