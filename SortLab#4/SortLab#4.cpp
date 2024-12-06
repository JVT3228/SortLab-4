#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SortAlgorithms.h"
#include <windows.h>
#include <algorithm> // Для std::shuffle
#include <vector>
#include "SearchAlgorithms.h"

std::vector<std::vector<int>> generateRandomGraph(int nodes, int edges) {
    std::vector<std::vector<int>> graph(nodes);

    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    for (int i = 0; i < edges; ++i) {
        int u = rand() % nodes;
        int v = rand() % nodes;

        // Добавляем ребро, если его нет
        if (u != v && std::find(graph[u].begin(), graph[u].end(), v) == graph[u].end()) {
            graph[u].push_back(v);
            graph[v].push_back(u); // Для неориентированного графа
        }
    }

    return graph;
}

void testGraphAlgorithms() {
    int nodes = 5;
    int edges = 7;

    std::vector<std::vector<int>> graph = generateRandomGraph(nodes, edges);

    std::cout << "Сгенерированный граф (список смежности):\n";
    for (int i = 0; i < graph.size(); ++i) {
        std::cout << i << ": ";
        for (int neighbor : graph[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }

    BFS(graph, 0);

    DFS(graph, 0);
}

void testBinarySearch(int arr[], int size) {
    std::cout << "Введите элемент для поиска: ";
    int target;
    std::cin >> target;

    int index = binarySearch(arr, size, target);

    if (index != -1) {
        std::cout << "Элемент найден на позиции: " << index << "\n";
    }
    else {
        std::cout << "Элемент не найден.\n";
    }
}

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void displayMenu() {
    setConsoleColor(14); // Желтый текст
    std::cout << "Выберите действие:\n";
    setConsoleColor(7); // Белый текст
    std::cout << "1. Пузырьковая сортировка\n";
    std::cout << "2. Шейкерная сортировка\n";
    std::cout << "3. Сортировка расчёской\n";
    std::cout << "4. Сортировка вставками\n";
    std::cout << "5. Сортировка слиянием\n";
    std::cout << "6. Сортировка выбором\n";
    std::cout << "7. Сортировка подсчётом\n";
    std::cout << "8. Быстрая сортировка\n";
    std::cout << "9. Пирамидальная сортировка\n";
    std::cout << "10. Генерация нового массива\n";
    std::cout << "11. Перемешивание текущего массива\n";
    std::cout << "12. Бинарный поиск\n";
    std::cout << "13. Поиск в ширину(BFS) и глубину(DFS) для случайного графа\n";
    std::cout << "0. Выход\n";
}

int getValidatedInput() {
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            setConsoleColor(4); // Красный текст
            std::cout << "Ошибка ввода! Введите число от 0 до 13: ";
            setConsoleColor(7); // Белый текст
        }
        else {
            return choice;
        }
    }
}

void generateNewArray(int*& arr, int& size) {
    std::cout << "Введите размер нового массива: ";
    size = getValidatedInput();
    delete[] arr;
    arr = new int[size];
    std::cout << "Генерация нового массива...\n";
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Генерация случайных чисел от 0 до 99
    }
    std::cout << "Новый массив сгенерирован: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void shuffleArray(int* arr, int size) {
    std::random_shuffle(arr, arr + size);
    std::cout << "Массив перемешан: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    SetConsoleCP(1251);         // Кодировка ввода
    SetConsoleOutputCP(1251);   // Кодировка вывода

    int size = 10;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Генерация случайных чисел от 0 до 99
    }

    std::cout << "Массив: ";
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    int choice;
    do {
        displayMenu();
        std::cout << "Ваш выбор: ";
        choice = getValidatedInput();

        switch (choice) {
        case 1:
            setConsoleColor(12); // Красный текст
            std::cout << "Пузырьковая сортировка\n";
            bubbleSort(arr, size);
            break;
        case 2:
            setConsoleColor(11); // Голубой текст
            std::cout << "Шейкерная сортировка\n";
            shakerSort(arr, size);
            break;
        case 3:
            setConsoleColor(10); // Зеленый текст
            std::cout << "Сортировка расчёской\n";
            combSort(arr, size);
            break;
        case 4:
            setConsoleColor(13); // Фиолетовый текст
            std::cout << "Сортировка вставками\n";
            insertionSort(arr, size);
            break;
        case 5:
            setConsoleColor(9); // Синий текст
            std::cout << "Сортировка слиянием\n";
            mergeSort(arr, size);
            break;
        case 6:
            setConsoleColor(14); // Желтый текст
            std::cout << "Сортировка выбором\n";
            selectionSort(arr, size);
            break;
        case 7:
            setConsoleColor(6); // Коричневый текст
            std::cout << "Сортировка подсчётом\n";
            countingSort(arr, size);
            break;
        case 8:
            setConsoleColor(5); // Пурпурный текст
            std::cout << "Быстрая сортировка\n";
            quickSort(arr, 0, size - 1);
            break;
        case 9:
            setConsoleColor(3); // Бирюзовый текст
            std::cout << "Пирамидальная сортировка\n";
            heapSort(arr, size);
            break;
        case 10:
            generateNewArray(arr, size);
            break;
        case 11:
            shuffleArray(arr, size);
            break;
        case 12:
            std::sort(arr, arr + size);
            testBinarySearch(arr, size);
            break;
        case 13:
            testGraphAlgorithms();
            break;
        case 0:
            setConsoleColor(7); // Белый текст
            std::cout << "Выход...\n";
            break;
        default:
            setConsoleColor(4); // Красный текст
            std::cout << "Неверный выбор. Введите число от 0 до 11.\n";
        }

        if (choice >= 1 && choice <= 9) {
            setConsoleColor(7); // Белый текст
            std::cout << "Результат сортировки: ";
            for (int i = 0; i < size; ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n";
        }

    } while (choice != 0);

    delete[] arr;
    return 0;
}