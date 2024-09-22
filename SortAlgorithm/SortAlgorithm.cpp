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
    for (int i = 0; i < 10; ++i) {
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

    //InsertSort(numbers.data(), numbers.size());

    //ShellSort(numbers.data(), numbers.size());

    //SelectSort(numbers.data(), numbers.size());

    HeapSort(numbers.data(), numbers.size());

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
        //ע�⣺���һ��Ҫ�������ݵ��±�Ϊn-1���˴β����������е�end�±�Ϊn-2
    {
        int end = i;//��ǵ�ǰ�������е����һ��λ���±�
        int x = a[end + 1];//Ҫ���������Ϊ�������еĺ�һ��λ��

        while (end >= 0)//���е�ǰ�˴εĲ�������
        {
            //����
            if (a[end] > x)//�������е����ݱȲ������ݴ�������Ų��
            {
                a[end + 1] = a[end];
                end--;//��ǰ�ң�������������
            }
            else//����������Ҫ�������ݣ�������ǰ��
            {
                break;
            }
        }
        a[end + 1] = x;//��Ҫ�������ݲ��뵽�����ڸ����ݵĺ�һ��λ��
    }
}

void ShellSort(int* a, const int& n)
{
    int gap = n;
    while (gap > 1)
    {
        gap /= 2;//��֤���һ�η���gap==1,�����һ��Ϊֱ�Ӳ�������
        //gap = gap / 3 + 1;//Ҳ����д����������3Ԥ�ŵ�Ч������ڳ�2�ĺõ�
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

void SelectSort(int* a, const int& n)
{
    assert(a);
    for (int i = 0; i < n; ++i)
    {

        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            
            if (*(a + j) < *(a + minIndex))
            {
                minIndex = j;
            }
        }

        int temp = *(a + minIndex);
        *(a + minIndex) = *(a + i);
        *(a + i) = temp;
    }
}

void AdjustDwon(int* a, const int& end, int start)
{

    //create father node
    int dad = start;

    //create child node
    int child = 2 * dad + 1;
    
    //if the child node is in the range of heap
    while (child <= end)
    {
        //compare the two child node and get the bigger one
        if (child + 1 <= end && a[child] < a[child + 1])
            child++;

        //if value of father node is bigger than child node, jump out the loop
        if (a[dad] > a[child])
            return;
        else
        {
            //change the value of father and son
            std::swap(a[dad], a[child]);

            //get the next father and son node
            int dad = child;
            child = 2 * dad + 1;
        }
    }
}

void HeapSort(int* a, const int& n)
{
    assert(a);

    //initialize the heap,begin at the last father node
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        AdjustDwon(a, n - 1, i);
    }

    //��������
    for (int i = n - 1; i > 0; --i)
    {
        std::swap(a[0], a[i]);
        //do the change in the remaining heap
        AdjustDwon(a, i - 1, 0);
    }
}

