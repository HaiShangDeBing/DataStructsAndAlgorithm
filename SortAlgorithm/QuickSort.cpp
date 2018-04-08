/// \brief 快速排序
///
/// 快速排序使用分治法策略来把一个序列分为两个子序列
/// 1.从数列中挑选出一个元素，称为基准（pivot），
/// 2.所有比基准值小的元素放在基准前面，所有比基准值大的元素放在基准后面，相等的放到任何一边。这个称为分区（partition）操作。
/// 3.递归子数列，重复 1,2。
/// \author HSDB
/// \date 2018-04-07

/// 第 1  交换 10,50,90,30,70,40,80,60,20
/// 第 2  交换 10,20,90,30,70,40,80,60,50  
/// 第 3  交换 10,20,40,30,70,90,80,60,50 
/// 第 4  交换 10,20,40,30,50,90,80,60,70
/// 第 5  交换 10,20,30,40,50,90,80,60,70
/// 第 6  交换 10,20,30,40,50,60,80,90,70
/// 第 7  交换 10,20,30,40,50,60,70,90,80
/// 第 8  交换 10,20,30,40,50,60,70,80,90
#include <iostream>
using namespace std;

/*
* 迭代法
*/
/*
struct Range {
    int start, end;
    Range(int s = 0, int e = 0) {
        start = s, end = e;
    }
};

template<typename T>
void quick_sort(T arr[],const int len){
    if (len <= 0)
    return; 
    Range r[len];
    int p = 0;
    r[p++] = Range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        T mid = arr[range.end];
        int left = range.start, right = range.end - 1;
        while (left < right) {
            while (arr[left] < mid && left < right) left++;
            while (arr[right] >= mid && left < right) right--;
            std::swap(arr[left], arr[right]);
        }
        if (arr[left] >= arr[range.end])
            std::swap(arr[left], arr[range.end]);
        else
            left++;
        r[p++] = Range(range.start, left - 1);
        r[p++] = Range(left + 1, range.end);
    }
}
*/

/*
* 递归法
*/

template<typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end)
    return;
    T mid = arr[end];                                       //选取最后一个元素作为基准
    int left = start, right = end - 1;
    while (left < right) {

        while (arr[left] < mid && left < right)             //从左往右找小于基准值的数
            left++;
        while (arr[right] >= mid && left < right)           //从右往左找大于基准值的数
            right--;
        swap(arr[left], arr[right]);                        //交换
    }
    if (arr[left] >= arr[end])                              //如果左边大于基准值，交换；
        swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

template<typename T>
void quick_sort(T arr[], const int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

int main(){
    int arr[]={50,10,90,30,70,40,80,60,20};
    int len=(int) sizeof(arr) / sizeof(*arr);
    quick_sort(arr,len);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cin.get();
    return 0;
}