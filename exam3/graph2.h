#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;

    adjVertex(){};
    adjVertex(vertex* vr, int w) {
        v = vr;
        weight = w;
    }
};

struct vertex {
    int ID;
    std::string name;
    int district = -1;
    bool visited = false;
    int distance;
    std::vector<adjVertex*> adj;

    vertex(){};
    vertex(std::string nameIn) {
        name = nameIn;
    };
};

struct queueVertex {
    int distance;
    std::vector<vertex*> path;

    queueVertex(){};
    queueVertex(int d, std::vector<vertex*> p) {
        distance = d;
        path = p;
    }
};

class Graph {
    protected:
    private:
        int stringToInt(std::string s);

        void addVertex(std::string name);
        void addEdge(std::string v1, std::string v2, int weight);
        vertex* findVertex(std::string name);
        vertex* findVertex(int id);
        void BFTraversalLabel(vertex* start, int distID);
        void setUnvisited();

        std::vector<vertex*> vertices;

    public:
        Graph();
        Graph(char* file);
        virtual ~Graph();

        void printVertices();
        void findDistricts();
        void shortestPath(std::string start, std::string end);

};

#include "Graph.cpp"
#endif // GRAPH_H