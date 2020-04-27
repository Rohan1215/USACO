#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int N,Q;
vector <int> bales;
map <int,int> numToIndex;
int binaryRight(int num){
    int beg=0;
    int end=N-1;
    if(num>=bales[end]){
        return end;
    }
    else if(num<=bales[beg]){
        return beg;
    }
    int mid=(end+beg)/2;
    while(beg!=end){
        if(bales[mid]<num && bales[mid+1]>num){
            return mid;
        }
        if(num<bales[mid]){
            end=mid;
            mid=(beg+end)/2;
        }
        else if(num>bales[mid]){
            beg=mid;
            mid=(beg+end)/2;
        }
        else{
            return mid;
        }
    }
    return mid;

}

int binaryLeft(int num){
    int beg=0;
    int end=N-1;
    if(num<=bales[beg]){
        return beg;
    }
    if(num>=bales[end]){
        return end;
    }
    int mid=(end+beg)/2;
    while(beg!=end){
        if(bales[mid-1]<num && bales[mid]>num){
            return mid;
        }
        if(num<bales[mid]){
            end=mid;
            mid=(beg+end)/2;
        }
        else if(num>bales[mid]){
            beg=mid;
            mid=(beg+end)/2;
        }
        else{
            return mid;
        }
    }
    return mid;

}
int main(){
    ifstream in;
    in.open("haybales.in");
    in>>N;
    in>>Q;
    int ans[Q];
    for(int i=0;i<N;i++){
        int t;
        in>>t;
        bales.push_back(t);
    }
    sort(bales.begin(),bales.end());
    for(int i=0;i<N;i++){
        cout<<bales[i]<<" ";
    }
    cout<<endl;
    for(int query=0;query<Q;query++){
        int s,e;
        in>>s;
        in>>e;
        if((s<bales[N-1])&&(e>bales[0])){
            int indexS=binaryLeft(s);
            int indexE=binaryRight(e);
            cout<<endl;
            cout<<query<<" "<<s<<" "<<indexS<<endl;
            cout<<query<<" "<<e<<" "<<indexE<<endl;
            cout<<endl;
            ans[query]=indexE-indexS+1;
        }
        else{
            ans[query]=0;
        }
    }
    in.close();
    ofstream out;
    out.open("haybales.out");
    cout<<endl<<"***"<<endl;
    for(int k=0;k<Q;k++){
        out<<ans[k]<<endl;
        cout<<ans[k]<<endl;
    }
    cout<<endl<<"***"<<endl;
    out.close();
    

}