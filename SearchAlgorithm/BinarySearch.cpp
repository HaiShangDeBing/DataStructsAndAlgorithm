/// \brief 二分查找
///
/// 搜索过程从有序数组的中间元素开始，如果中间元素正好是要查找的元素，则搜索过程结束；
/// 如果某一特定元素大于或者小于中间元素，则在数组大于或小于中间元素的那一半中查找
///
/// \author HSDB
/// \date 2018-04-08
#include <iostream>
using namespace std;

int binary_search(const int arr[],int n,int key){
    int low=0,high=n-1,mid;
    while(low<=high){
        //mid=(low+high)/2;                                   //可能会溢出
        mid=low+(high-low)/2;
        //mid=low+(how-low)*(key-a[low])/(a[high]-a[low]);  //插值查找，对于表长较大关键字又分布均匀
        if(arr[mid]>key){
            high=mid-1;
        }else if(arr[mid]<key){
            low=mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,3,4,6,7,8,10,13,14};
    int len=(int) sizeof(arr) / sizeof(*arr);
    cout<<binary_search(arr,len,9);
    cin.get();
    return 0;
}