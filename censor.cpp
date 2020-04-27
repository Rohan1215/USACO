#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
    ifstream in;
    in.open("censor.in");
    string str;
    string substring;
    in>>str;
    in>>substring;
    int subSize=substring.size();
    for(int i=0;i<str.size();i++){
        string s=str.substr(i,subSize);
        cout<<str<<"  "<<substring<<"  "<<s<<endl;
        if(substring.compare(s)==0){
            str.erase(i,subSize);
            if(i>subSize){
                i-=subSize;
            }
            else{
                i=0;
            }
        }

    }
    ofstream out;
    out.open("censor.out");
    out<<str<<endl;
    out.close();
}