#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int N;
map <string,int> BessieTimes;
map <string,int> ElsieTimes;
map<int,char> intToChar{
    {1,"1"},
    {2,"2"},
    {3,"3"},
    {4,"4"},
    {5,"5"},
    {6,"6"},
    {7,"7"},
    {8,"8"},
    {9,"9"},
    {10,"10"},
    {11,"11"},
    {12,"12"},
    {13,"13"},
    {14,"14"},
    {15,"15"},
    {16,"16"}
    
};
string toChar(int a, int b){
    return intToChar(a)+intToChar(b);
}
class field{
    public:
    int key;
    vector <field*> nextField;
    field(){
        key=-1;
    }
    field(int k){
        key=k;
    }
};
field allFields[17];

int traverseFields(int index, int BorE){
    int length= allFields[index].nextField.size();
    int vector<int> time;
    for(int i=0;i<length;i++){
        if(allFields[index].nextField[i]==N){
            if (BorE)
                time.push_back(BessieTimes[toChar(index,N)]);
            else
                time.push_back(ElsieTimes[toChar(index,N)]);
            
        }
        else{
            
        }
        
    }

}

int main(){
    ifstream in;
    in.open("meeting.in");
    in>>N;
    int M;
    in>>M;
    for(int i=0;i<M;i++){
        int start, end, bessie,elsie;
        in>>start;
        in>>end;
        in>>bessie;
        in>>elsie;
        if(allFields[start].key==-1)
            allFields[start]=field(start);
        allFields[start].nextField.push_back(&(allFields[end]));
        string s=toChar(start,end);
        BessieTimes[s]=bessie;
        ElsieTimes[s]=elsie;

    }
    vector <int> bessieEndTimes;
    vector<int> elsieEndTimes;
    //traverseFields(1,true);
    //traverseFields(1,false);
}