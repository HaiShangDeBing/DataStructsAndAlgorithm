/// \brief 直接插入排序
///
/// 将一个记录插入到已经排好序的表中，从而得到一个新的有序表。
/// 对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。可以采用二分查找法来减少比较操作的数目
///
/// \author HSDB
/// \date 2018-04-06

/// 第1趟 10,50,90,30,70,40,80,60,20
/// 第2趟 10,50,90,30,70,40,80,60,20
/// 第3趟 10,30,50,90,70,40,80,60,20
/// 第4趟 10,30,50,70,90,40,80,60,20
/// 第5趟 10,30,40,50,70,90,80,60,20
/// 第6趟 10,30,40,50,70,80,90,60,20
/// 第7趟 10,30,40,50,60,70,80,90,20
/// 第8趟 10,20,30,40,50,60,70,80,90
#include <iostream>
using namespace std;

template <typename T>
void direct_insert_sort(T arr[], const int len){
    for(int i=1;i<len;i++){
        T temp=arr[i];
        for(int j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
                arr[j]=temp;
            }else
                break;
        }
    }
}

int main(){
    int arr[]={50,10,90,30,70,40,80,60,20};
    int len=(int) sizeof(arr) / sizeof(*arr);
    direct_insert_sort(arr,len);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cin.get();
    return 0;
}