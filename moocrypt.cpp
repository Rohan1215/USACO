#include <fstream>
#include <iostream>
using namespace std;
int N,M;
int main(){
    ifstream in;
    in.open("moocrypt.in");
    in>>N;
    in>>M;
    int count[26][26];
    char letters[N][M];
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            count[i][j]=0;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char t;
            in>>t;
            letters[i][j]=t;
            //cout<<t-'A'<<" ";
        }
        //cout<<endl;
    }
    in.close();
    //left to right
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int letterM=letters[i][j]-'A';
            if(i>=2){
                if(letters[i-1][j]==letters[i-2][j]){
                    count[letterM][letters[i-1][j]-'A']+=1;
                }
                if(j>=2){
                    if(letters[i-1][j-1]==letters[i-2][j-2]){
                        count[letterM][letters[i-1][j-1]-'A']+=1;
                    }
                }
                if(j<M-2){
                    if(letters[i-1][j+1]==letters[i-2][j+2]){
                        count[letterM][letters[i-1][j+1]-'A']+=1;
                    }
                }
            }
            if(j>=2){
                if(letters[i][j-1]==letters[i][j-2]){
                    count[letterM][letters[i][j-1]-'A']+=1;
                }
            }
            if(i<N-2){
                if(letters[i+1][j]==letters[i+2][j]){
                    count[letterM][letters[i+1][j]-'A']+=1;
                }
                if(j>=2){
                    if(letters[i+1][j-1]==letters[i+2][j-2]){
                        count[letterM][letters[i+1][j-1]-'A']+=1;
                    }
                }
                if(j<M-2){
                    if(letters[i+1][j+1]==letters[i+2][j+2]){
                        count[letterM][letters[i+1][j+1]-'A']+=1;
                    }
                }
            }
            if(j<M-2){
                if(letters[i][j+1]==letters[i][j+2]){
                    count[letterM][letters[i][j+1]-'A']+=1;
                }
            }
            
        }
    }
    cout<<endl;
    int mx=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(j==14){
                continue;
            }
            if(i!=j){
                mx=max(mx,count[i][j]);
            }
        }    
}
    ofstream out;
    out.open("moocrypt.out");
    out<<mx;
    cout<<mx;
    out.close();
}