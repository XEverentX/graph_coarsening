// Copyright [year] <Copyright Owner>
#include "../../pch/include/precomp.h"

std::vector <int> vertexes_eccentricity(const CSR& graph) {
    std::vector <std::vector <int>> matrix;
    floyd_warshall(&matrix, graph);
    std::vector <int> ecc(graph.n, 0);
    for (unsigned i = 0; i < matrix.size(); ++i)
        for (unsigned j = 0; j < matrix[i].size(); ++j)
            ecc[i] = std::max(ecc[i], matrix[i][j]);
    return ecc;
}

int graph_radius(const CSR& graph) {
    std::vector <int> ecc = vertexes_eccentricity(graph);
    int rad = 200000;
    for (int e : ecc)
        rad = std::min(rad, e);
    return rad;
}

int graph_diameter(const CSR& graph) {
    std::vector <int> ecc = vertexes_eccentricity(graph);
    int diam = 0;
    for (int e : ecc)
        diam = std::max(diam, e);
    return diam;
}