#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N,M;
struct interval{
    int beg;
    int end;
    int size;
};
bool sortSegments(interval l, interval r){
    return l.beg<r.beg;
}
interval segments[100000];
int works(int indicesDiff){
    long long mnDist=10000000000000000;
    long long prevNum=segments[0].beg;
    long long curSum=0;
    int segIndex=0;
    for(int i=1;i<N;i++){
        int a=i*indicesDiff;
        while(curSum<a){
            curSum+=segments[segIndex].size;
            segIndex++;
            if(segIndex>M){
                return -1;  
        curSum-=segments[segIndex].size;
        segIndex--;
        long long diff= a-curSum;
        mnDist=min(mnDist, segments[segIndex].beg+diff-prevNum);
        prevNum=segments[segIndex].beg+diff;
    }
    return mnDist;
}
int main(){
    ifstream in ("socdist.in");
    in>>N>>M;
    long long total=0;
    for(int i=0;i<M;i++){
        long long x,y,s;
        in>>x>>y;
        s=y-x+1;
        segments[i].beg=x;
        segments[i].end=y;
        segments[i].size=s;
        total+=s;
    }
    sort(segments,segments+M,sortSegments);
    long long beg=1;
    long long end=total;
    long long mx=-50;
    while(end-beg>1){
        long long mid=(end+beg)/2;
        bool lower=false;
        if(mid*(N-1)<=total){
            long long aMin=works(mid);
            cout<<aMin<<endl;
            if(aMin<0){
                lower=true;
            }
            else{
                mx=max(mx,aMin);
            }
        }
        else{
            lower=true;
        }
        if(lower){
            end=mid;
        }
        else{
            beg=mid;
        }
    }
    cout<<mx;

}