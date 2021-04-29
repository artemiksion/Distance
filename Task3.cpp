#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct awf
{
	int num;
	int i;
};
void heapify(vector<awf>& arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2; 
	if (l < n && arr[l].num > arr[largest].num)
		largest = l;
	if (r < n && arr[r].num > arr[largest].num)
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(vector<awf>& arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i = i - 1)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i = i - 1)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
int main()
{
	int n;
	int s;
	cin >> n;
	cin >> s;
	vector<awf> b;
	b.reserve(n);
	for (int i = 0; i < n; i = i + 1)
	{
		int num;
		cin >> num;
		awf t;
		t.i = i;
		t.num = num;
		b.push_back(t);
	}
	heapSort(b,n);
	int* mas;
	mas = new int[n];
	int right = 0;
	int left = 0;
	int res = 0;
	for (int j = 0; j < n; j = j + 1)
	{
		for (int k = 0; k < s; k = k + 1)
		{
			if (j + 1 + right == n)
			{
				res += abs(b[j].num - b[j - left - 1].num);
				left+=1;
				continue;
			}
			if (j - left <= 0)
			{
				res += abs(b[j].num - b[j + right + 1].num);
				right+=1;
				continue;
			}
			if (abs(b[j].num - b[j + right + 1].num) <= abs(b[j].num - b[j - left - 1].num))
			{
				res += abs(b[j].num - b[j + right + 1].num);
				right+=1;
			}
			else
			{
				res += abs(b[j].num - b[j - left - 1].num);
				left+=1;
			}
		}
		mas[b[j].i] = res;
		res = 0;
		right = left = 0;
	}
	for (int i = 0; i < n; i = i + 1)
		cout << mas[i] << ' ';
	return 0;
}
