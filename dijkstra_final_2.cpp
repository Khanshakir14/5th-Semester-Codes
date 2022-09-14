#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>

using namespace std;

class Graph{

	int V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}

	void addEdge(int m,bool undir =false){  //m is number of edges, n is number of vertices
   
    for(int i=0; i<m;i++){
        int u,v,wt;
        cout<<"Enter "<<i+1<<"th edge ";
		
        cin>> u >> v>>wt;

        l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	
		
	}
    }

	int dijkstra(int src,int dest){

		//Data Structures
		vector<int> dist(V,INT_MAX);
		set<pair<int,int> >  s;

		//1. Init 
		dist[src] = 0;
		s.insert({0,src});
       cout<<"Intermediate steps:"<<endl;
		while(!s.empty()){
        //pair(wt,node)
			auto it = s.begin();
			int node = it->second;
			int distTillNow = it->first; 
			s.erase(it); //Pop 

			//Iterate over the nbrs of node
			for(auto nbrPair : l[node]){
				//......

				int nbr = nbrPair.second;
				int currentEdge = nbrPair.first;

				if(distTillNow + currentEdge < dist[nbr]){
					//remove if nbr already exist in the set
                        
					auto f = s.find({dist[nbr],nbr});
					if(f!=s.end()){
						s.erase(f);
					}
					//insert the updated value with the new dist
					dist[nbr] = distTillNow + currentEdge;
					s.insert({dist[nbr],nbr});

				
                    cout<<"Reached Node is "<<nbr<<" with current distance from source "<<dist[nbr]<<endl;

				}
                
			}
              

		}
		//Single Source Shortest Dist to all other nodes
		for(int i=0;i<V;i++){
			cout<<"Node i "<<i <<" Dist "<<dist[i] <<endl;
		}
		return dist[dest];

	}

      

};

int main(){
	
   int n,m;//n vertices, m edges
   cout<<"Enter the Number of vertices in the graph"<<endl;
   cin>>n;
   cout<<"Enter the Number of edges in the graph "<<endl;
   cin>>m;
   Graph g(n);

    cout<<"Make sure that graph's numbering is 0 based before entering edges"<<endl;
	g.addEdge(m);

    int src,dest;
    cout<<"Enter Source and destionation "<<endl;
    cin>>src>>dest;
   auto t = g.dijkstra(src,dest);
   cout<<"The distance between source "<<src<<" and destination "<<dest<<" is "<<t<<endl;
  

}