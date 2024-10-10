#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void fillvector(vector<int> &, int size);
int getTarget(const vector<int>&);
int binSearch(const vector<int>&, int, int &);
int binSearch_recur(const vector<int>&, int, int, int, int &);
int LinearSearch(const vector<int>&, int, int &);
void print(const vector<int>&);

void fillvector(vector<int> &numbers, int N) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < N; i++)
        numbers.push_back(rand() % 1000);
}

int getTarget(const vector<int> &numbers) {
    int index = rand() % numbers.size();
    return numbers[index];
}

int LinearSearch(const vector<int> &numbers, int target, int &cmpcnt) {
    for (int i = 0; i < numbers.size(); i++) {
        cmpcnt++;
        if (numbers[i] == target) {
            return i;
        }
    }
    return -1;
}

int binSearch(const vector<int> &numbers, int target, int &cmpcnt) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right) {
        cmpcnt++;
        int mid = left + (right - left) / 2;

        if (numbers[mid] == target) {
            return mid;
        } else if (numbers[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int binSearch_recur(const vector<int> &numbers, int target, int start, int end, int &cmpcnt) {
    if (start > end) {
        return -1;
    }

    cmpcnt++;
    int mid = start + (end - start) / 2;

    if (numbers[mid] == target) {
        return mid;
    } else if (numbers[mid] < target) {
        return binSearch_recur(numbers, target, mid + 1, end, cmpcnt);
    } else {
        return binSearch_recur(numbers, target, start, mid - 1, cmpcnt);
    }
}

void print(const vector<int> &numbers) {
    for (auto v : numbers)
        cout << v << "\t";
    cout << endl;
}