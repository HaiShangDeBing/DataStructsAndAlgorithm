/// \brief 简单选择排序
///
/// 通过 n-i 次关键字的比较，从 n-i+1 个记录中选出关键字最小的记录。
/// 
///
/// \author HSDB
/// \date 2018-04-06

/// 第1趟 10,50,90,30,70,40,80,60,20
/// 第2趟 10,20,90,30,70,40,80,60,50
/// 第3趟 10,20,30,90,70,40,80,60,50
/// 第4趟 10,20,30,40,70,90,80,60,50
/// 第5趟 10,20,30,40,50,90,80,60,70
/// 第6趟 10,20,30,40,50,60,80,90,70
/// 第7趟 10,20,30,40,50,60,70,90,80
/// 第8趟 10,20,30,40,50,60,70,80,90
#include <iostream>
using namespace std;

template <typename T>
void simple_select_sort(T arr[], const int len){
    int min;
    for(int i=0;i<len-1;i++){
        min=i;
        for(int j=i+1;j<len;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        if(min!=i)
            swap(arr[i],arr[min]);
    }
}

int main(){
    int arr[]={50,10,90,30,70,40,80,60,20};
    int len=(int) sizeof(arr) / sizeof(*arr);
    simple_select_sort(arr,len);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cin.get();
    return 0;
}