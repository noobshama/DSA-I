#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>>moves={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};

bool is_validPositon(int x,int y,int n,int m)
{
    return (0<=x && x<n && 0<=y && y<m);
}

int main()
{   
    ifstream infile("task3_in4.txt");
    ofstream outfile;
    outfile.open("out.txt");
        if(!outfile.is_open())
        {
            cout<<"file can't be open"<<endl;
        }
        outfile.clear();
    if(!infile.is_open())
    {
        cout<<"can't open the file"<<endl;
    }
    int n,m,q;
    infile>>n>>m>>q;
    
    vector<pair<pair<int,int>,int>>kRiders(q);
    for(int i=0;i<q;i++)
    {
        infile>>kRiders[i].first.first>>kRiders[i].first.second>>kRiders[i].second;
    }
    vector<vector<int>>moveCounts(n,vector<int>(m,0));
    for(int i=0;i<q;i++)
    {
        int x=kRiders[i].first.first;
        int y=kRiders[i].first.second;
        int k=kRiders[i].second;
        vector<vector<int>>dist(n,vector<int>(m,-1));
        

        queue<pair<int,int>>bfs_Q;
        bfs_Q.push({x,y});  
        dist[x][y]=0;
        while(!bfs_Q.empty())
        {
            int cx=bfs_Q.front().first;
            int cy=bfs_Q.front().second;
            bfs_Q.pop();
            for (auto move : moves) 
            {
                int nx = cx + move.first;
                int ny = cy + move.second;
                if(is_validPositon(nx,ny,n,m) && dist[nx][ny]==-1)
                {
                    dist[nx][ny]=dist[cx][cy]+1;
                    bfs_Q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int totalMoves=dist[i][j];
                if(totalMoves!=-1)
                {
                    moveCounts[i][j]+=(totalMoves+k-1)/k;
                    
                }
            }
        }
    }
    int minMoves=INT_MAX;
    //int totalRiders=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int val=moveCounts[i][j];
            if(val>=1 && val<minMoves)
            {
                minMoves=val;
            }
        }
    }
    if(minMoves==INT_MAX)
    {
        outfile<<"-1"<<endl;
    }
   else
   {
    outfile<<minMoves<<endl;
   }

}