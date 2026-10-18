#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include "RouteDecisionEngine.h"

using namespace std;

int main() {
    cout << "=== PHASE 7.4.7: UNREACHABLE ROUTE TEST ===\n";

    Graph graph;

    bool locationsLoaded = graph.loadLocations("data/locations.csv");
    bool roadsLoaded = graph.loadRoads("data/roads.csv");

    if (!locationsLoaded || !roadsLoaded) {
        cout << "FAIL: Dataset loading failed.\n";
        return 1;
    }

    cout << "Locations loaded: PASS\n";
    cout << "Roads loaded: PASS\n";

    vector<string> route =
        RouteDecisionEngine::findBestRoute(
            graph, "LOC_0001", "LOC_9999"
        );

    bool unreachableHandled = route.empty();

    cout << "Unreachable destination handled: "
         << (unreachableHandled ? "PASS" : "FAIL") << endl;

    cout << "=== UNREACHABLE ROUTE TEST: "
         << (unreachableHandled ? "PASSED" : "FAILED")
         << " ===\n";

    return unreachableHandled ? 0 : 1;
}
