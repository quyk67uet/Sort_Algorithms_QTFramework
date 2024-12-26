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

        steps += "Step (Merge [" + QString::number(left) + ", " +
                 QString::number(mid) + ", " + QString::number(right) + "]): ";
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

        steps += "Step (Partition at index " + QString::number(pi) + "): ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";

        steps += quickSortWithSteps(arr, low, pi - 1);
        steps += quickSortWithSteps(arr, pi + 1, high);
    }
    return steps;
}


// Hàm phụ trợ để xây dựng và điều chỉnh heap
void heapifyWithSteps(std::vector<int>& arr, int n, int i, QString& steps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Tìm phần tử lớn nhất trong gốc và các nút con
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu gốc không phải lớn nhất, hoán đổi và điều chỉnh tiếp
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // In trạng thái sau mỗi lần hoán đổi trong heapify
        steps += "Heapify: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";

        heapifyWithSteps(arr, n, largest, steps);
    }
}

// Heap Sort chính
QString heapSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int n = arr.size();

    // Xây dựng max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyWithSteps(arr, n, i, steps);
    }

    steps += "Initial Max-Heap: ";
    for (int num : arr) {
        steps += QString::number(num) + " ";
    }
    steps += "\n";

    // Trích xuất từng phần tử từ heap
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);  // Đưa phần tử lớn nhất về cuối
        steps += "Extract Max: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";

        // Điều chỉnh lại heap
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

            // In trạng thái sau mỗi lần hoán đổi
            steps += "Gap " + QString::number(gap) + ": ";
            for (int num : arr) {
                steps += QString::number(num) + " ";
            }
            steps += "\n";
        }
    }

    return steps;
}


int getMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (int num : arr) {
        if (num > max) max = num;
    }
    return max;
}
// Hàm phụ trợ: Counting Sort cho Radix Sort
void countingSortForRadixWithSteps(std::vector<int>& arr, int exp, QString& steps) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    // Đếm số lần xuất hiện của mỗi chữ số
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Cộng dồn để xác định vị trí
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Xây dựng mảng kết quả
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Sao chép mảng kết quả về mảng ban đầu
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // In trạng thái sau mỗi lần sắp xếp theo chữ số
    steps += "After sorting by digit (exp " + QString::number(exp) + "): ";
    for (int num : arr) {
        steps += QString::number(num) + " ";
    }
    steps += "\n";
}

// Radix Sort chính
QString radixSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int max = getMax(arr);

    // Thực hiện Counting Sort cho từng chữ số (đơn vị, chục, trăm...)
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

    // Đếm số lần xuất hiện
    for (int num : arr) {
        count[num - min]++;
    }

    steps += "Count array: ";
    for (int c : count) {
        steps += QString::number(c) + " ";
    }
    steps += "\n";

    // Cộng dồn
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Sắp xếp
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    steps += "Sorted array: ";
    for (int num : output) {
        steps += QString::number(num) + " ";
    }
    steps += "\n";

    arr = output;  // Cập nhật mảng ban đầu
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

    // Phân phối phần tử vào các bucket
    for (int num : arr) {
        buckets[(num - min) / bucketRange].push_back(num);
    }

    // Hiển thị trạng thái các bucket
    for (size_t i = 0; i < buckets.size(); i++) {
        steps += "Bucket " + QString::number(i) + ": ";
        for (int num : buckets[i]) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }

    // Hợp nhất các bucket
    arr.clear();
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        for (int num : bucket) {
            arr.push_back(num);
        }

        // In trạng thái sau mỗi lần hợp nhất
        steps += "After merging bucket: ";
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

    // Sắp xếp từng đoạn "run"
    for (int i = 0; i < n; i += RUN) {
        insertionSortForTim(arr, i, std::min(i + RUN - 1, n - 1));
        steps += "Run sorted [" + QString::number(i) + "]: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }

    // Hợp nhất các "run"
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);
            mergeForTim(arr, left, mid, right);

            steps += "Merged [" + QString::number(left) + " to " + QString::number(right) + "]: ";
            for (int num : arr) {
                steps += QString::number(num) + " ";
            }
            steps += "\n";
        }
    }

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

        steps += "Gap " + QString::number(gap) + ": ";
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

            // In trạng thái sau mỗi lần hoán đổi
            steps += "Gnome Swap: ";
            for (int num : arr) {
                steps += QString::number(num) + " ";
            }
            steps += "\n";
        }
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

    // Đếm số lần xuất hiện
    for (int num : arr) {
        holes[num - min]++;
    }

    steps += "Holes filled: ";
    for (int h : holes) {
        steps += QString::number(h) + " ";
    }
    steps += "\n";

    // Đặt phần tử về mảng
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (holes[i]-- > 0) {
            arr[index++] = i + min;

            // In trạng thái sau mỗi lần đặt phần tử
            steps += "Placed " + QString::number(i + min) + ": ";
            for (int num : arr) {
                steps += QString::number(num) + " ";
            }
            steps += "\n";
        }
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

        // Tìm vị trí chính xác của item
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) pos++;
        }

        // Nếu item đã ở đúng vị trí
        if (pos == cycle_start) continue;

        // Bỏ qua các phần tử trùng lặp
        while (item == arr[pos]) pos++;

        // Hoán đổi item với phần tử tại pos
        std::swap(item, arr[pos]);

        // Lặp lại cho đến khi item trở về vị trí ban đầu
        while (pos != cycle_start) {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) pos++;
            }
            while (item == arr[pos]) pos++;
            std::swap(item, arr[pos]);
        }

        // In trạng thái mảng sau mỗi chu kỳ
        steps += "After completing cycle starting at index " + QString::number(cycle_start) + ": ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }

    return steps;
}

QString oddEvenSortWithSteps(std::vector<int>& arr) {
    QString steps;
    int n = arr.size();
    bool sorted = false;

    while (!sorted) {
        sorted = true;

        // So sánh các cặp phần tử ở vị trí chẵn
        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        steps += "Even pass: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";

        // So sánh các cặp phần tử ở vị trí lẻ
        for (int i = 1; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        steps += "Odd pass: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }

    return steps;
}

void bitonicMerge(std::vector<int>& arr, int low, int cnt, bool ascending, QString& steps) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) {
            if ((arr[i] > arr[i + k]) == ascending) {
                std::swap(arr[i], arr[i + k]);
            }
        }
        bitonicMerge(arr, low, k, ascending, steps);
        bitonicMerge(arr, low + k, k, ascending, steps);
    }
}

void bitonicSortHelper(std::vector<int>& arr, int low, int cnt, bool ascending, QString& steps) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonicSortHelper(arr, low, k, true, steps);
        bitonicSortHelper(arr, low + k, k, false, steps);
        bitonicMerge(arr, low, cnt, ascending, steps);
        steps += "Bitonic merge: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }
}

QString bitonicSortWithSteps(std::vector<int>& arr) {
    QString steps;
    bitonicSortHelper(arr, 0, arr.size(), true, steps);
    return steps;
}

int findMaxIndex(const std::vector<int>& arr, int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

QString pancakeSortWithSteps(std::vector<int>& arr) {
    QString steps;
    for (int curr_size = arr.size(); curr_size > 1; curr_size--) {
        int maxIdx = findMaxIndex(arr, curr_size);

        if (maxIdx != curr_size - 1) {
            std::reverse(arr.begin(), arr.begin() + maxIdx + 1);
            steps += "Flip at index " + QString::number(maxIdx) + ": ";
            for (int num : arr) {
                steps += QString::number(num) + " ";
            }
            steps += "\n";

            std::reverse(arr.begin(), arr.begin() + curr_size);
            steps += "Flip at size " + QString::number(curr_size) + ": ";
            for (int num : arr) {
                steps += QString::number(num) + " ";
            }
            steps += "\n";
        }
    }
    return steps;
}


QString cocktailShakerSortWithSteps(std::vector<int>& arr) {
    QString steps;
    bool swapped = true;
    int start = 0, end = arr.size() - 1;

    while (swapped) {
        swapped = false;

        // Đi từ trái sang phải
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        steps += "Left pass: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";

        if (!swapped) break;

        swapped = false;
        --end;

        // Đi từ phải sang trái
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        steps += "Right pass: ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";

        ++start;
    }

    return steps;
}


void stoogeSortHelper(std::vector<int>& arr, int l, int h, QString& steps) {
    if (l >= h) return;

    if (arr[l] > arr[h]) {
        std::swap(arr[l], arr[h]);
        steps += "Swap at indexes " + QString::number(l) + " and " + QString::number(h) + ": ";
        for (int num : arr) {
            steps += QString::number(num) + " ";
        }
        steps += "\n";
    }

    if (h - l + 1 > 2) {
        int t = (h - l + 1) / 3;
        stoogeSortHelper(arr, l, h - t, steps);
        stoogeSortHelper(arr, l + t, h, steps);
        stoogeSortHelper(arr, l, h - t, steps);
    }
}

QString stoogeSortWithSteps(std::vector<int>& arr) {
    QString steps;
    stoogeSortHelper(arr, 0, arr.size() - 1, steps);
    return steps;
}


