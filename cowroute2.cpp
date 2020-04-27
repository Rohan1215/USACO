#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int A,B,N;
class stop{
    public:
    int key;
    vector <stop*> nextStops;
    bool firstroute=false;
    stop(){
        key=0;
    }
    stop(int k){
        key=k;
    }
};
int main(){
    ifstream in;
    in.open("cowroute.in");
    in>>A;
    in>>B;
    in>>N;
    int mx=1001;
    stop allStops[10000];
    int routeCost[N];
    for(int i=0;i<N;i++){
        int cost;
        in>>cost;
        routeCost[i]=cost;
        int tripLength;
        in>>tripLength;
        stop* prevStop;
        for(int j=0;j<tripLength;j++){
            int city;
            in>>city;
            if(allStops[city].key==-1){
                allStops[city].key=city;
            }
            if(j>0){
                allStops[city].nextStops.push_back(prevStop);
            }
            prevStop=&allStops[city];     
        }
        cout<<endl;
    }
}