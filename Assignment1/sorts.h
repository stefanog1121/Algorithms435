#ifndef SORTS_H
#define SORTS_H

#include <vector>

void selectionSort(std::vector<std::string>& A);

void insertionSort(std::vector<std::string>& A);

void merge(std::vector<std::string>& A, int left, int right, int mid, int& comparisons);

void mergeSort(std::vector<std::string>& A, int left, int right, int& comparisons);

void countMergeSort(std::vector<std::string>& A);

int partition(std::vector<std::string>& A, int low, int high, int& comparisons);

void quickSort(std::vector<std::string>& A, int low, int high, int& comparisons);

void countQuickSort(std::vector<std::string>& A);

void shuffle(std::vector<std::string>& A);

#endif