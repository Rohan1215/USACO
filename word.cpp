#include <fstream>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N;
int K;
queue <string> lines;
int main(){
    ifstream in;
    ofstream out;
    in.open("word.in");
    out.open("word.out");
    in>>N;
    in>>K;
    int currentsize=0;
    int queuesize=0;
    for(int i=0;i<N;i++){
        string s;
        in>>s;
        int size=s.size();
        if(size+currentsize>K){
            for(int j=0;j<queuesize;j++){
                out<<lines.front();
                lines.pop();
                if(j!=(queuesize-1)){
                    out<<" ";
                }
            }
            queuesize=0;
            out<<endl;
            currentsize=0;
        }
        currentsize+=size;
        lines.push(s);
        queuesize++;
    }
    int t=lines.size();
    for(int i=0;i<t;i++){
        out<<lines.front();
        lines.pop();
        if(i!=(queuesize-1)){
            out<<" ";
        }
        
    }
}