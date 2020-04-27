#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
struct cow{
    public:
        int first;
        int last;
        cow(){
            first=0;
            last=0;
        }
};
bool srtlast(cow l, cow r){
    return l.last<r.last;
}
bool srtfirst(cow l, cow r){
    return l.first<r.first;
}
bool works(int cowf, int cowl, int ch){
    return (((cowf<=ch) && (ch<=cowl)));
}
int main(){
    ifstream in;
    in.open("helpcross.in");
    ofstream out;
    out.open("helpcross.out");
    int chickNum,cowNum;
    in>>chickNum;
    in>>cowNum;
    int chickens[chickNum];
    cow cows[cowNum];
    for(int c=0;c<chickNum;c++){
        in>>chickens[c];
    }
    for(int c=0;c<cowNum;c++){
        in>>cows[c].first;
        in>>cows[c].last;
    }

}