#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
int N,K;
int ceiling(int num){
    int x= num%2==0 ? num/2 : (num/2)+1;
    return x;
}
int main(){
    ifstream in;
    in.open("diamond.in");
    in>>N;
    in>>K;
    cout<<N<<endl;
    int diamonds[10001];
    for(int i=0;i<10000;i++){
        diamonds[i]=0;
    }
    for(int i=0;i<N;i++){
        int t;
        in>>t;
        diamonds[t]+=1;
    }
    in.close();
    //1 1 3 4 6
    cout<<endl;
    queue <int> hpn;
    int curcount=0;
    for(int i=0;i<=K;i++){
        curcount+=diamonds[i];
        hpn.push(diamonds[i]);
  //      cout<<diamonds[i]<<" ";
    }
    cout<<endl;
    int mx=curcount;
    cout<<curcount<<endl;
    for(int i=K+1;i<10000;i++){
        int count=0;
        curcount-=hpn.front();
//        cout<<i<<" "<<hpn.front()<<" ";
        hpn.pop();
        hpn.push(diamonds[i]);
        curcount+=diamonds[i];
//        cout<<diamonds[i]<<" "<<curcount<<" ";
        mx=max(curcount,mx);
//        cout<<"*** "<<hpn.size()<<" ***"<<endl;
    }

    cout<<endl;
    cout<<mx;
    ofstream out;
    out.open("diamond.out");
    out<<mx;
    out.close();

}