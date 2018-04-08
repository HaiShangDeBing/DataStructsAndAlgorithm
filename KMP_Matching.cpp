#include <iostream>
#include <string>
#include <vector>
using namespace std;
void get_next(const string &p,vector<int> &next){
    next.resize(p.size());
    next[0]=-1;
    int i=0,j=-1;
    while(i!=p.size()-1){
        if(j==-1 || p[i]==p[j]){
            ++i;
            ++j;
            if(p[i]!=p[j]){
                next[i]=j;          //之前只有这一行
            }else{
                next[i]=next[j];
            }
           
        }else{
            j=next[j];
        }
    }
}

int kmp_matching(const string &s,const string &p,const int index=0){
    vector<int>next;
    get_next(p,next);
    int i=index,j=0;
    while(i!=s.length() && j!=p.length()){
        if(j==-1 || s[i]==p[j]){
            ++i;
            ++j;
        }else{
            j=next[j];
        }
    }
    return j==p.length()?i-j:-1;
}

int main(){
    string S="BBC ABCDAB ABCDABCDABDE";
    string T="ABCDABD";
    int index=kmp_matching(S,T,0);
    cout<<index;
    cin.get();
    return 0;
}