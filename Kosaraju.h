/*
Kosaraju algorithm for finding Strong components of graph and building a new graph
*/

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template <class G, class V>
void dfs(G& graph, V& topsort, V& used, int v) { // topsort - after execution, reverse
   used[v] = true;
   for (auto& nxt : graph[v]) {
       if (used[nxt] == false) {
            dfs(graph, topsort, used, nxt);
       }
   }
   topsort.push_back(v);
}   


template <class G, class RG, class V>    // RG - reversed graph
void unite(G& result_graph, RG& rev_graph, V& colors, int v, int c) {
    colors[v] = c;
    for (auto& nxt : rev_graph[v]) {
        if (colors[nxt] == 0) {   // TODO: base color
            unite(result_graph, rev_graph, colors, nxt, c);
        } else if (colors[nxt] != c) {
            result_graph[colors[nxt]].push_back(v); // colors[nxt] first, because we have reversed graph
        }
    }
}

/*

main() {
    std::vector<int> topsort(n);
    std::vector<int> used(n);

    // g, reversed_g
    
    for (int v = 0; v < n; ++v) {
        if (used[v] == false) {
            dfs(topsort, used, v);
        }
    }
    std::reverse(topsort.begin(), topsort.end());


    // result graph
    std::vector<int> colors(n, 0);  // TODO: base color
    
    int current_color = 1;
    for (int v = 0; v < n; ++v) {
        if (colors[v] == 0) {
            unite(result_graph, reversed_g, colors, v, current_color++);
        }
    }


}

*/
