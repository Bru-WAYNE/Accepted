#include<bits/stdc++.h>
using namespace std;

bool Cyclic(int S,vector<bool> &visited , vector<bool> &dfsVisited , vector<int> adj[])
{
    visited[S]=true;
    dfsVisited[S]=true;
    for(int u:adj[S])
    {
        if(visited[u]==false)
        {
            if(Cyclic(u,visited,dfsVisited,adj))
                return true;
        }
        else if(visited[u]==true && dfsVisited[u]==true)
        {
            return true;
        }

    }
    dfsVisited[S]= false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> dfsVisited(V,false);
        for(int i=0;i<V;i++)
        { 
            if(Cyclic(i,visited,dfsVisited,adj))
                return true;

        }
        return false;

    }

int main()
{
 return 0;
}