#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool CowInRange[200][200];
class cow{
    public:
    int x;
    int y;
    int power;
    vector <int> CowsRange;
    cow(){
        x=-1;
        y=-1;
        power=-1;
    }
    cow(int xs, int ys, int pow){
        x=xs;
        y=ys;
        power=pow;
    }

};
int N;
cow cows[200];
bool inRange(int source,int destination, int p){
    if(sqrt((cows[source].y-cows[destination].y)*(cows[source].y-cows[destination].y)+(cows[source].x-cows[destination].x)*(cows[source].x-cows[destination].x))<=p){
        return true;
    }
    return false;
}

int dfs(int curCow,int index){
    CowInRange[index][curCow]=true;
    int vSize=cows[curCow].CowsRange.size();
    int cnt=1;
    if(vSize==0){
        return cnt;
    }
    for(int j=0;j<vSize;j++){
        cout<<cows[cows[curCow].CowsRange[j]].x<<" "<<cows[cows[curCow].CowsRange[j]].y<<endl;
        if(CowInRange[index][cows[curCow].CowsRange[j]]==false){
            cnt+=dfs(cows[curCow].CowsRange[j],index);
        }
    }
    return cnt;
}
int main(){
    ifstream in;
    in.open("moocast.in");
    in>>N;
    for(int i=0;i<N;i++){
        int xloc,yloc,pwer;
        in>>xloc;
        in>>yloc;
        in>>pwer;
        cows[i].x=xloc;
        cows[i].y=yloc;
        cows[i].power=pwer;
    }
    in.close();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)
                continue;
            if(inRange(i,j,cows[i].power)){
                cows[i].CowsRange.push_back(j);
            }
        }
    }
    int mx=0;
    for(int i=0;i<N;i++){
        cout<<"* "<<cows[i].x<<" "<<cows[i].y<<" *"<<endl;
        int ans= dfs(i,i);
        cout<<endl<<endl;        
        mx=max(mx,ans);
    }
  
    cout<<mx;
    ofstream out;
    out.open("moocast.out");
    out<<mx;
    out.close();
    

}