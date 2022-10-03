/*
Name:Khan Shah Ahmed Shakir Abu Asim 
faculty no: 20COB206
Enrollment no: GL9636
A3CO


*/

#include <iostream>
#include <math.h>
using namespace std;

class Graph
{
	int** adj;
	int n;

public:
	Graph(int x)
	{
		n = x;
		adj = new int*[n];
		for(int i=0; i<n; i++)
			adj[i] = new int[n]{0};
	}

	void addEdge(int x,int y, int w)
	{
		adj[x][y] = w;
		//adj[y][x] = w;
	}

	bool bfs(int source, int sink, int* parent)
	{
		bool visited[n];
		int queue[n], front = -1, rear = -1;
		queue[++rear] = source;
		front++;

		visited[source] = true;
		parent[source] = -1;

		int u;
		while (front <= rear) 
		{
			u = queue[front++];

			for (int v = 0; v < n; v++) 
			{
				if ((!visited[v]) && adj[u][v] > 0) 
				{
					if(v == sink)
					{
						parent[v] = u;
						return true;
					}
					queue[++rear] = v;
					parent[v] = u;
					visited[v] = true;
				}
			}
		}
		return false;
	}

	int FF(int source, int sink)
	{
		int parent[n];
		int maxFlow = 0;

		while(bfs(source, sink, parent))
		{
			int minFlow = INT_MAX;

			cout<<"\nAdjacency Matrix : "<<endl;
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
					cout<<adj[i][j]<<"\t";
				cout<<endl;
			}

			int c = sink, p;
			while(c!=source)
			{
				p = parent[c];
				minFlow = min(minFlow, adj[p][c]);
				c = p;
			}

			c = sink;
			while(c!=source)
			{
				p = parent[c];
				adj[p][c] -= minFlow;
				//adj[c][p] += minFlow;
				c = p;
			}

			cout<<"Minimum Flow = "<<minFlow<<endl;
			maxFlow += minFlow;
		}
		return maxFlow;
	}
};

int main()
{
	int u, v, w, n, e;
	cout<<"\nEnter the number of nodes : ";
	cin>>n;
	Graph G(n);
	cout<<"\nEnter the number of edges : ";
	cin>>e;
	cout<<"\nEnter source, dest, weight of edges :"<<endl;
	for(int i=1; i<=e; i++)
	{
		cout<<"Edge "<<i<<" \t ";
		cin>>u>>v>>w;
		G.addEdge(u,v,w);
	}
	int source, sink;
	cout<<"\nSource? "; cin>>source;
	cout<<"Sink? "; cin>>sink;
	int ans = G.FF(source, sink);
	cout << "\nMAXIMUM FLOW = "<< ans ;
}
