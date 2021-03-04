#pragma once
#include <iostream>

using namespace std;
namespace SortFunc
{

	//ð������
	template <typename T>
	void BubbleSort(T arr[], int n)
	{
		int i, j;  T temp;
		for (i = 0; i < n - 1; i++) //����������len��������len-1��
		{
			for (j = 0; j < n - 1 - i; j++)//��ѭ��Ϊÿ�˱ȽϵĴ�������i�˱Ƚ�len-i��
			{
				if (arr[j] > arr[j + 1])//�Ƚ�����Ԫ�أ��������򽻻�
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}


	//ѡ������
	template <typename T>
	void SelectSort(T arr[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			//Ѱ��[i, n)�������С����
			int index = i;
			for (int j = i + 1; j < n; ++j)
			{
				if (arr[j] < arr[index])
					index = j;
			}

			//��[i, n)�е���Сֵ���i��Ԫ�ؽ��н���
			swap(arr[i], arr[index]);
		}
		return;
	}

	//��������
	//template<typename T>
	//void InsertSort(T arr[], int n)
	//{
	//	for (int i = 1; i < n; ++i)
	//	{
	//		//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
	//		for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j)
	//		{
	//			swap(arr[j], arr[j - 1]);
	//		}
	//	}
	//}

	//�Ż�, ���ø��ƶ����ǽ����ķ��������Ż�
	template<typename T>
	void InsertSort(T arr[], int n)
	{
		for (int i = 1; i < n; ++i)
		{
			//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
			T e = arr[i];
			int j;//j����Ԫ��eӦ�ò����λ��
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
			//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
			T e = arr[i];
			int j;//j����Ԫ��eӦ�ò����λ��
			for (j = i; j > l && arr[j - 1] > e; --j)
			{
				arr[j] = arr[j - 1];
			}

			arr[j] = e;
		}
	}

	//��arr[l....mid] ��arr[mid+1....r] �����ֽ��кϲ�
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

	//�ݹ�ʹ�ù鲢���� ��arr[l...r]�ķ�Χ��������
	template <typename T>
	void __MergeSort(T arr[], int l, int r)
	{
		if (r - l <= 15)//����ʹ�ò�������
		{
			InsertSort(arr, l, r);
			return;
		}//�Ż�
		//if (l >= r)
		//	return;

		int mid = (l + r) / 2;
		__MergeSort(arr, l , mid);
		__MergeSort(arr, mid + 1, r);
		//if (arr[mid] > arr[mid + 1])//�Ż��������úϲ�
			__merge(arr, l, mid, r);
	}

	template <typename T>
	void MergeSort(T arr[], int n)
	{
		__MergeSort(arr, 0, n - 1);
	}


}