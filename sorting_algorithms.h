#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <QString>

QString insertionSortWithSteps(std::vector<int>& arr);
QString selectionSortWithSteps(std::vector<int>& arr);
QString bubbleSortWithSteps(std::vector<int>& arr);
QString mergeSortWithSteps(std::vector<int>& arr, int left, int right);
QString quickSortWithSteps(std::vector<int>& arr, int low, int high);
QString heapSortWithSteps(std::vector<int>& arr);
QString shellSortWithSteps(std::vector<int>& arr);
QString radixSortWithSteps(std::vector<int>& arr);
QString countingSortWithSteps(std::vector<int>& arr);
QString bucketSortWithSteps(std::vector<int>& arr);
QString timSortWithSteps(std::vector<int>& arr);
QString combSortWithSteps(std::vector<int>& arr);
QString gnomeSortWithSteps(std::vector<int>& arr);
QString pigeonholeSortWithSteps(std::vector<int>& arr);
QString cycleSortWithSteps(std::vector<int>& arr);

#endif // SORTING_ALGORITHMS_H
