#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

int linearSearch(std::vector<std::string>& a, std::string key);

int binarySearch(std::vector<std::string>& a,int low, int high, std::string key, int comparisons);

void linearGetItems(std::vector<std::string>& list, std::vector<std::string>& items);

void binaryGetItems(std::vector<std::string>& list, std::vector<std::string>& items);
#endif
