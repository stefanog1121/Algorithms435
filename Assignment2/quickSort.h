#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

int partition(std::vector<std::string>& A, int low, int high);

void quickSort(std::vector<std::string>& A, int low, int high);

std::string makeLower(std::string s);

#endif