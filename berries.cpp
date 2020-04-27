#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
int main(){
    ifstream in;
    in.open("berries.in");
    vector <int> berries;
    in>>N;
    in>>K;
    for(int i=0;i<N;i++){
        int b;
        in>>b;
        berries.push_back(b);
    }
    sort(berries.begin(),berries.end(),greater<int>());
    for(int i=0;i<N;i++){
        cout<<berries[i]<<" ";
    }
}