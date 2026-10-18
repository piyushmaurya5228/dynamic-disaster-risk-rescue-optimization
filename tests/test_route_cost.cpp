#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include "RouteDecisionEngine.h"

using namespace std;

int main() {
    cout << "=== PHASE 7.4.8: ROUTE COST TEST ===\n";

    Graph graph;

    bool locationsLoaded = graph.loadLocations("data/locations.csv");
    bool roadsLoaded = graph.loadRoads("data/roads.csv");

    if (!locationsLoaded || !roadsLoaded) {
        cout << "FAIL: Dataset loading failed.\n";
        return 1;
    }

    vector<string> route =
        RouteDecisionEngine::findBestRoute(
            graph, "LOC_0001", "LOC_0010"
        );

    if (route.empty()) {
        cout << "FAIL: Route not found.\n";
        return 1;
    }

    double cost = RouteDecisionEngine::getRouteCost(graph, route);

    cout << "Route found: PASS\n";
    cout << "Route cost: " << cost << endl;

    bool validCost = cost >= 0.0;
    cout << "Route cost is non-negative: "
         << (validCost ? "PASS" : "FAIL") << endl;

    cout << "=== ROUTE COST TEST: "
         << (validCost ? "PASSED" : "FAILED") << " ===\n";

    return validCost ? 0 : 1;
}
