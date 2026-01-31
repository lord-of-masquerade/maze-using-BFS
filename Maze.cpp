#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cell{
    int x,y, dist;
};
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
    
    while (endx!=-1 && endy!=-1)
    {
        path.push_back({endx,endy});
        auto p=parent[endx][endy];
        endx=p.first;
        endy=p.second;
    }

    for(int i=path.size()-1;i>=0;i--){
         cout << "(" << path[i].first << "," << path[i].second << ") ";
    }
    return 0;
}
