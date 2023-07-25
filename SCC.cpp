#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int t=0;
const int M=1e5;
int f[M],d[M];
bool vis[M];
vector<vector<int>>adj;
vector<vector<int>>cmps;
vector<vector<int>>trans;


#define pb push_back
#define debug(x) cerr << (#x) << ' ' << x << endl;


void dfs(int i){

    vis[i]=1; 
    t++;
    d[i]=t;
   // debug(i);

    for(auto c: adj[i]){
        if(!vis[c])
        {
            dfs(c);
        }
    }
    
    t++;
    f[i]=t;
}

void dfs_cmp(int p,vector<int> &new_cmp){

     vis[p]=1; 
     new_cmp.pb(p); 
     for(auto c: trans[p]){
        if(!vis[c]){
            dfs_cmp(c,new_cmp);
        }
     }
}

struct AscendingFirstElementComparator {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;
    }
};

int main(){

    int P,T; 
    cin>>P>>T;
    adj.resize(P+1);
    trans.resize(P+1);

    for (size_t i = 0; i < T; i++)
    {   
       int u,v;
       cin>>u>>v; 
       adj[u].pb(v); 
       trans[v].pb(u);
    }

    for(int i=1;i<=P;i++){
        
        if(!vis[i])
          dfs(i);
    }

    priority_queue<pair<int,int>> pr; 



    for (size_t i =1; i <= P; i++)
    {
        pr.push({f[i],i});
    }

    memset(vis,0,sizeof(vis));
    while(!(pr.empty())){

        int x= pr.top().ss;
        pr.pop();
        if(!vis[x]){
            vector<int>new_cmp; 
            dfs_cmp(x,new_cmp);
            cmps.pb(new_cmp);
        }
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, AscendingFirstElementComparator> pq;

    for (size_t i = 0; i < cmps.size(); i++)
    {
        for (size_t j= 0; j < cmps[i].size(); j++)
        {
           pq.push({cmps[i][j],i});

        }
        //cout<<"\n";
        
    }

    cout<<cmps.size()<<"\n";

    while(!(pq.empty())){
        cout<<pq.top().ss+1<<" ";
        pq.pop();
    }
    
    

   
    
    
 

}
