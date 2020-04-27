#include <fstream>
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    ifstream in;
    in.open("whereami.in");
    int N;
    in>>N;
    char s[N];
    string st="";
    for(int i=0;i<N;i++){
        in>>s[i];
        st+=s[i];
    }
    in.close();
    cout<<N<<endl;
    cout<<s<<endl;
    int ans;
    bool work=true;
    for(int i=0;i<N;i++){
        ans=i;
        set <string> stringset;
        work=true;
        for(int j=0;j<N+1-i;j++){
            string temp=st.substr(j,i);
            int a =stringset.size();
            stringset.insert(temp);
            int b=stringset.size();
            if(a==b){
                work=false;
                break;
            }
        }
        if(work==true)
            break;
    }
    ofstream out;
    out.open("whereami.out");
    out<<ans<<endl;
    cout<<ans;
    out.close();
}