#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>>& graph,vector<bool> &visited,vector<bool> &dfsVisited,
                int s,vector<bool> &cycle_present)
        {
            visited[s]=true;
            dfsVisited[s]=true;
            for(auto data:graph[s])
            { 
                if(visited[data]==false)
                {
                if(isCycle(graph,visited,dfsVisited,data,cycle_present))
                    {
                        cycle_present[i]=true;
                        return true;
                    }
                }
                else if(visited[i]==true && dfsVisited[i]==true)
                        cycle_present[i]=true;
            }
            dfsVisited[s]=false;
            cycle_present[s]=false;
            return false;
        }

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool> visited(V,false);
        vector<bool> dfsVisited(V,false);
        vector<bool> cycle_present(V,false);
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
                isCycle(graph,visited,dfsVisited,i,cycle_present);
                // return true;
        }   
        for(int i=0;i<V;i++)
        {
            if(cycle_present[i]==false)
                ans.push_back(i);
        }
        return ans;
        
    }
int main()
{
 return 0;
}