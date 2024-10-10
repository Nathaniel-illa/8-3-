#include "main.hpp"

int main()
{
	int N = 1000;
	int cmpcnt, target, idx;
	vector<int> numbers, copied;
	fillvector(numbers, N);
	copied = numbers;
	print(numbers);

	sort(numbers.begin(), numbers.end());
	target = getTarget(numbers);

	cmpcnt = 0;
	auto start = high_resolution_clock::now();
	idx = LinearSearch(numbers, target, cmpcnt);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);

	cout << "Found the target " << target << " at the index " << idx << endl;
	cout << "The Linear Search comparison count " << cmpcnt << endl;
	cout << "The elappsed time  " << duration.count() << endl;

	cmpcnt = 0;
	start = high_resolution_clock::now();
	idx = binSearch(numbers, target, cmpcnt);
	stop = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(stop - start);

	cout << "Found the target " << target << " at the index " << idx << endl;
	cout << "The Binary Search comparison count " << cmpcnt << endl;
	cout << "The elappsed time  " << duration.count() << endl;

	cmpcnt = 0;
	start = high_resolution_clock::now();
	idx = binSearch_recur(numbers, target, 0, numbers.size() - 1, cmpcnt);
	stop = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(stop - start);

	cout << "Found the target " << target << " at the index " << idx << endl;
	cout << "The Recursive Binary Search comparison count " << cmpcnt << endl;
	cout << "The elappsed time  " << duration.count() << endl;
}
