/// \brief 堆排序
///
/// 完全二叉树每个结点的值都大于或等于左右孩子结点的值，称为大顶堆。
/// 将待排序的序列构造成一个大顶堆，把根结点（最大值）与末尾元素交换，
/// 然后将剩余的 n-1 个序列重新构造成一个堆，如此反复执行。
///
/// \author HSDB
/// \date 2018-04-07

/// 第 1  交换 50,10,90,60,70,40,80,30,20
/// 第 2  交换 50,70,90,60,10,40,80,30,20  
/// 第 3  交换 90,70,50,60,10,40,80,30,20
/// 第 4  交换 90,70,80,60,10,40,50,30,20      //第 1 次大顶堆
/// 第 5  交换 20,70,80,60,10,40,50,30,90      //最大值与末尾元素交换
/// 第 6  交换 80,70,20,60,10,40,50,30,90
/// 第 7  交换 80,70,50,60,10,40,20,30,90      //第 2 次大顶堆
/// 第 8  交换 30,70,50,60,10,40,20,80,90      //最大值交换
/// 第 9  交换 70,30,50,60,10,40,20,80,90
/// 第 10 交换 70,60,50,30,10,40,20,80,90      //第 3 次大顶堆
/// 第 11 交换 20,60,50,30,10,40,70,80,90      //最大值交换
/// 第 12 交换 60,20,50,30,10,40,70,80,90
/// 第 13 交换 60,30,50,20,10,40,70,80,90      //第 4 次大顶堆
/// 第 14 交换 40,30,50,20,10,60,70,80,90      //最大值交换
/// 第 15 交换 50,30,40,20,10,60,70,80,90      //第 5 次大顶堆      
/// 第 16 交换 10,30,40,20,50,60,70,80,90      //最大值交换
/// 第 17 交换 40,30,10,20,50,60,70,80,90      //第 6 次大顶堆      
/// 第 18 交换 20,30,10,40,50,60,70,80,90      //最大值交换
/// 第 19 交换 30,20,10,40,50,60,70,80,90      //第 7 次大顶堆      
/// 第 20 交换 10,20,30,40,50,60,70,80,90      //最大值交换 这一次其实已经排好序了，但是做了多余的交换
/// 第 21 交换 20,10,30,40,50,60,70,80,90      //第 8 次大顶堆      
/// 第 22 交换 10,20,30,40,50,60,70,80,90      //最大值交换
#include <iostream>
using namespace std;

/// 父节点i的左子节点在位置 (2i+1);
/// 父节点i的右子节点在位置 (2i+2);
/// 子节点i的父节点在位置 floor((i-1)/2);
template <typename T>
void max_heapify(T arr[],int start,int end){
    int dad=start;
    int son=dad*2+1;
    while(son<=end){
        if(son+1<=end && arr[son]<arr[son+1]){      //选出该父结点的左右子结点中较大的一个
            son++;
        }
        if(arr[dad]>arr[son]){                      //如果父结点最大，返回
            return;
        }else{
            swap(arr[dad],arr[son]);                //否则交换
            dad=son;                                //继续调整交换后的子结点作为父结点构成大顶堆
            son=dad*2+1;
        }
    }
}

template <typename T>
void heap_sort(T arr[],int len){
    for(int i=len/2-1;i>=0;i--){
        max_heapify(arr,i,len-1);                   //第一次构建大顶堆完成
    }
    for(int i=len-1;i>0;i--){
        swap(arr[0],arr[i]);                        //把根结点（最大值）与末尾元素交换
        max_heapify(arr,0,i-1);                     //然后将剩余的 n-1 个序列重新构造成一个堆。
    }
}

int main(){
    int arr[]={50,10,90,30,70,40,80,60,20};
    int len=(int) sizeof(arr) / sizeof(*arr);
    heap_sort(arr,len);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cin.get();
    return 0;
}