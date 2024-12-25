#include "sorting_algorithms.h"
#include <QString>
#include <vector>
#include <algorithm>

// Insertion Sort
QString insertionSortWithSteps(std::vector<int>& arr) {
    QString steps;
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        steps += "Step " + QString::number(i) + ": ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
    return steps;
}

// Selection Sort
QString selectionSortWithSteps(std::vector<int>& arr) {
    QString steps;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
        steps += "Step " + QString::number(i + 1) + ": ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
    return steps;
}

// Bubble Sort
QString bubbleSortWithSteps(std::vector<int>& arr) {
    QString steps;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
        steps += "Step " + QString::number(i + 1) + ": ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
    return steps;
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Merge Sort
QString mergeSortWithSteps(std::vector<int>& arr, int left, int right) {
    QString steps;
    if (left < right) {
        int mid = left + (right - left) / 2;
        steps += mergeSortWithSteps(arr, left, mid);
        steps += mergeSortWithSteps(arr, mid + 1, right);
        merge(arr, left, mid, right);
        steps += "Step: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
    return steps;
}

int partitionWithSteps(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort
QString quickSortWithSteps(std::vector<int>& arr, int low, int high) {
    QString steps;
    if (low < high) {
        int pi = partitionWithSteps(arr, low, high);
        steps += quickSortWithSteps(arr, low, pi - 1);
        steps += quickSortWithSteps(arr, pi + 1, high);
    }
    return steps;
}

void heapifyWithSteps(std::vector<int>& arr, int n, int i, QString& steps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapifyWithSteps(arr, n, largest, steps);
    }
}

// Heap Sort
QString heapSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyWithSteps(arr, n, i, steps);
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        steps += "Step: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
        heapifyWithSteps(arr, i, 0, steps);
    }
    return steps;
}

// Shell Sort
QString shellSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
            steps += "Step: ";
            for (int num : arr) {
                steps += QString::number(num) + " ";
            }
            steps += "\n";
        }
    }
    return steps;
}

void countingSortForRadixWithSteps(std::vector<int>& arr, int exp, QString& steps) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    steps += "Step: ";
    for (int num : arr) {
        steps += QString::number(num) + " ";
    }
    steps += "\n";
}

int getMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (int num : arr) {
        if (num > max) max = num;
    }
    return max;
}

// Radix Sort
QString radixSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortForRadixWithSteps(arr, exp, steps);
    }
    return steps;
}

// Counting Sort
QString countingSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    std::vector<int> count(range), output(arr.size());
    for (int num : arr) {
        count[num - min]++;
    }
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    arr = output;
    steps += "Step: ";
    for (int num : arr) {
        steps += QString::number(num) + " ";
    }
    steps += "\n";
    return steps;
}

// Bucket Sort
QString bucketSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int n = arr.size();
    if (n <= 0) return steps;
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int bucketRange = (max - min) / n + 1;
    std::vector<std::vector<int>> buckets(n);
    for (int num : arr) {
        buckets[(num - min) / bucketRange].push_back(num);
    }
    arr.clear();
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        for (int num : bucket) {
            arr.push_back(num);
        }
        steps += "Step: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
    return steps;
}

void mergeForTim(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int>::size_type left_size = m - l + 1;
    std::vector<int>::size_type right_size = r - m;
    std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    std::vector<int>::size_type i = 0, j = 0;
    int k = l;
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left_size) arr[k++] = left[i++];
    while (j < right_size) arr[k++] = right[j++];
}

void insertionSortForTim(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Tim Sort
const int RUN = 32;

QString timSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int n = arr.size();
    for (int i = 0; i < n; i += RUN) {
        insertionSortForTim(arr, i, std::min(i + RUN - 1, n - 1));
    }
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);
            mergeForTim(arr, left, mid, right);
        }
    }
    steps += "Step: ";
    for (int num : arr) {
        steps += QString::number(num) + " ";
    }
    steps += "\n";
    return steps;
}

// Comb Sort
QString combSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int n = arr.size();
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        swapped = false;
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
        steps += "Step: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
    return steps;
}

// Gnome Sort
QString gnomeSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int n = arr.size();
    int index = 0;
    while (index < n) {
        if (index == 0 || arr[index] >= arr[index - 1]) {
            index++;
        } else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
        steps += "Step: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
    return steps;
}

// Pigeonhole Sort
QString pigeonholeSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int min = *min_element(arr.begin(), arr.end());
    int max = *max_element(arr.begin(), arr.end());
    int range = max - min + 1;
    std::vector<int> holes(range, 0);
    for (int num : arr) {
        holes[num - min]++;
    }
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (holes[i]-- > 0) {
            arr[index++] = i + min;
        }
        steps += "Step: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
    return steps;
}

// Cycle Sort
QString cycleSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int n = arr.size();
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) pos++;
        }
        if (pos == cycle_start) continue;
        while (item == arr[pos]) pos++;
        std::swap(item, arr[pos]);
        while (pos != cycle_start) {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) pos++;
            }
            while (item == arr[pos]) pos++;
            std::swap(item, arr[pos]);
        }
        steps += "Step: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
    return steps;
}
