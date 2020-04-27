#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int X,Y,M;
int mx=0;
void output(int x){
    ofstream out;
    cout<<x;
    out.open("pails.out");
    out<<x;
    out.close();
    exit(0);
}
void divideandconquermybutt(int yeetthis){
    if(yeetthis+X>M){
        mx=max(mx,yeetthis);
        if(mx==M)
            output(mx);
    }
    else{
        divideandconquermybutt(yeetthis+X);
    }
    if(yeetthis+Y>M){
        mx=max(mx,yeetthis);
        if(mx==M)
            output(mx);
    }
    else{
        divideandconquermybutt(yeetthis+Y);
    }
}

int main(){
    ifstream in;
    in.open("pails.in");
    in>>X;
    in>>Y;
    in>>M;
    in.close();
    divideandconquermybutt(0);
    cout<<mx;
    output(mx);
}