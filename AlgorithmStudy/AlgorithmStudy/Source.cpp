#include "SortFunc.h"
#include "TestHelper.h"
#include "MergeSort.h"
#include <thread>
int main()
{
	int n = 10000;
	int* arr = TestHelper::generate_rand_arr(n, 0, n);
	int* arr1 = TestHelper::copy_arr(arr, n);
	int* arr2 = TestHelper::copy_arr(arr, n);
	int* arr3 = TestHelper::copy_arr(arr, n);
	int* arr4 = TestHelper::copy_arr(arr, n);

	//TestHelper::print_arr(arr, n);
	TestHelper::caculate_sort_time("BubbleSort", arr1, n, SortFunc::BubbleSort);
	TestHelper::caculate_sort_time("SelectSort", arr2, n, SortFunc::SelectSort);
	TestHelper::caculate_sort_time("InsertSort", arr3, n, SortFunc::InsertSort);
	TestHelper::caculate_sort_time("MergeSort", arr4, n, mergeSort);
	//TestHelper::print_arr(arr, n);

	delete[] arr;

	system("pause");
	return 0;
}

//#include <iostream>
//#include <string>
//#include <unordered_map>
//int main()
//{
//	std::unordered_map<std::string, std::string> mymap =
//	{
//		{ "house", "maison" },
//		{ "apple", "pomme" },
//		{ "tree", "arbre" },
//		{ "book", "livre" },
//		{ "door", "porte" },
//		{ "grapefruit", "pamplemousse" }
//	};
//	unsigned n = mymap.bucket_count();
//	std::cout << "mymap has " << n << " buckets.\n";
//	for (unsigned i = 0; i < n; ++i)
//	{
//		std::cout << "bucket #" << i << " contains: ";
//		for (auto it = mymap.begin(i); it != mymap.end(i); ++it)
//			std::cout << "[" << it->first << ":" << it->second << "] ";
//		std::cout << "\n";
//	}
//
//	system("pause");
//	return 0;
//}