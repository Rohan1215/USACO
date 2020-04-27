#include <fstream>
using namespace std;
int main(){
    ofstream out;
    out.open("race.in");
    out<<1000000000<<" "<<1000<<endl;
    for(int i=1;i<1001;i++){
        out<<i<<endl;
    }
    out.close();
}