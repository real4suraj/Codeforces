#include <bits/stdc++.h>
using namespace std;
void SCAN(int arr[], int head, string direction, int size = 8, int disk_size = 200)
{
	int seek_count = 0;
	vector<int> left, right;
	if (direction == "left") left.push_back(0);
	else right.push_back(disk_size - 1);
	for (int i = 0; i < size; i++) {
		if (arr[i] < head) left.push_back(arr[i]);
		else right.push_back(arr[i]);
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	for (int i = 0; i < 2; ++i) {
		if (direction == "left") {
			for (int i = left.size() - 1; i >= 0; i--) {
				cout << left[i] << "->";
				seek_count += abs(left[i] - head);
				head = left[i];
			}
			direction = "right";
		}
		else if (direction == "right") {
			for (int i = 0; i < right.size(); i++) {
				cout << right[i] << "->";
				seek_count += abs(right[i] - head);
				head = right[i];
			}
			direction = "left";
		}
	}
	cout << "Total number of seek operations = " << seek_count << endl;
}

int main()
{
	int arr[size] = { 176, 79, 34, 60, 92, 11, 41, 114 }, head = 50;
	string direction = "left";
	SCAN(arr, head, direction);
	return 0;
}
