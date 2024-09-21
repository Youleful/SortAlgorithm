// SortAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm> // std::shuffle
#include <random>    // std::default_random_engine
#include <ctime>     // std::time
#include <cassert>


// 插入排序
void InsertSort(int* a, const int& n);
// 希尔排序
void ShellSort(int* a, const int& n);
// 选择排序
void SelectSort(int* a, const int& n);
// 堆排序
void AdjustDwon(int* a, const int& n, int root);
void HeapSort(int* a, const int& n);
// 冒泡排序
void BubbleSort(int* a, const int& n);
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);
// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);

int main() {
    // 初始化随机数种子
    std::srand(static_cast<unsigned>(std::time(0)));

    // 生成 1000 个随机数并存储在向量中
    std::vector<int> numbers;
    for (int i = 0; i < 10; ++i) {
        numbers.push_back(std::rand() % 100); // 生成范围在 0 到 9999 的随机数
    }

    // 使用随机引擎打乱这些数字的顺序
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(std::time(0)));

    // 输出打乱后的无序数字
    std::cout << "Random unordered numbers:" << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //InsertSort(numbers.data(), numbers.size());

    ShellSort(numbers.data(), numbers.size());

    std::cout << "ordered numbers:" << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;
}


void InsertSort(int* a, const int& n)
{
    assert(a);
    for (int i = 0; i < n - 1; i++)
        //注意：最后一个要插入数据的下标为n-1，此次插入有序数列的end下标为n-2
    {
        int end = i;//标记当前有序数列的最后一个位置下标
        int x = a[end + 1];//要插入的数据为有序数列的后一个位置

        while (end >= 0)//进行当前趟次的插入排列
        {
            //升序
            if (a[end] > x)//有序数列的数据比插入数据大，则往后挪动
            {
                a[end + 1] = a[end];
                end--;//向前找，进行排列数据
            }
            else//遇到不大于要插入数据，则不再往前找
            {
                break;
            }
        }
        a[end + 1] = x;//将要插入数据插入到不大于该数据的后一个位置
    }
}

void ShellSort(int* a, const int& n)
{
    int gap = n;
    while (gap > 1)
    {
        gap /= 2;//保证最后一次分组gap==1,即最后一次为直接插入排序
        //gap = gap / 3 + 1;//也可以写成这样，除3预排的效率相比于除2的好点
        for (int i = 0; i < n - gap; i++)
        {
            int end = i;
            int x = a[end + gap];
            while (end >= 0)
            {
                if (a[end] > x)
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                    break;
            }
            a[end + gap] = x;
        }
    }


}
