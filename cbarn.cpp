#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
class room{
    public:
    int id;
    int capacity;
    room* NextRoom;
    room(){
//        cout<<'.';
    }
    room(int c,int d){
        capacity=c;
        id=d;
    }
    room(room* r,int c,int d){
        NextRoom=r;
        capacity=c;
        id=d;
    }
};
int N;
int main(){
    ifstream in;
    in.open("cbarn.in");
    in>>N;
    int CowsPerRoom[N];
    room rooms[N];

    for(int i=0;i<N;i++){
        int j;
        in>>j;
        CowsPerRoom[i]=j;
        rooms[i]=room(&rooms[i-1],j,i);
    }
    for (int i=0;i<N-1;i++){
        rooms[i].NextRoom=&rooms[i+1];
    }
    rooms[N-1].NextRoom=&rooms[0];
    for(int a=0;a<N;a++){
//        cout<<rooms[a].capacity<<endl;
    }
//    cout<<endl;
    long mx=10000000000;
    for(int i=0;i<N;i++){
        long count=0;
        int curkey=i;
        int pos=i;
        vector<int> v;
        int di=0;
        do
        {
//            cout<<"[ *"<<pos<<"* "<<rooms[pos].capacity<<" "<<di<<" ] ";
            int diff=(di)*rooms[pos].capacity;
            v.push_back(diff);
            count+=diff;
            pos=(*(rooms[pos].NextRoom)).id;
            di++;
        } while (pos!=curkey);
//        cout<<endl;
        for(int j=0;j<N;j++){
//            cout<<v[j]<<" ";
        }
        mx=min(mx,count);
//        cout<<endl;
//        cout<<count;
//       cout<<endl<<endl;
    }
    ofstream out;
    out.open("cbarn.out");
    out<<mx;
    out.close();
//    cout<<mx;   
}