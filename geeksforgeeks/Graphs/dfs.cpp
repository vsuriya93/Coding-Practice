#include<iostream>
#include<list>

using namespace std;

class graph
{
 private:
 	int V;
	list<int> *adj;
 public:
 	graph(int V)
	{
	 this->V=V;
	 adj = new list<int>[V];
	}
	void addEdge(int src,int dest)
	{
	 adj[src].push_back(dest);
	 adj[dest].push_back(src);
	}

	void DFS_Fun(int node,bool *visited)
	{
	 visited[node]=true;
	 cout<<node<<" ";
	 for(list<int>::iterator i=adj[node].begin();i!=adj[node].end();++i)
	 {
	  if(!visited[*i])
	   DFS_Fun(*i,visited);
	 }
	}
	
	void DFS(int start)
	{
	 bool *visited=new bool[V];
	 for(int i=0;i<V;i++)
	  visited[i]=false;
	DFS_Fun(start,visited);
	}

};

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
}
