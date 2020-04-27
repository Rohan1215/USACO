#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int N,M;
struct cow{
    int f;
    int l;
};
cow cows[100000];
int cerealLeft[100000][100000];
int main(){
    ifstream in ("cereal.in");
    in>>N>>M;
    for(int i=0;i<N;i++){
        in>>cows[i].f>>cows[i].l;
    }
}