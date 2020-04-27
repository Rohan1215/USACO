#include <fstream>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N;
int main(){
    ifstream in;
    in.open("photo.in");
    in>>N;
    int inarr[N-1];
    for(int i=0;i<N-1;i++){
        int t;
        in>>t;
        inarr[i]=t;
    }
    in.close();
    for(int i=1;i<N;i++){
        bool works=true;
        int curnum=i;
        vector <int> v;
        set <int> s;
        v.push_back(curnum);
        s.insert(curnum);
        cout<<curnum<<" ";
        for(int j=0;j<N-1;j++){
            curnum=inarr[j]-curnum;
            if(curnum<1){
                works=false;
                break;
            }
            v.push_back(curnum);
            s.insert(curnum);
            cout<<curnum<<" ";
            if(v.size()!=s.size()){
                works=false;
                break;
            }
        }
        if(works){
            ofstream out;
            out.open("photo.out");
            for(int k=0;k<v.size();k++){
                out<<v[k];
                if(k!=(v.size()-1)){
                    out<<" ";
                }
            }
            out.close();
            break;
        }
        
        cout<<endl;
    }

}