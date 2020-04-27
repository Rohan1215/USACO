#include <iostream>
#include <fstream>
using namespace std;
class boot{
    public:
    long long depth;
    int span;
    boot(int d, int s){
        depth=d;
        span=s;
    }
    boot(){
        depth=0;
        span=0;
    }
};
int N,B;
int ans=9999;
long long tiles[250];
boot boots[250];
bool dp[250][250];


void dfs(int shoe, int tile){
    if(dp[shoe][tile]){
        return;
    }
    dp[shoe][tile]=true;
    if(tile==N-1){
        ans=min(ans,shoe);
    }  
    else if(boots[shoe].depth>=tiles[tile]){
        for(int j=1;j<=boots[shoe].span;j++){
            if(tile+j<N)
                dfs(shoe,tile+j);
        }

        for(int i=shoe+1;i<B;i++){
            if(boots[i].depth>=tiles[tile]){
                for(int j=1;j<=boots[i].span;j++){
                    if(tile+j<N)
                        dfs(i,tile+j);
                }
            }
        }
        
    }
}

int main(){
    ifstream in;
    in.open("snowboots.in");
    in>>N;
    in>>B;
    for(int i=0;i<N;i++){
        in>>tiles[i];
    }
    for(int i=0;i<B;i++){
        in>>boots[i].depth;
        in>>boots[i].span;
    }
    in.close();


    dfs(0,0);
    
    
    ofstream out;
    out.open("snowboots.out");
    out<<ans;
    cout<<ans;
    out.close();
}