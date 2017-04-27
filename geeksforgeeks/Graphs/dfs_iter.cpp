#include<iostream>
#include<stack>
#include<list>

using namespace std;

class graph
{
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

};
