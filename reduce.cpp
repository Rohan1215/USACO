#include <fstream>
#include <iostream>
using namespace std;
int N;

int main(){
    ifstream in;
    in.open("reduce.in");
    in>>N;
    int cows[N][2];
    
    int top=0;
    int bot=40001;
    int left=40001;
    int right=0;
    int topI,botI,leftI,rightI;

    for(int i=0;i<N;i++){
        int x;
        int y;
        in>>x;
        in>>y;
        if(y>top){
            top=y;
            topI=i;
        }
        if(y<bot){
            bot=y;
            botI=i;
        }
        if(x>right){
            right=x;
            rightI=i;
        }
        if(x<left){
            left=x;
            leftI=i;
        }
        cows[i][0]=x;
        cows[i][1]=y;
    }
    in.close();
    int arr[4][4];
    for(int i=0;i<4;i++){
        arr[i][0]=40001;
        arr[i][1]=0;
        arr[i][2]=40001;
        arr[i][3]=0;
    }
    //prank bottom
    for(int i=0;i<N;i++){
        if(i==botI)
            continue;
        arr[0][0]=min(cows[i][1],arr[0][0]);
        arr[0][1]=max(cows[i][1],arr[0][1]);
        arr[0][2]=min(cows[i][0],arr[0][2]);
        arr[0][3]=max(cows[i][0],arr[0][3]);
    }
    //prank top
    for(int i=0;i<N;i++){
        if(i==topI)
            continue;
        arr[1][0]=min(cows[i][1],arr[1][0]);
        arr[1][1]=max(cows[i][1],arr[1][1]);
        arr[1][2]=min(cows[i][0],arr[1][2]);
        arr[1][3]=max(cows[i][0],arr[1][3]);
    }
    //prank left
    for(int i=0;i<N;i++){
        if(i==leftI)
            continue;
        arr[2][0]=min(cows[i][1],arr[2][0]);
        arr[2][1]=max(cows[i][1],arr[2][1]);
        arr[2][2]=min(cows[i][0],arr[2][2]);
        arr[2][3]=max(cows[i][0],arr[2][3]);
    }
    //prank right
    for(int i=0;i<N;i++){
        if(i==rightI)
            continue;
        arr[3][0]=min(cows[i][1],arr[3][0]);
        arr[3][1]=max(cows[i][1],arr[3][1]);
        arr[3][2]=min(cows[i][0],arr[3][2]);
        arr[3][3]=max(cows[i][0],arr[3][3]);
    }
    int sit1=(arr[0][3]-arr[0][2])*(arr[0][1]-arr[0][0]);
    int sit2=(arr[1][3]-arr[1][2])*(arr[1][1]-arr[1][0]);
    int sit3=(arr[2][3]-arr[2][2])*(arr[2][1]-arr[2][0]);
    int sit4=(arr[3][3]-arr[3][2])*(arr[3][1]-arr[3][0]);
    int u=min(sit1,sit2);
    int w=min(sit3,sit4);
    int uwu=min(u,w);
    cout<<uwu<<endl;
    ofstream out;
    out.open("reduce.out");
    out<<uwu;
    out.close();
    
}