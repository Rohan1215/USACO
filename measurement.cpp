#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
struct measurement{
    public:
    int time;
    int id;
    int change;
};
bool srt(measurement l, measurement r){
    return l.time<r.time;
}
int main(){
    ifstream in;
    in.open("measurement.in");
    int N;
    int G;
    in>>N;
    in>>G;
    map<int,int> mCount;
    measurement m[N];
    for(int i=0;i<N;i++){
        in>>m[i].time;
        in>>m[i].id;
        in>>m[i].change;
        mCount[m[i].id]=G;
    }
    sort(m,m+N,srt);
    for(int i=0;i<N;i++){
        cout<<m[i].time<<" "<<m[i].id<<" "<<m[i].change<<endl;
    }
    int newTop=0;
    int top=0;
    int topId=0;
    int lastTime=0;
    for(int i=0;i<N;i++){
        mCount[m[i].id]+=m[i].change;
        if((mCount[m[i].id]>=top)&&(m[i].id!=topId)){
            if(lastTime!=m[i].time){
                newTop++;
                cout<<m[i].id<<" "<<top<<endl;
            }
            topId=m[i].id;
            top=mCount[m[i].id];
        }
        lastTime=m[i].time;
    }
    cout<<endl<<newTop;
}