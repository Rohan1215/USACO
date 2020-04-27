#include <fstream>
#include <iostream>
#include <set>
using namespace std;
int N;
int B[20];
int E[20];
int S[20];
int I[20];
int G[20];
int O[20];
int M[20];
// (B+I)(G+O+E+S)(M)
int Bs,Es,Ss,Is,Gs,Os,Ms=0;
int main(){
    ifstream in;
    in.open("geteven.in");
    in>>N;
    for(int i=0;i<N;i++){
        char c;
        int n;
        in>>c;
        in>>n;
        if(c=='B'){
            B[Bs]=n;
            Bs++;
        }
        else if(c=='E'){
            E[Es]=n;
            Es++;
        }
        else if(c=='S'){
            S[Ss]=n;
            Ss++;
        }
        else if(c=='I'){
            I[Is]=n;
            Is++;
        }   
        else if(c=='G'){
            G[Gs]=n;
            Gs++;
        }
        else if(c=='O'){
            O[Os]=n;
            Os++;
        }  
        else{
            M[Ms]=n;
            Ms++;
        }
    }
    in.close();
    int BIodd=0;
    int BIeven=0;
    int GOESeven=0;
    int GOESodd=0;
    int Meven=0;
    int Modd=0;
    for(int i=0;i<Ms;i++){
        if(M[i]%2==0)
            Meven++;
        else
            Modd++;
    }
    for(int i=0;i<Bs;i++){
        for(int j=0;j<Is;j++){
            if((B[i]+I[j])%2==0)
                BIeven++;
            else
                BIodd++;
        }
    }
    for(int a=0;a<Gs;a++){
        for(int b=0;b<Os;b++){
            for(int c=0;c<Es;c++){
                for(int d=0;d<Ss;d++){
                    if((G[a]+O[b]+E[c]+S[d])%2==0)
                        GOESeven++;
                    else
                        GOESodd++;
                }
            }
        }
    }
    cout<<BIeven<<" "<<BIodd<<endl;
    cout<<GOESeven<<" "<<GOESodd<<endl;
    cout<<Meven<<" "<<Modd<<endl;
    int count=0;
    count+=BIeven*GOESeven*Meven+BIeven*GOESeven*Modd+BIeven*GOESodd*Meven+BIeven*GOESodd*Modd;
    count+=BIodd*GOESeven*Meven+BIodd*GOESeven*Modd+BIodd*GOESodd*Meven;
    cout<<count;
    ofstream out;
    out.open("geteven.out");
    out<<count;
    out.close();
}