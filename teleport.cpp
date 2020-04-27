#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int arr[4];
int abs(int x){
    if(x<0){
        x=-1*x;
    }
    return x;
}

int main(){
    ifstream in;
    in.open("teleport.in");
    for(int i=0;i<4;i++){
        int s;
        in>>s;
        cout<<s<<endl;
        arr[i]=s;
    }
    cout<<endl;
    in.close();
    ofstream out;
    out.open("teleport.out");
    int c1,c2,c3;
    c1=abs(arr[1]-arr[0]);
    c2=abs(arr[0]-arr[2])+abs(arr[3]-arr[1]);
    c3=abs(arr[0]-arr[3])+abs(arr[2]-arr[1]);
    cout<<c1<<endl<<c2<<endl<<c3<<endl;
    int a=min(c1,c2);
    out<<min(a,c3);
    out.close();

}