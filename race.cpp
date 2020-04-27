#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int K,N;
int run(int X){
    int fullsum=(1+X)*(X/2); //1+2+3+4
    if(K==fullsum){
        cout<<'A'<<endl;
        return X;
    }


    else if(fullsum<K){
        cout<<'B'<<endl;
        float temp=(float) X;
        float t2=((temp-1.0)/2.0);
        int cursum=(int)((t2)*(temp));
        cout<<"******** "<<X<<" "<<cursum<<endl<<endl;
        int curspeed=X;
        int incrementCount=0;
        while(cursum<K){
            cursum+=(2*curspeed);
            curspeed++;
            incrementCount+=2;
        }
        if(cursum-curspeed>=K){
            incrementCount--;
            cursum-=curspeed;
        }
        return incrementCount+X-1;
    }


    else{
        cout<<'C'<<endl;
        float curnum=1.0;
        float t2=((curnum)/2.0);
        float sum=(t2*(curnum+1.0));
        while(sum<K){
            curnum+=1;
            sum=(curnum+1.0)*(curnum/2.0);
        }
        return (int) curnum;
    }

}
int main(){
    ifstream in;
    ofstream out;
    in.open("race.in");
    out.open("race.out");
    in>>K;
    in>>N;
    for(int i=0;i<N;i++){
        int maxSpeed;
        in>>maxSpeed;
        int time=run(maxSpeed);
        out<<time<<endl;
        
    }
}
