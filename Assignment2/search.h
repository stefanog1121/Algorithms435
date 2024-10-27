#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

int linearSearch(std::vector<std::string>& a, std::string key);

int binarySearch(std::vector<std::string>& a,int low, int high, std::string key, int comparisons);

#endif
