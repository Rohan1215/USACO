#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int N;
vector <int> v;
bool blown[100];
void BlowLeft(int index,int radius){
    cout<<" [ "<<v[index]<<" *"<<radius<<"* ] ";
    blown[index]=true;
    //if can't blow anymore or at complete left, stop
    if(index==0){
        cout<<"at leftmost"<<endl;
    }
    else if((v[index]-v[index-1])>radius){
        cout<<"hay not in range"<<endl;
    }
    else{
        bool reachedend=false;
        int prevhay=index-1;
        while(((v[index]-v[prevhay])<=radius)){
            if(prevhay==0){
                blown[prevhay]=true;
                reachedend=true;
                break;
            }
            blown[prevhay]=true;
            prevhay--;
        }    
        if(reachedend==false)
            BlowLeft(prevhay+1,radius+1);
        
    }
}
void BlowRight(int index,int radius){
    cout<<" [ "<<v[index]<<" *"<<radius<<"* ] ";
    blown[index]=true;
    //if can't blow anymore or at complete right, stop
    if(index==N-1){
        cout<<"at rightmost"<<endl;
    }
    else if((v[index+1]-v[index])>radius){
        cout<<"hay not in range"<<endl;
    }
    else{
        bool reachedend=false;
        int nexthay=index+1;
        while(((v[nexthay]-v[index])<=radius)){
            if(nexthay==N-1){
                blown[nexthay]=true;
                reachedend=true;
                break;
            }
            blown[nexthay]=true;
            nexthay++;
        }    
        if(reachedend==false)
            BlowRight(nexthay-1,radius+1);
        
    }
}
int main(){
    ifstream in;
    in.open("angry.in");
    in>>N;
    for(int i=0;i<N;i++){
        int j;
        in>>j;
        v.push_back(j);
    }
    in.close();
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        cout<<v[i]<<" ";
    }
    int mx=0;
    cout<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            blown[j]=false;
        }   
        BlowLeft(i,1);
        cout<<endl;
        BlowRight(i,1);
        cout<<endl;
        int c=0;
        for(int j=0;j<N;j++){
            if(blown[j]){
                c++;
            }
        }
        mx=max(mx,c);
        cout<<c;
        cout<<endl<<endl;
    }
    cout<<endl;
    cout<<mx;
    ofstream out;
    out.open("angry.out");
    out<<mx;
    out.close();


    
}