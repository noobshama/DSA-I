#include<bits/stdc++.h>
using namespace std;
//template<typename bfs>
class Graph
{
  private:
  int v;
  unordered_map<int,int>vertexIndex;
  vector<vector<int>> adj;
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
    adj.resize(v);
    parent=new int[v];
    dist=new int [v];
    visited=new bool[v];
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
        adj.push_back({});
    }
    if(vertexIndex.find(v)==vertexIndex.end())
    {
        vertexIndex[v]=vertexIndex.size();
        adj.push_back({});
    }
    int indexU=vertexIndex[u];
    int indexV=vertexIndex[v];
    adj[indexU].push_back(indexV);
  }

  void BFS(int s)
  {
    int sIndex=vertexIndex[s];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    queue<int>q;
    q.push(sIndex);
    dist[sIndex]=0;
    visited[sIndex]=true;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        
        for(auto v : adj[u])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
                dist[v]=dist[u]+1;
                parent[v]=u;    
            }
        }
    }
  }

~Graph()
{
    delete [] parent;
    delete [] visited;
    delete [] dist;
}
void printPath(int source, int destination)
{
    int dIndex = vertexIndex[destination];

    if (!visited[dIndex])
    {
        outfile<<"-1" << endl;
        return;
    }

    vector<int> path;
    int curr = dIndex;
    while (curr != -1)
    {
        path.push_back(curr);
        if (curr == vertexIndex[source])
        {
            break;
        }
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());

    outfile<< dist[dIndex] << endl;
    for (int i = 0; i < path.size(); i++)
    {
        outfile<< path[i];
        if (i < path.size() - 1)
        {
            outfile<< " ";
        }
    }
    outfile<< endl;
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
    for(int i=0;i<m;i++)
    {
        int u,v;
        infile>>u>>v;
        g.addEdges(u,v);
    }
    int source,destination;
    infile>>source>>destination;
    g.BFS(source);
    g.printPath(source,destination);
}