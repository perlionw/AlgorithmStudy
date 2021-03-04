#pragma once
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
using namespace std;
namespace TestHelper
{
	int* generate_rand_arr(int n, int l_range, int r_range)
	{
		assert(l_range <= r_range);
		int * arr = new int[n];
		srand(time(NULL));

		for (int i = 0; i < n; ++i)
		{
			arr[i] = rand() % (r_range - l_range + 1) + l_range;
		}

		return arr;
	}

	template<typename T>
	int *copy_arr(T a[], int n)
	{
		int* arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}

	template<typename T>
	void print_arr(T arr[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	template<typename T>
	void caculate_sort_time(std::string sort_name, T arr[], int n, void(*sort)(T arr[], int n))
	{
		clock_t start_time =  clock();
		sort(arr, n);
		clock_t end_time = clock();

		assert(!IsSortSuccess(arr, n));
		cout << sort_name << ": " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
	}

	template<typename T>
	bool IsSortSuccess(T arr[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	int* generate_nearly_order_arr(int n, int swap_times)
	{
		int * arr = new int[n];
		for (int i = 0; i < n; ++i)
			arr[i] = i;

		srand(time(NULL));
		for (int i = 0; i < swap_times; ++i)
		{
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}

		return arr;
	}
}