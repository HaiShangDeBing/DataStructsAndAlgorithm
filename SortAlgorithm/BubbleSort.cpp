/// \brief 冒泡排序
///
/// 两辆比较相邻记录的关键字，如果反序则交换，直到没有反序的记录。
/// 
///
/// \author HSDB
/// \date 2018-04-06

/// 第1趟 10,50,20,90,30,70,40,80,60
/// 第2趟 10,20,50,30,90,40,70,60,80
/// 第3趟 10,20,30,50,40,90,60,70,80
/// 第4趟 10,20,30,40,50,60,90,70,80
/// 第5趟 10,20,30,40,50,60,70,90,80
/// 第6趟 10,20,30,40,50,60,70,80,90
#include <iostream>
using namespace std;

template <typename T>
void bubble_sort(T arr[], const int len){
    bool flag;                                  ///改进后的冒泡排序，增加了一个flag来判断是否已经排序完成。
    for(int i=0;i<len-1;i++){
        flag=false;
        for(int j=len-1;j>i;j--){
            if(arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
                flag=true;
            }
        }
        if(flag==false)
            return;
    }
}

int main(){
    int arr[]={50,10,90,30,70,40,80,60,20};
    int len=(int) sizeof(arr) / sizeof(*arr);
    bubble_sort(arr,len);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cin.get();
    return 0;
}