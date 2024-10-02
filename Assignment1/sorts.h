#ifndef SORTS_H
#define SORTS_H

#include <vector>

void selectionSort(std::vector<int>& A);

void insertionSort(std::vector<int>& A);

void mergeSort(std::vector<int>& A, int left, int right);

void merge(std::vector<int>& A, int left, int right, int mid);

int quickSort(std::vector<int>& A, int low, int high);

#endif