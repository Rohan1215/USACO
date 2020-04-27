#include <iostream>
#include <fstream>
#include <map>
using namespace std;
long long L,N;
long long total;
int rf,rb;
int computeSegment(long long start, long long dest, int yum){
    long long dist=dest-start;
    return yum*((rf*dist) - (rb*dist));

}
int main(){
    ifstream in;
    in.open("reststops.in");
    in>>L;
    in>>N;
    in>>rf;
    in>>rb;
    long long stops[N+1][2];
    long long maxes[N+1];
    stops[0][0]=0;
    stops[0][1]=0;
    maxes[0]=0;
    for(int i=1;i<N+1;i++){
        in>>stops[i][0];
        in>>stops[i][1];
        //cout<<stops[i][0]<<" "<<stops[i][1]<<endl;
        maxes[i]=0;
    }
    in.close();
    long long mx=0;
    for(int i=N;i>=1;i--){
        mx=max(mx,stops[i][1]);
        cout<<mx<<endl;
        maxes[i-1]=mx;
    }
    long long setmax=maxes[0];
    long long c=0;
    long long o=0;
    while(c<N+1){
        if(stops[c][1]==setmax){
            total+=(stops[c][1]*(stops[c][0]-stops[o][0])*(rf-rb));
            //cout<<total<<endl;
            o=c;
            setmax=maxes[c];
        }
        c++;
    }
    //-------output----------
    ofstream out;
    out.open("reststops.out");
    out<<total;
    cout<<endl<<total<<endl;
    return 0;
}