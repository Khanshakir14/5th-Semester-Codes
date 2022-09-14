import java.util.*;

class Graph{

	int V;
	List<Integer> l[];

	Graph(int v)
	{
		V=v;
		l = new ArrayList[V];	
		for(int i=0; i<V; i++)
		{
			l[i] = new ArrayList<>();	
		}
	}

	void addEdge(int m,Boolean undir){
		Scanner t = new Scanner(System.in);
        for(int i = 0; i<m;i++){
			int u,v;
			System.out.print("Enter "+(i+1)+"th edge: ");
            u = t.nextInt();
			v= t.nextInt();
		

		l[u].add(v);
		if(undir){
			l[v].add(u);
		}
	}
	}
	void bfs(int source){

		Queue<Integer> q = new LinkedList<>();
		Boolean visited[] = new Boolean[V];

		for(int i=0; i<V; i++)
			visited[i] = false;

		q.add(source);
		visited[source] = true;

		while(!q.isEmpty()){
			//Do some work for every node
			int f = q.peek();
			System.out.println("Contents of Queue are:"+q);
			System.out.println("\nNode Reached:"+f);
			q.remove();
			System.out.print("Neighbours of "+f+" are "+l[f]+":");

			//PUsh the nbrs of current node inside q if they are not already visited
			for(int i = 0; i<l[f].size(); i++) {
				int x = l[f].get(i);
				
				if(!visited[x]){
					q.add(x);
					
					visited[x] = true;
				}
				
			}
		}
	}


	void dfsHelper(int node,Boolean visited[]){
		visited[node] = true;
		System.out.print("\nNode Reached->"+node);
      //  System.out.print("Neighbours of "+node+ " are " +l[node]+": ");
		//make a dfs call on all its unvisited neighbours
		for(int i = 0; i<l[node].size(); i++) {
			int x = l[node].get(i);
			
			if(!visited[x]){
				
				dfsHelper(x,visited);
			}
		}
		return;

	}


	void dfs(int source){
		Boolean visited[] = new Boolean[V];

		for(int i=0; i<V; i++)
			visited[i] = false;

		dfsHelper(source,visited);
	}
}

class DFS_BFS_1 {
	public static void main(String args[]){

		System.out.println("Enter the number of vertices in the graph ");
		Scanner sc = new Scanner(System.in);
		int v = sc.nextInt();
		System.out.println("Enter the number of edges in the graph");
		int m = sc.nextInt();

	     Graph g = new Graph(v);
		 Boolean undirected  = true;
		 g.addEdge(m,undirected);

		
		/*g.addEdge(0,1,true);
		g.addEdge(1,2,true);
		g.addEdge(2,3,true);
		g.addEdge(3,5,true);
		g.addEdge(5,6,true);
		g.addEdge(4,5,true);
		g.addEdge(0,4,true);
		g.addEdge(3,4,true);*/
		//System.out.print("1. BFS\n2. DFS\nEnter -1 to exit\nChoice?");
		int ch=1;

		while (true) {
			System.out.print("\n1. BFS\n2. DFS\nEnter -1 to exit\nChoice?\n");
		
			ch = sc.nextInt();

			if(ch==1){g.bfs(1);}
			if(ch==2){g.dfs(1);}

			if(ch==-1){
				break;
			}


			
		}
		
	}
}
