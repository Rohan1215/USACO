#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
int B,K,N;
queue <bool> q;
int main(){
    ifstream in;
    in.open("maxcross.in");
    in>>N;
    in>>K;
    in>>B;
    int crosswalks[N+1];
    for(int i=0;i<N+1;i++){
        crosswalks[i]=0;
    }
    for(int i=0;i<B;i++){
        int n;
        in>>n;
        crosswalks[n]=1;
    }
    in.close();
    int currentsize=0;
    for(int i=1;i<K+1;i++){
        currentsize+=crosswalks[i];
        q.push(crosswalks[i]);
    }
    int minsize=currentsize;
    for(int i=K+1;i<N+1;i++){
        currentsize-=q.front();
        q.pop();
        currentsize+=crosswalks[i];
        q.push(crosswalks[i]);
        minsize=min(currentsize,minsize);
    }
    ofstream out;
    out.open("maxcross.out");
    out<<minsize;
    out.close();

    
        
}
