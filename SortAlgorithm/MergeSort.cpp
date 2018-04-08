/// \brief 归并排序
///
/// 将两个或两个以上的有序表合并成一个新的有序表。
///
/// \author HSDB
/// \date 2018-04-07

///               50 10 90 30 70 40 80 60 20
///         50 10 90 30 70             40 80 60 20
///      50 10 90       30 70       40 80       60 20
///    50 10    90     30   70     40   80     60   20
///  50    10   90     30   70     40   80     60   20
///    10 50    90     30   70     40   80     60   20
///      10 50 90       30 70      40   80     60   20
///         10 30 50 70 90         40   80     60   20
///         10 30 50 70 90          40 80      60   20
///         10 30 50 70 90          40 80       60 20
///         10 30 50 70 90             20 40 60 80
///               10 20 30 40 50 60 70 80 90
#include <iostream>
using namespace std;

/*
* 迭代法
*
* 1.将序列每相邻两个数字进行归并操作，形成 ceil(n/2) 个序列,排序。
* 2.若此时序列数不是 1 个则将上述序列再次归并。
* 3.重复 2，直到所有元素排序完毕。
*/
/*
template<typename T>
void merge_sort(T arr[],const int len){
    T *a=arr;
    T *b=new T[len];
    for(int seg=1;seg<len;seg+=seg){
        for(int start=0;start<len;start+=seg+seg){
            int low=start,mid=min(start+seg,len),high=min(start+seg+seg,len);
            int k=low;
            int start1=low,end1=mid;
            int start2=mid,end2=high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T* temp = a;
		a = b;
		b = temp;
    }
    if (a != arr) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}
*/

/*
* 递归法
* 1.申请空间，使其大小为两个已经排序序列之和。
* 2.设定两个指针，最初位置分别为两个已经排序序列的起始位置
* 3.比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一个位置
* 4.重复 3 直到某一指针到达序列尾
* 5.将另一序列剩下的所有元素直接复制到合并序列尾
*/

template<typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
	if (start >= end)
		return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;                                             //两个指针,指向两个排序序列的起始位置
	int start2 = mid + 1, end2 = end;
	merge_sort_recursive(arr, reg, start1, end1);                               //递归前边一段
	merge_sort_recursive(arr, reg, start2, end2);                               //递归后边一段
	int k = start;
	while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];   //选择相对小的放入合并空间，并移动指针到下一个位置
        
	while (start1 <= end1)
        reg[k++] = arr[start1++];                                               //把前边一段剩下的一个放入合并空间，并移动指针到下一个位置
        
	while (start2 <= end2)
        reg[k++] = arr[start2++];                                               //把后边一段剩下的一个放入合并空间，并移动指针到下一个位置
        
	for (k = start; k <= end; k++)                                              //把排好序的 reg 赋值给对应位置的 arr
		arr[k] = reg[k];
}

template<typename T>
void merge_sort(T arr[], const int len) {
	T *reg = new T[len];
	merge_sort_recursive(arr, reg, 0, len - 1);
	delete[] reg;
}

int main(){
    int arr[]={50,10,90,30,70,40,80,60,20};
    int len=(int) sizeof(arr) / sizeof(*arr);
    merge_sort(arr,len);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cin.get();
    return 0;
}