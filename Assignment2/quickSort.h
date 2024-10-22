#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

int partition(std::vector<std::string>& A, int low, int high, int& comparisons);

void quickSort(std::vector<std::string>& A, int low, int high, int& comparisons);

std::string makeLower(std::string s);

#endif