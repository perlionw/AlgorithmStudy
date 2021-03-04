#pragma once
#include <iostream>

using namespace std;
namespace SortFunc
{

	//冒泡排序
	template <typename T>
	void BubbleSort(T arr[], int n)
	{
		int i, j;  T temp;
		for (i = 0; i < n - 1; i++) //排序趟数，len个数进行len-1趟
		{
			for (j = 0; j < n - 1 - i; j++)//内循环为每趟比较的次数，第i趟比较len-i次
			{
				if (arr[j] > arr[j + 1])//比较响铃元素，若逆序则交换
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}


	//选择排序
	template <typename T>
	void SelectSort(T arr[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			//寻找[i, n)里面的最小索引
			int index = i;
			for (int j = i + 1; j < n; ++j)
			{
				if (arr[j] < arr[index])
					index = j;
			}

			//将[i, n)中的最小值与第i个元素进行交换
			swap(arr[i], arr[index]);
		}
		return;
	}

	//插入排序
	//template<typename T>
	//void InsertSort(T arr[], int n)
	//{
	//	for (int i = 1; i < n; ++i)
	//	{
	//		//寻找元素arr[i]合适的插入位置
	//		for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j)
	//		{
	//			swap(arr[j], arr[j - 1]);
	//		}
	//	}
	//}

	//优化, 采用复制而不是交换的方法进行优化
	template<typename T>
	void InsertSort(T arr[], int n)
	{
		for (int i = 1; i < n; ++i)
		{
			//寻找元素arr[i]合适的插入位置
			T e = arr[i];
			int j;//j保存元素e应该插入的位置
			for (j = i; j > 0 && arr[j - 1] > e; --j)
			{
				arr[j] = arr[j - 1];
			}

			arr[j] = e;
		}
	}

	template<typename T>
	void InsertSort(T arr[], int l, int r)
	{
		for (int i = l + 1; i <= r; ++i)
		{
			//寻找元素arr[i]合适的插入位置
			T e = arr[i];
			int j;//j保存元素e应该插入的位置
			for (j = i; j > l && arr[j - 1] > e; --j)
			{
				arr[j] = arr[j - 1];
			}

			arr[j] = e;
		}
	}

	//将arr[l....mid] 和arr[mid+1....r] 两部分进行合并
	template<typename T>
	void __merge(T arr[], int l, int mid, int r)
	{
		T* aux = new T[r - l + 1];

		for (int i = l; i <= r; ++i)
			aux[i - l] = arr[i];

		int i = l, j = mid + 1;
		for (int k = l; k <= r; ++k)
		{
			if (i > mid)
			{
				arr[k] = aux[j - l];
				j++;
			}
			else if (j > r)
			{
				arr[k] = aux[i - l];
				i++;
			}
			else if (aux[i - l] < aux[j - l])
			{
				arr[k] = aux[i - l];
				i++;
			}
			else
			{
				arr[k] = aux[j - l];
				j++;
			}
		}

		delete[] aux;
	}

	//递归使用归并排序， 对arr[l...r]的范围进行排序
	template <typename T>
	void __MergeSort(T arr[], int l, int r)
	{
		if (r - l <= 15)//有序使用插入排序
		{
			InsertSort(arr, l, r);
			return;
		}//优化
		//if (l >= r)
		//	return;

		int mid = (l + r) / 2;
		__MergeSort(arr, l , mid);
		__MergeSort(arr, mid + 1, r);
		//if (arr[mid] > arr[mid + 1])//优化，有序不用合并
			__merge(arr, l, mid, r);
	}

	template <typename T>
	void MergeSort(T arr[], int n)
	{
		__MergeSort(arr, 0, n - 1);
	}


}