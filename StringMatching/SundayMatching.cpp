/// \brief Sunday 字符串匹配算法
///
/// 在匹配失败时关注的是主串中参加匹配的最末位字符的下一位字符。
/// 如果该字符没有在模式串中出现则直接跳过，即移动位数 = 模式串长度 + 1；
/// 否则，其移动位数 = 模式串长度 - 该字符最右出现的位置(以0开始) = 模式串中该字符最右出现的位置到尾部的距离 + 1。
///
/// \author HSDB
/// \date 2018-04-08
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxNum = 127;

int sunday_matching(const string& S,const string& T){
    int n=S.length();                                            //主串 S 的长度
    int m=T.length();
    int shift[maxNum];
    // 默认值，移动 m+1 位
    for(int i=0;i<maxNum;i++){
        shift[i]=m+1;
    }
    // 子串 T 中每个字母出现的最后的下标
    // 所对应的主串参与匹配的最末位字符的下一位字符移动到该位，所需要的移动位数
    // P[i] 对应的字符的 ASCII 整数值
    for(int i=0;i<m;i++){
        shift[T[i]] = m-i;
    }

    // 子串开始位置在主串的位置
    int start=0;
    // 子串串已经匹配到的位置
    int current;
    while(start<=n-m){
        current = 0;
        while(S[start+current]==T[current]){
            current++;
            if(current >= m){
                return start;               // 匹配成功
            }
        }
        // 找到主串中当前跟模式串匹配的最末字符的下一个字符
        // 在模式串中出现最后的位置
        // 所需要从(模式串末尾+1)移动到该位置的步数
        start += shift[S[start+m]];
    }
    return -1;
}

int main(){
    string S="BBC ABCDAB ABCDABCDABDE";
    string T="ABCDABD";
    int index=sunday_matching(S,T);
    cout<<index;
    cin.get();
    return 0;
}