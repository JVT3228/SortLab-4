#include "SearchAlgorithms.h"
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }

        if (arr[mid] > target) {
            right = mid - 1; 
        }
        else {
            left = mid + 1; 
        }
    }

    return -1; 
}

void BFS(const std::vector<std::vector<int>>& graph, int startNode) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    std::cout << "BFS обход: ";
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        std::cout << currentNode << " ";

        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << "\n";
}

void DFSUtil(const std::vector<std::vector<int>>& graph, int node, std::vector<bool>& visited) {
    visited[node] = true;
    std::cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFSUtil(graph, neighbor, visited);
        }
    }
}

void DFS(const std::vector<std::vector<int>>& graph, int startNode) {
    std::vector<bool> visited(graph.size(), false);
    std::cout << "DFS обход: ";
    DFSUtil(graph, startNode, visited);
    std::cout << "\n";
}