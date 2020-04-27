#include <fstream>
#include <iostream>
using namespace std;
int A,B,N;
int main(){
    ifstream in;
    in.open("cowroute.in");
    in>>A;
    in>>B;
    in>>N;
    int mx=1001;
    cout<<" "<<A<<" "<<B<<" "<<N<<endl;
    for(int i=0;i<N;i++){
        int cost;
        in>>cost;
        int tripLength;
        in>>tripLength;
        cout<<"*"<<cost<<"* ";
        bool firstfound=false;
        for(int j=0;j<tripLength;j++){
            int stop;
            in>>stop;
            cout<<stop<<" ";
            if(stop==A){
                firstfound=true;
            }
            else if(stop==B){
                if(firstfound){
                    mx=min(mx,cost);
                }
            }
            

        }
        cout<<endl;
    }
    in.close();
    if(mx==1001){
        mx=-1;
    }
    cout<<mx;
    ofstream out;
    out.open("cowroute.out");
    out<<mx;
    out.close();
}