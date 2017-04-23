#include<iostream>
#include<list>
#include<queue>

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
	 adj=new list<int>[V];
	}
	void addEdge(int src,int dest)
	{
	 adj[src].push_back(dest);
	}
	void print()
	{
	 for(int i=0;i<this->V;i++)
	 {
	  cout<<endl<<i<<": ";
	  for(list<int>::iterator j=adj[i].begin();j!=adj[i].end();++j)
	  	cout<<*j<<"=>";
	 }
	}
	void BFS(int src)
	{
	 queue<int> q;
	 q.push(src);
	 bool *finished = new bool[V];
	 for(int i=0;i<V;i++)
	  finished[i]=false;
	 while(!q.empty())
	 {
	  int element=q.front();
	  cout<<element<<" ";
	  q.pop();
	  finished[element]=true;
	   for(list<int>::iterator i=adj[element].begin();i!=adj[element].end();++i)
	   {
            if(!finished[*i])
	      q.push(*i);
	  }
	 
	}
	cout<<endl;
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
 g.BFS(2);
}
