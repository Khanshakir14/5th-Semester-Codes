#include <iostream>
using namespace std;

class BankersAlgo{
    int**need, **allocate, **max, *avail;
    int np, nr;

    public:

    BankersAlgo(int np, int nr){
        this->np = np;
        this->nr =nr;
        need = new int *[np];
        for(int i=0; i<np; i++)
            need[i] = new int[np];
        max = new int*[np];
        for(int i=0; i<np; i++)
            max[i] = new int[np];
        allocate = new int*[np];
        for(int i=0; i<np; i++)
            allocate[i] = new int[np];
        avail = new int[nr];
        
        
    }

    void inputData(){
        cout<<"\nEnter the matrices :";
        cout<<"\nAllocated resources ( "<<np<<" x "<<nr<<" )\n";
         for(int i=0; i<np; i++)
           for(int j=0; j<nr; j++)
             cin>>allocate[i][j];

             cout<<"\nMaximum need of processes ( "<<np<<" x "<<nr<<" )\n";
             for(int i=0; i<np;i++)
               for(int j=0; j<nr; j++)
                 cin>>max[i][j];

                 cout<<"Enter total available resources : ";
                   for(int j=0; j<nr; j++)
                      cin>>avail[j];



    }

    int ** calc_need(){
        for(int i=0; i<np; i++)
           for(int j=0; j<nr; j++)
            need[i][j]= max[i][j]-allocate[i][j];


            return need;
    }

    bool check(int i){
        for(int j=0; j<nr; j++)
        if(avail[j]<need[i][j])
            return false;

            return true;
    }

    void isSafe(){

        calc_need();
        bool *done = new bool[np];
        for(int i=0; i<np; i++)
           done[i]=false;

           int j=0;

           cout<<"\nSafe sequence : ";
           while(j<np){
            bool allocated = false;
            for(int i=0; i<np; i++){
                if(!done[i] && check(i)){
                    for(int k=0; k<nr; k++)
                    avail[k]=avail[k]-need[i][k]+max[i][k];

                    cout<<i+1<<" ";
                    allocated = true;
                    done[i]=true;
                    j++;
                }
            }

        if(!allocated) break;

           }

           if(j==np)
             cout<<"\nSafely Allocated!";
            else
             cout<<"\nAll processes can be allocated safely !";

    }

};



    int main(){
        int processes, resources;
        cout<<"Enter number of processes and resources : ";
        cin>>processes;
        cin>>resources;

        BankersAlgo B(processes, resources);
        B.inputData();
        B.isSafe();

        return 0;
    }
