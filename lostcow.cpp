#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int X,Y;
int main(){
    ifstream in;
    in.open("lostcow.in");
    in>>X;
    in>>Y;
    in.close();
    int count=0;
    int At=X;
    bool notfound =true;
    int factor=0;
    if(X>Y){
        while(notfound){
            int goTo=X+(pow(-1,factor)*(pow(2,factor)));
            cout<<goTo<<" ";
            if(goTo<=Y){
                notfound=false;
                count+=At-Y;
                break;
            }
            count+=abs(At-goTo);
            At=goTo;
            factor++;
        }
    }
    else{
        while(notfound){
            int goTo=X+(pow(-1,factor)*(pow(2,factor)));
            cout<<goTo<<" ";
            if(goTo>=Y){
                notfound=false;
                count+=Y-At;
                break;
            }
            count+=abs(goTo-At);
            At=goTo;
            factor++;
        }
    }
    cout<<endl;
    cout<<count;
    ofstream out;
    out.open("lostcow.out");
    out<<count;
    out.close();

}
//6   7
//7   4
//1   7
//1 3 5
