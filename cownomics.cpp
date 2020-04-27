#include <fstream>
#include <iostream>
#include <set>
using namespace std;
int N,M;
int main(){
    ifstream in;
    in.open("cownomics.in");
    in>>N;
    in>>M;
    char sequences[2*N][M];
    for(int i=0;i<2*N;i++){
        for(int j=0;j<M;j++){
            char c;
            in>>c;
            sequences[i][j]=c;
        }
    }
    in.close();
    int count=0;
    for(int i=0;i<M;i++){
        set<char> spotted;
        bool similar=false;
        for(int j=0;j<N;j++){
            spotted.insert(sequences[j][i]);
        }
        for(int j=N;j<2*N;j++){
            if(spotted.find(sequences[j][i])!=spotted.end()){
                similar=true;
                break;
            }
        }
        if(similar==false){
            cout<<sequences[2][i]<<" "<<sequences[3][i]<<" ";
            count++;
        }
    }
    cout<<endl;
    cout<<count;
    ofstream out;
    out.open("cownomics.out");
    out<<count;
    out.close();
}