#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cell{
    int x,y, dist;
};
void printMaze(vector<vector<int>>& maze, vector<vector<int>>& pathMark,int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (pathMark[i][j] && !(i == 0 && j == 0) && !(i == n-1 && j == m-1))
                cout << "+ ";
            else if (i == 0 && j == 0)
                cout << "S ";
            else if (i == n-1 && j == m-1)
                cout << "E ";
            else if (maze[i][j] == 1)
                cout << "# ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}
int main(){
    int n,m;
    cout<<"Enter rows and columns ";
    cin>>n>>m;
    vector<vector<int>> maze(n, vector<int>(m));
    cout<<"Enter maze (0=Path,1=Wall): \n";

    for(int i=0 ; i<n; i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m,0));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m));

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    queue<cell> q;
    q.push({0,0,0});
    visited[0][0]=1;
    parent[0][0]={-1,-1};

    int endx=-1,endy=-1;

    while (!q.empty())
    {
        cell cur=q.front();
        q.pop();
        
        if (cur.x==n-1 && cur.y==m-1){
            cout << "Shortest path length: " << cur.dist << endl;
            endx=cur.x;
            endy=cur.y;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=cur.x + dx[i];
            int ny=cur.y + dy[i];
            if (nx>=0 && ny>=0 && nx<n && ny<m){
                if (maze[nx][ny]==0 && !visited[nx][ny]){
                    visited[nx][ny]=1;
                    parent[nx][ny]={cur.x,cur.y};
                    q.push({nx,ny,cur.dist+1});
                }
            }
        }
    }

    vector<vector<int>> pathMark(n,vector<int>(m,0));
    vector<pair<int,int>> path;
     while (endx!=-1 && endy!=-1)
    {
        path.push_back({endx,endy});
        auto p=parent[endx][endy];
        endx=p.first;
        endy=p.second;
    }

    for (auto c : path) {
    pathMark[c.first][c.second] = 1;
}

    cout << "\nMaze with shortest path:\n";
    cout << " Path taken shown with \"+\"\n";
    printMaze(maze, pathMark , n, m);
    return 0;
}