#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

// Структура для представления графа
struct Graph {
    std::unordered_map<std::string, std::vector<std::string>> adjList;

    // Функция для добавления ребра в граф
    void addEdge(const std::string& src, const std::string& dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Поскольку граф неориентированный
    }
};

// Функция для выполнения поиска в ширину (BFS)
std::vector<std::string> bfs(const Graph& g, const std::string& start, const std::string& goal) {
    std::queue<std::string> q;
    std::unordered_map<std::string, std::string> parent;
    std::unordered_map<std::string, bool> visited;

    q.push(start);
    visited[start] = true;
    parent[start] = "";

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        if (current == goal) {
            // Восстановление пути
            std::vector<std::string> path;
            for (std::string at = goal; at != ""; at = parent[at]) {
                path.push_back(at);
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const std::string& neighbor : g.adjList.at(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    // Если путь не найден
    return {};
}

int main() {
    // Создание графа лабиринта
    Graph g;
    g.addEdge("S", "A");
    g.addEdge("S", "B");
    g.addEdge("A", "C");
    g.addEdge("B", "D");
    g.addEdge("C", "E");
    g.addEdge("D", "F");
    g.addEdge("E", "I");
    g.addEdge("F", "G");
    g.addEdge("G", "H");
    g.addEdge("H", "I");

    // Поиск кратчайшего пути от "S" до "I"
    std::vector<std::string> path = bfs(g, "S", "I");

    if (!path.empty()) {
        std::cout << "Кратчайший путь от S до I: ";
        for (const std::string& room : path) {
            std::cout << room << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Путь не найден." << std::endl;
    }

    return 0;
}
