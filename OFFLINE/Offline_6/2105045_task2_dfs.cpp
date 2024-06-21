#include<bits/stdc++.h>
using namespace std;

class Graph
{
   int v;
   unordered_map<int,int>vertexIndex; 
   list<int>*adj;
   int *parent;
   int *dist;
   bool *visited;
   ofstream outfile;

   public:
   Graph(int v)
   {  
    outfile.open("out.txt");
        if(!outfile.is_open())
        {
            cout<<"file can't be open"<<endl;
        }
        outfile.clear();
    this->v=v;
    adj=new list<int> [v];
    parent=new int [v];
    dist=new int [v];
    visited=new bool [v];
    for(int i=0;i<v;i++)
    {
        parent[i]=-1;
        dist[i]=INT_MAX;
        visited[i]=false;
    }
   }

   void addEdges(int u,int v)
   {
    if(vertexIndex.find(u)==vertexIndex.end())
    {
        vertexIndex[u]=vertexIndex.size();
        adj[vertexIndex[u]] = {};
    }
    if(vertexIndex.find(v)==vertexIndex.end())
    {
        vertexIndex[v]=vertexIndex.size();
        adj[vertexIndex[v]] = {};
    }
    int indexU=vertexIndex[u];
    int indexV=vertexIndex[v];
    adj[indexU].push_back(indexV);
   }

   void DFS(int s)
   {
       int sIndex = vertexIndex[s];
       visited[sIndex]=true;
       dist[sIndex]=0;
       dfs(sIndex);
   } 
   
   void dfs(int n)
   {
    for(int neighbor:adj[n])
    {
        if(!visited[neighbor])
        {
            visited[neighbor]=true;
            dist[neighbor]=dist[n]+1;
            parent[neighbor]=n;
            dfs(neighbor);
        }
    }
   } 
   
   void printPath(int source, int destination)
{
    int dIndex =vertexIndex[destination];

    if (!visited[dIndex])
    {
        outfile<<"-1"<< endl;
        return;
    }

    vector<int> path;
    int curr = dIndex;
    while (curr!= -1)
    {
        for (auto check : vertexIndex)
        {
            if (check.second == curr)
            {
                path.push_back(check.first);
                break;
            }
        }
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    outfile<<dist[dIndex]<<endl;
    for (int i = 0;i < path.size(); i++)
    {
        outfile<<path[i];
        if (i<path.size() - 1)
        {
            outfile<< " ";
        }
    }
    outfile<<endl;
}

};

int main()

{   
    ifstream infile("task1_in.txt");
    if(!infile.is_open())
    {
        cout<<"can't open the file"<<endl;
    }
    int n,m;
    infile>>n>>m;
     Graph g(n);
     for(int i=0;i<m;++i)
     {
        int u,v;
        infile>>u>>v;
        g.addEdges(u,v);
     }
     int source,destination;
     infile>>source>>destination;
     g.DFS(source);
     g.printPath(source,destination);

    return 0;
}
