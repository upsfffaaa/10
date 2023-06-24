#include <iostream>
#include <thread>
#include <vector>

class MergeSort {
public:
    void Sort(std::vector<int>& arr) {
        if (arr.size() > 1) {
            std::vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
            std::vector<int> right(arr.begin() + arr.size() / 2, arr.end());

            Sort(left);
            Sort(right);

            Merge(left, right, arr);
        }
    }

private:
    void Merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& arr) {
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left.size()) {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (j < right.size()) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
};

int main() {
    const int SIZE = 10;
    std::vector<int> arr(SIZE);

    std::cout << "Enter " << SIZE << " integers to sort: ";
    for (int i = 0; i < SIZE; i++) {
        std::cin >> arr[i];
    }

    MergeSort msort;

    auto sort_func = [&msort](std::vector<int>& arr) { msort.Sort(arr); };

    std::thread t(sort_func, std::ref(arr));
    t.join();

    std::cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}