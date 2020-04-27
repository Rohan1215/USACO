#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int N;
int count=0;
int main(){
    ifstream input;
    input.open("crossroad.in");
    input>>N;
    map<int,char> m;
    for(int i=0;i<N;i++){
        int a;
        char b;
        input>>a;
        input>>b;
        cout<<a<<" "<<b<<endl;
        if(m[a]){
            if(m.at(a)!=b){
                cout<<"LOOKIEHERE1 "<<a<<" "<<b<<" "<<m.at(a)<<endl;
                m[a]=b;
                cout<<"LOOKIEHERE2 "<<a<<" "<<b<<" "<<m.at(a)<<endl;
                count++;
            }
        }
        else{
            m[a]=b;
            cout<<"uwu"<<endl;
        }
    }
    input.close();
    ofstream output;
    output.open("crossroad.out");
    output<<count;
    output.close();
    cout<<count;
    return 0;
}