// SortAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm> // std::shuffle
#include <random>    // std::default_random_engine
#include <ctime>     // std::time
#include <cassert>


// ��������
void InsertSort(int* a, const int& n);
// ϣ������
void ShellSort(int* a, const int& n);
// ѡ������
void SelectSort(int* a, const int& n);
// ������
void AdjustDwon(int* a, const int& n, int root);
void HeapSort(int* a, const int& n);
// ð������
void BubbleSort(int* a, const int& n);
// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
// ��������
void CountSort(int* a, int n);

int main() {
    // ��ʼ�����������
    std::srand(static_cast<unsigned>(std::time(0)));

    // ���� 1000 ����������洢��������
    std::vector<int> numbers;
    for (int i = 0; i < 100; ++i) {
        numbers.push_back(std::rand() % 100); // ���ɷ�Χ�� 0 �� 9999 �������
    }

    // ʹ��������������Щ���ֵ�˳��
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(std::time(0)));

    // ������Һ����������
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
            //��ǰ���ÿ��ֵ���бȽ�,�������С�Ͳ���
            if (cur < *(a + j))
            {
                *(a + j + 1) = *(a + j);
                *(a + j) = cur;
            }
        }
    }
}
