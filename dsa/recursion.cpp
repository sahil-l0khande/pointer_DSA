#include <iostream>
#include <vector>
using namespace std;
class Search{
	private:
		vector<int> arr;
		int start;
		int end;
		int mid;
		int search_index;

	public:
		//Search(vector<int> _arr, int _start, int _end) : arr(_arr) , start(_start), end(_end), search(_search) {

		//}

		Search(){

		}


		int bin_search(vector<int> arr, int start, int end, int search);
		void test_bin_search(void);

};

int Search::bin_search(vector<int> arr, int start, int end, int element)
{
	int mid;

	if(start <= end)
	{
		mid = (start+end)/2;
		if(arr[mid] == element)
			return (mid);
		else if(arr[mid] > element)
			return bin_search(arr, start, mid-1, element);
		else if(arr[mid] < element)
			return bin_search(arr, mid+1, end, element);
	}

	return (-1);
}

void Search::test_bin_search(void)
{
	arr = {10, 20, 30 , 40, 50, 60, 70, 80};
	vector<int> elements = {
		10, 15, 20, -40, 30, 40,
		50, 55, 60, 66, 70, 80
	};


	int i;
	for(i = 0; i < elements.size(); ++i)
	{
		search_index = bin_search(arr, 0, arr.size()-1, elements[i]);
		if(search_index == -1)
			printf("%d is not found in arr \n", elements[i]);
		else
			printf("%d found at index %d\n", elements[i], search_index);
	}	

}

int main(void)
{
	Search B;

	B.test_bin_search();

	return 0;
}
