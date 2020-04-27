#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int N;
map <string, int> s;
int main(){
    ifstream in;
    in.open("citystate.in");
    in>>N;
    map<string,int> firstTwo;
    int count=0;
    for(int i=0;i<N;i++){
        string city;
        string state;
        in>>city;
        in>>state;
        //cout<<city[0]<<city[1]<<" "<<state<<endl; 
        if(city[0]==state[0]&&city[1]==state[1]){
            cout<<"what"<<endl;

        }
        else{
            string cityAbbr=city.substr(0,2);
            string s1;
            s1.append(cityAbbr);
            s1.append(state);
            s[s1]++;
            cout<<s[s1]<<" "<<s1<<" "<<i<<endl;
            string s2;
            s2.append(state);
            s2.append(cityAbbr);
            firstTwo[s1]=1;
            if(firstTwo[s2]>0){
                cout<<"  "<<s2<<"  "<<endl;
                count++;
            }
        }
    }
    in.close();
    cout<<count;
    ofstream out;
    out.open("citystate.out");
    out<<count;
    out.close();
}