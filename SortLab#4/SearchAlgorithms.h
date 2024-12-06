#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <vector>

int binarySearch(int arr[], int size, int target);
void BFS(const std::vector<std::vector<int>>&graph, int startNode);
void DFS(const std::vector<std::vector<int>>& graph, int startNode);

#endif // SEARCH_ALGORITHMS_H