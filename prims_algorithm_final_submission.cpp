#include <iostream>
#define I __INT_MAX__

using namespace std;

/*

name:Khan Shah Ahmed Shakir Abu Asim
Faculty no:20COB206
GL9636
B-Tech-3rd Year



*/


/*={
    {I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I},
    {I,25,I,12,I,I,I,10},
    {I,I,12,I,8,I,I,I},
    {I,I,I,8,I,16,I,14},
    {I,I,I,I,16,I,20,18},
    {I,5,I,I,I,20,I,I},
    {I,I,10,I,14,18,I,I}

    
};*/



int main () {
	int nodes;
int cost[100][100];
int near[100];
int t[3][100];

    int i,j,k,u,v, min=I,ans=0;
    int x,y,z;
    cout<<"Enter number of nodes, present in the graph"<<endl;
    cin>>nodes;
    cout<<"Enter edges, and do follow the order edges->cost, enter -1 when done"<<endl;
    for(int i=1; i<=nodes; i++)
	{
		for(int j=1; j<=nodes; j++)
			cost[i][j] = I;
		near[i] = I;
	}
    while(1)
    {
    	cin>>x>>y>>z;
    	if(x==-1||y==-1||z==-1) break;
    	cost[x][y] = z;
    	cost[y][x] = z;
    }
    for(i=1;i<=nodes;i++){
        for(j=i;j<=nodes;j++){
            if(cost[i][j]<min){
                min = cost[i][j];
               
                u=i;
                v=j;

            }
        }
    }
       t[0][0]=u;t[1][0]=v,t[2][0]=cost[u][v];
       near[u]=near[v]=0;

       for(i=1;i<=nodes;i++){
        if(near[i]!=0){
        if(cost[i][u]<cost[i][v])
            near[i]=u;
        
        else
        near[i]=v;
        }

       }

      for(i=1;i<nodes-1;i++){
        min=I;
        for(j=1;j<=nodes;j++){

            if(near[j]!=0 && cost[j][near[j]]<min){
                k=j;
                min = cost[j][near[j]];
                

            }

        }
             t[0][i]=k;
             t[1][i]=near[k];
             t[2][i]=cost[k][near[k]];
             near[k]=0;

             for(j=1;j<=nodes;j++){
                if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
                     near[j]=k;
             }
      }

      

      for(i=0; i<nodes-1;i++){
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<":cost-->"<<t[2][i]<<")"<<endl;

      }
      for(i=0;i<nodes-1;i++){
        ans+=t[2][i];
      }
      cout<<"Minimum cost is "<<ans;
      
}
