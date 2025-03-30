#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Структура для представления ребра графа
struct Edge {
    int to;
    int cost;
};

// Функция для выполнения алгоритма Дейкстры
int dijkstra(int N, const vector<int>& fuelCosts, const vector<vector<Edge>>& graph) {
    vector<int> dist(N, INT_MAX); // Вектор для хранения минимальных стоимостей пути до каждого города
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Очередь с приоритетом для выбора минимального пути

    dist[0] = 0; // Начальная стоимость пути из первого города равна 0
    pq.push({ 0, 0 }); // Начинаем с первого города

    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        // Если текущая стоимость больше, чем минимальная известная стоимость, пропускаем
        if (currentDist > dist[u]) continue;

        // Проходим по всем смежным вершинам
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int newDist = currentDist + fuelCosts[u];

            // Если найден более короткий путь до города v
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({ newDist, v });
            }
        }
    }

    // Если путь до последнего города не найден, возвращаем -1
    return (dist[N - 1] == INT_MAX) ? -1 : dist[N - 1];
}

int main() {
    int N;
    cin >> N;
    vector<int> fuelCosts(N);
    for (int i = 0; i < N; ++i) {
        cin >> fuelCosts[i];
    }

    int M;
    cin >> M;
    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v; // Переводим номера городов в нумерацию с нуля
        graph[u].push_back({ v, fuelCosts[u] });
        graph[v].push_back({ u, fuelCosts[v] });
    }

    int result = dijkstra(N, fuelCosts, graph);
    cout << result << endl;

    return 0;
}
