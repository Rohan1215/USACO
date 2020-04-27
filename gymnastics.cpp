#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int K,N;
int arr[20];
int main(){
    ifstream in;
    in.open("gymnastics.in");
    in>>K;
    in>>N;
    int exercises[K][N];
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            int c;
            in>>c;
            exercises[i][j]=c;
            cout<<c<<" ";
        }
    cout<<endl;
    }
    int count=0;
    int total=0;
    for(int i=1; i<N+1;i++){
        for(int j=i+1;j<N+1;j++){
            total++;


            int b=-1;
            bool works=true;

            for (int row=0;row<K;row++){
                int I;
                cout<<i<<" "<<j<<" "<<row<<" "<<b<<endl;
                for(int item=0;item<N;item++){
                    if((exercises[row][item]==i)||(exercises[row][item]==j)){

                        I=exercises[row][item];
                        if(b<0){
                            b=I;
                            cout<<"rheeeeeeeeeeeeeeewtffffffffffffffffff "<<I<<endl;
                        }
                        else{
                            if(b!=I)
                                works=false;

                        }
                        break;
                    }
                    
                }
                if(works==false){
                    cout<<i<<" "<<j<<" "<<I<<" BLACK"<<endl<<endl;
                    count++;
                    break;
                }



            }
    }

}
cout<<total-count;
in.close();
ofstream out;
out.open("gymnastics.out");
out<<total-count;
out.close();
}