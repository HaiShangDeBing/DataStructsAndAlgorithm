/// \brief KMP 字符串匹配算法
///
/// 此算法通过运用对这个词在不匹配时本身就包含足够的信息来确定下一个匹配将在哪里开始的发现，从而避免重新检查先前匹配的字符。
/// 即部分匹配表，程序中由 get_next 函数获得。时间复杂度最好为 O(m+n)，最坏为 O（(n-m+1)*m)。
///
/// \author HSDB
/// \date 2018-04-08
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// 调试时用 *(next._M_impl._M_start)@7 产看 vector 里的值
/// -1 0 0 0 -1 0 2
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