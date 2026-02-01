#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cell{
    int x,y, dist;
};
void printMaze(int maze[5][5], int pathMark[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (i == 0 && j == 0)
                cout << "S ";
            else if (i == 4 && j == 4)
                cout << "E ";
            else if (maze[i][j] == 1)
                cout << "# ";
            else if (pathMark[i][j])
                cout << "* ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}
int main(){
    int maze[5][5] = {
        {0,0,1,0,0},
        {0,0,1,0,1},
        {1,0,0,0,0},
        {0,1,1,1,0},
        {0,0,0,0,0}
    };
    int visited[5][5]={0};
    pair<int,int> parent[5][5];

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
        
        if (cur.x==4 && cur.y==4){
            cout << "Shortest path length: " << cur.dist << endl;
            endx=cur.x;
            endy=cur.y;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=cur.x + dx[i];
            int ny=cur.y + dy[i];
            if (nx>=0 && ny>=0 && nx<5 && ny<5){
                if (maze[nx][ny]==0 && !visited[nx][ny]){
                    visited[nx][ny]=1;
                    parent[nx][ny]={cur.x,cur.y};
                    q.push({nx,ny,cur.dist+1});
                }
            }
        }
    }
    cout<< "Path: ";
    vector<pair<int,int>> path;
    
    int pathMark[5][5]={0};

    for (auto cell:path){
        pathMark[cell.first][cell.second] = 1;
    }
    
    while (endx!=-1 && endy!=-1)
    {
        path.push_back({endx,endy});
        auto p=parent[endx][endy];
        endx=p.first;
        endy=p.second;
    }

    cout << "\nMaze with shortest path:\n";
    printMaze(maze, pathMark);
    return 0;
}