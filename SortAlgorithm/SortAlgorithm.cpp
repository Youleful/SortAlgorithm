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
    for (int i = 0; i < 100; ++i) {
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

    InsertSort(numbers.data(), numbers.size());

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
    for (int i = 1; i < n; ++i)
    {
        int cur = *(a + i);
        for (int j = i - 1; j >= 0; j--)
        {
            //和前面的每个值进行比较,如果比他小就插入
            if (cur < *(a + j))
            {
                *(a + j + 1) = *(a + j);
                *(a + j) = cur;
            }
        }
    }
}
