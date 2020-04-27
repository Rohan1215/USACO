#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;
class Cow
{
    public:
    bool checked=false;
    vector <string> adj;
};
int main(){
    ifstream in;
    in.open("lineup.in");
    int N;
    in>>N;
    cout<<N<<endl;
    string s;
    string arr[N][2];
    map<string,Cow> nametoCow={{"Beatrice",Cow()},{"Belinda",Cow()},{"Bella",Cow()},{"Bessie",Cow()},{"Betsy",Cow()},{"Blue",Cow()},{"Buttercup",Cow()},{"Sue",Cow()}};
    string allnames[8]={"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};

    for(int i=0;i<N;i++){
        string s1;
        string s2;
        for(int j=0;j<6;j++){
            string temp;
            in>>temp;
            if(j==0){
                s1=temp;
                arr[i][0]=s1;
                cout<<"*** "<<s1<<" ";
            }
            else if(j==5){
                s2=temp;
                arr[i][1]=s2;
                cout<<s2<<" ***"<<endl;
            }
        }
        nametoCow[s1].adj.push_back(s2);
        nametoCow[s2].adj.push_back(s1);

    }
    cout<<endl<<endl;
    for(int a=0;a<8;a++){
        cout<<"*** "<<allnames[a]<<" *** ";
        for(int b=0;b<nametoCow[allnames[a]].adj.size();b++){
            cout<<nametoCow[allnames[a]].adj[b]<<" ";
        }
        cout<<endl;
    }

    vector<string> f;
    queue<string> havtado;
    int num=8;

    for(int i=0;i<8;i++){
        if(nametoCow[allnames[i]].adj.size()==0){
            f.push_back(allnames[i]);
            nametoCow[allnames[i]].checked=true; 
            num--;
        }
        else if(nametoCow[allnames[i]].adj.size()==1){
            f.push_back(allnames[i]);
            nametoCow[allnames[i]].checked=true;
            num--;
            havtado.push(nametoCow[allnames[i]].adj[0]);
            break;
        }
    }
    cout<<endl<<endl;
    for(int o=0;o<8;o++){
        cout<<nametoCow[allnames[o]].checked<<" ";
    }
    cout<<endl;
    int kms=0;
    while(num>0){
        kms++;
        while(havtado.size()>0){
            int length=nametoCow[havtado.front()].adj.size();
            nametoCow[havtado.front()].checked=true;
            cout<<"A ";
            for(int o=0;o<8;o++){
                cout<<nametoCow[allnames[o]].checked<<" ";
            }
            cout<<" "<<kms<<" "<<havtado.front()<<" "<<endl;
            for(int j=0;j<length;j++){
                string temp =nametoCow[havtado.front()].adj[j];
                if(nametoCow[temp].checked==false){
                    havtado.push(temp);
                }
                
            }
            f.push_back(havtado.front());
            havtado.pop();
            num--;
        }
        cout<<"B ";
        for(int o=0;o<8;o++){
                cout<<nametoCow[allnames[o]].checked<<" ";
            }
        cout<<endl;
        if(havtado.size()==0){
            for(int i=0;i<8;i++){
                if((nametoCow[allnames[i]].adj.size()==0) &&(nametoCow[allnames[i]].checked==false)){
                    f.push_back(allnames[i]);
                    nametoCow[allnames[i]].checked=true;
                    num--;
                }
                if((nametoCow[allnames[i]].adj.size()==1 )&&(nametoCow[allnames[i]].checked==false)){
                    f.push_back(allnames[i]);
                    nametoCow[allnames[i]].checked=true;
                    num--;
                    havtado.push(nametoCow[allnames[i]].adj[0]);
                    break;
                }
            }
        }
    }
    ofstream out;
    out.open("lineup.out");
    
    for(int o=0;o<f.size();o++){
        out<<f[o]<<endl;
    }
    out.close();

}