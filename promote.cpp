#include <fstream>
#include <iostream>
using namespace std;
int before[4];
int after[4];
int diff[4];
int main(){
    ifstream in;
    in.open("promote.in");
    for(int i=0;i<4;i++){
        int a,b;
        in>>a;
        in>>b;
        before[i]=a;
        after[i]=b;
        diff[i]=b-a;
        cout<<a<<" "<<b<<endl;
    }
    in.close();
    int out[3]={0,0,0};
    for(int i=1;i<4;i++){
        for(int j=0;j<i;j++){
            out[j]+=diff[i];
        }
    }
    ofstream outtt;
    outtt.open("promote.out");
    cout<<endl;
    cout<<endl;
    cout<<endl;

    for(int a=0;a<3;a++){
        cout<<out[a]<<endl;
        outtt<<out[a]<<endl;
    }
    outtt.close();

}