#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int N;
char matrix[10][10];
int count=0;
void draw(){    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }

}
void toggle(int x, int y){
    count+=1;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            matrix[i][j]= matrix[i][j]=='0'? '1':'0';
        }
    }
}
void Untip(){
    for(int i=N-1;i>=0;i--){
        for(int j=N-1;j>=0;j--){
            if(matrix[i][j]=='1'){
//                cout<<i<<" "<<j<<" owo"<<endl;
                toggle(i+1,j+1);
                Untip();
            }
        }
    }
}

int main(){
    ifstream input;
    input.open("cowtip.in");
    input>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c;
            input>>c;
            matrix[i][j]=c;
        }
    }
    input.close();
    ofstream output;
    output.open("cowtip.out");
    Untip();    
    cout<<"***"<<count<<"***";
    output<<count;
    return 0;
}