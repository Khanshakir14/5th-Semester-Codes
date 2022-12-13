#include<bits/stdc++.h>

using namespace std;

class Page_Replacement
{
    int frames;
    int  ref_size;
    vector<int> p;
    vector<int> hi;
    int hit=0;
    int i, j;

    
    public:
      Page_Replacement(int frames, int ref_size, vector<int> p, vector<int> hi){
        this->frames = frames;
        this->ref_size = ref_size;
        this->p = p;
        this->hi = hi;
        

      }

    void FIFO(){
        cout<<"Enter reference string\n";
        for(i =0; i<ref_size; i++){
            cin>>p[i];
        }
     vector<vector<int>> a(frames);
     for(i=0;i<frames;i++){
        a[i]=vector<int>(ref_size,-1);
    }
    map <int, int> mp;    
    for( i=0;i<ref_size;i++){
        vector<pair<int,int>> c;
        for(auto q: mp){
            c.push_back({q.second,q.first});
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for( j=0;j<frames;j++){
            if(a[j][i] == p[i]){
                hit++;
                hi[i]=1;
                mp[p[i]]++;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(int k=i;k<ref_size;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==frames||hasrun==false){
            for(int j=0;j<frames;j++){
                if(a[j][i]==c[c.size()-1].second){
                    mp.erase(a[j][i]);
                    for(int k=i;k<ref_size;k++)
                        a[j][k]=p[i];
                    mp[p[i]]++;
                    break;
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    cout<<"Process ";
    for( i=0;i<ref_size;i++){
        cout<<p[i]<<" ";
    }
    cout<<'\n';
    for( i=0;i<frames;i++){
        cout<<"Frame "<<i<<" ";
        for(int j=0;j<ref_size;j++){
            if(a[i][j]==-1)
                cout<<"E ";
                else 
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(i=0;i<ref_size;i++){
        if(hi[i]==0)
        cout<<"  ";
        else
        cout<<hi[i]<<" ";
    }
    cout<<"\n";
    cout<<"Hit "<<hit<<'\n'<<"Page Fault "<<ref_size-hit<<'\n';
}

void LRU(){
    cout<<"Enter processes\n";
    for(i=0;i<ref_size;i++){
        cin>>p[i];
    }    
    vector<vector<int>> a(frames);
    for(i=0;i<frames;i++){
        a[i]=vector<int>(ref_size,-1);
    }
    map <int, int> mp;    
    for(i=0;i<ref_size;i++){
        vector<pair<int,int>> c;
        for(auto q: mp){
            c.push_back({q.second,q.first});
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0;j<frames;j++){
            if(a[j][i]==p[i]){
                hit++;
                hi[i]=1;
                mp[p[i]]=1;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(int k=i;k<ref_size;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==frames||hasrun==false){
            for(j=0;j<frames;j++){
                if(a[j][i]==c[c.size()-1].second){
                    mp.erase(a[j][i]);
                    for(int k=i;k<ref_size;k++)
                        a[j][k]=p[i];
                    mp[p[i]]++;
                    break;
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    cout<<"Process ";
    for(i=0;i<ref_size;i++){
        cout<<p[i]<<" ";
    }
    cout<<'\n';
    for(i=0;i<frames;i++){
        cout<<"Frame "<<i<<" ";
        for(j=0;j<ref_size;j++){
            if(a[i][j]==-1)
                cout<<"E ";
                else 
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(i=0;i<ref_size;i++){
        if(hi[i]==0)
        cout<<"  ";
        else
        cout<<hi[i]<<" ";
    }
    cout<<"\n";
    cout<<"Hit "<<hit<<'\n'<<"Page Fault "<<ref_size-hit<<'\n';
    
}

void OPT(){
    cout<<"Enter processes\n";
    for(i=0;i<ref_size;i++){
        cin>>p[i];
    }
    vector<vector<int>> a(frames,vector<int>(ref_size,-1));
    map <int, int> mp;    
    for(i=0;i<ref_size;i++){
        vector<int> op;
        vector<pair<int,int>> c;
        for(auto q: mp){
            c.push_back({q.second,q.first});
        }
        for(int q=i+1;q<ref_size;q++){
            for(j=0;j<frames;j++){
                if(a[j][i]==p[q]){
                    op.push_back(p[q]);
                }            
            }
        }
        sort(op.begin(),op.end());
        op.erase(unique(op.begin(),op.end()),op.end());
        bool dontCall=true;        
        if(op.size()==frames){
            dontCall=false;
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0;j<frames;j++){
            if(a[j][i]==p[i]){
                mp[p[i]]++;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(int k=i;k<ref_size;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==frames||hasrun==false){
            for(j=0;j<frames;j++){
                if(dontCall==true){
                    if(a[j][i]==c[c.size()-1].second){
                        mp.erase(a[j][i]);
                        for(int k=i;k<ref_size;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        break;
                    }
                }
                else if(dontCall==false){
                    if(a[j][i]==op[op.size()-1]){
                        mp.erase(a[j][i]);
                        for(int k=i;k<ref_size;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        break;
                    }
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    int hit=0;
    vector<int> hitv(ref_size);
    for(i=1;i<ref_size;i++){
        for(j=0;j<frames;j++){
            if(p[i]==a[j][i-1]){
                hit++;
                hitv[i]=1;
                break;            
            }
        }
    }
    cout<<"Process ";
    for(i=0;i<ref_size;i++){
        cout<<p[i]<<" ";
    }
    cout<<'\n';
    for(i=0;i<frames;i++){
        cout<<"Frame "<<i<<" ";
        for(j=0;j<ref_size;j++){
            if(a[i][j]==-1)
                cout<<"E ";
                else 
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<"HIT     ";
    for(i=0;i<hitv.size();i++){
        if(hitv[i]==0)
            cout<<"  ";
        else
        cout<<hitv[i]<<" ";
    }
    cout<<"\n";
    cout<<"Hit "<<hit<<'\n'<<"Page Fault "<<ref_size-hit<<'\n';
}



   






};

int main(){
    int frames,ref_size,n;
    cout<<"Enter the number of frames"<<endl;
    cin>>frames;
    cout<<"Enter the number reference string  size "<<endl;
    cin>>ref_size;
    vector<int> p(ref_size);
    vector<int> hi(ref_size);

   
   
   Page_Replacement pg(frames, ref_size,p,hi);
   

   int choose;
   cout<<"Enter 1 for fifo , 2 for LRU and 3 for OPT";
   cin>>choose;

   switch(choose){
     case 1:
     pg.FIFO();
     break;
     case 2:
     pg.LRU();
     break;
     case 3:
     pg.OPT();
     break;
     default:
     break;
     
   }  
   

   





    return 0;

}