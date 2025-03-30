#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Функция, которая находит кратчайшее расстояние между двумя вершинами
int dijkstra(const vector<vector<int>>& graph, int start, int finish) {
    // Инициализируем вектор расстояний от начальной вершины до всех остальных
    vector<int> distances(graph.size(), INT_MAX);
    // Расстояние от начальной вершины до самой себя равно 0
    distances[start] = 0;

    // Создаем очередь приоритетов, где будем хранить пары (расстояние, вершина)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Добавляем начальную вершину в очередь приоритетов
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        // Извлекаем из очереди вершину с минимальным расстоянием
        int curr = pq.top().second;
        pq.pop();

        // Если это конечная вершина, возвращаем найденное расстояние
        if (curr == finish) {
            return distances[curr];
        }

        // Перебираем все соседние вершины текущей вершины
        for (int i = 0; i < graph.size(); i++) {
            // Если существует ребро между текущей и i-ой вершинами
            if (graph[curr][i] != -1) {
                // Вычисляем расстояние от начальной вершины до i-ой вершины
                // через текущую вершину
                int new_distance = distances[curr] + graph[curr][i];
                // Если это расстояние меньше, чем уже сохраненное, обновляем его
                if (new_distance < distances[i]) {
                    distances[i] = new_distance;
                    // Добавляем i-ую вершину в очередь приоритетов
                    pq.push(make_pair(new_distance, i));
                }
            }
        }
    }

    // Если мы дошли до этого места, значит пути между вершинами не существует
    return -1;
}

int main() {
    // Читаем входные данные

    int N, S, F;
    cin >> N >> S >> F;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    // Вызываем функцию, которая находит кратчайшее расстояние
    int distance = dijkstra(graph, S - 1, F - 1);
    
    // Выводим результат
    cout << distance << endl;

    return 0;
}
