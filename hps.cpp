#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    ifstream in;
    in.open("hps.in");
    int N;
    in>>N;
    int games[N][2][3];
    char track[N];
    char represent[]={'H','P','S'};
    map <char,int>beats={{'S',0},{'H',1},{'P',2}}; //H beats S, P beats H, S beats P
    int count[]={0,0,0};
//...................................................................................
    for(int i=0;i<N;i++){
        char s;
        in>>s;
        track[i]=s;
        int a=beats[s];
        count[a]+=1;
        for(int j=0;j<3;j++){
            games[i][1][j]=count[j];
        }
    }
//.......................................checking forward ^^..........................
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cout<<represent[j]<<" "<<games[i][1][j]<<endl;
        }
        cout<<endl;
    }
//.................print
    int bount[3];
    bount[0]=0;
    bount[1]=0;
    bount[2]=0;
    for(int p=0;p<3;p++){
        cout<<bount[p]<<endl;
    }
    for(int i=N-1;i>=0;i--){
        int a =beats[track[i]];
        for(int j=0;j<3;j++){
            games[i][2][j]=bount[j];
        }
        bount[a]+=1;
    }
//...............go back rheeeeee ^^...........
    cout<<"uwu"<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cout<<represent[j]<<" "<<games[i][2][j]<<endl;
        }
        cout<<endl;
    }
//.............. print ^^
    int mx=0;
    for(int i=0; i<N;i++){
        int owo;
        int uwu;
        int m1=0;
        int m2=0;
        for(int j=0;j<3;j++){
            owo=games[i][1][j];
            m1=max(owo,m1);
        }
        for(int j=0;j<3;j++){
            uwu=games[i][2][j];
            m2=max(uwu,m2);
        }
        mx=max(mx,m1+m2);
    cout<<endl;
    }
    cout<<mx;
    ofstream out;
    out.open("hps.out");
    out<<mx;
    out.close();

}
