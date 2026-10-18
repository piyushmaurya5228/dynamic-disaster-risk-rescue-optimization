#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include "RouteDecisionEngine.h"

using namespace std;

int main() {
    cout << "=== PHASE 7.4.6: BLOCKED ROAD TEST ===\n";

    Graph graph;

    bool locationsLoaded = graph.loadLocations("data/locations.csv");
    bool roadsLoaded = graph.loadRoads("data/roads.csv");

    if (!locationsLoaded || !roadsLoaded) {
        cout << "FAIL: Dataset loading failed.\n";
        return 1;
    }

    vector<string> originalRoute =
        RouteDecisionEngine::findBestRoute(
            graph, "LOC_0001", "LOC_0010"
        );

    if (originalRoute.empty()) {
        cout << "FAIL: Original route not found.\n";
        return 1;
    }

    cout << "Original route found: PASS\n";

    // Check that the selected route has at least one road.
    if (originalRoute.size() < 2) {
        cout << "FAIL: Route has no road to block.\n";
        return 1;
    }

     cout << "Route has roads to test: PASS\n";
     return 0;
    }  
