#include "Graph.h"

//all these test added
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

Graph::Graph(char* file) {
    std::ifstream in;
    std::string line;
    std::string word;
    std::string name;
    bool add;
    int dist,i,j;

    in.open(file);
    if (in.good()) {
        std::getline(in,line);
        std::stringstream ss(line);
        std::getline(ss,word,',');
        while (std::getline(ss,word,',')) {
            Graph::addVertex(word);
        }

        while (std::getline(in,line)) {
            std::stringstream ss(line);
            std::getline(ss,name,',');
            j = 0;
            add = false;
            while (std::getline(ss,word,',')) {
                dist = Graph::stringToInt(word);
                if (dist > 0) {
                    if (add) {
                        Graph::addEdge(name, Graph::vertices[j]->name, dist);
                    }
                }
                if (dist == 0) {
                    add = true;
                }
                j++;
            }
            i++;

        }
    }
}

Graph::~Graph() {

}

int Graph::stringToInt(std::string s) {
    std::stringstream ss(s);
    int i;
    ss>>i;
    return i;
}

void Graph::addVertex(std::string name) {
    Graph::vertices.push_back(new vertex(name));

}

void Graph::addEdge(std::string v1, std::string v2, int weight) {
    vertex* city1 = Graph::findVertex(v1);
    vertex* city2 = Graph::findVertex(v2);
    if (city1 == NULL || city2 == NULL) {
        return;
    }
    city1->adj.push_back(new adjVertex(city2, weight));
    city2->adj.push_back(new adjVertex(city1, weight));
}

vertex* Graph::findVertex(std::string name) {
    int i=0;
    while (i<Graph::vertices.size()) {
        if (name.compare(Graph::vertices[i]->name) == 0) {
            return Graph::vertices[i];
        }
        i++;
    }
    return NULL;
}


void Graph::BFTraversalLabel(vertex* start, int distID) {
    std::queue<vertex*> Q;
    vertex* city;
    int i;

    Q.push(start);
    while (!Q.empty()) {
        city = Q.front();
        Q.pop();
        city->district = distID;
        i=0;
        while (i<city->adj.size()) {
            if (city->adj[i]->v->district == -1){
                Q.push(city->adj[i]->v);
            }
            i++;
        }
    }
}

void Graph::setUnvisited() {
    int i=0;
    while (i<Graph::vertices.size()) {
        Graph::vertices[i]->visited = false;
        i++;
    }
}


void Graph::printVertices() {
    int i=0;
    int j;
    while (i<Graph::vertices.size()) {
        std::cout<<Graph::vertices[i]->district<<":"<<Graph::vertices[i]->name<<"-->";
        j=0;
        int size = Graph::vertices[i]->adj.size();
        while (j<size-1) {
            std::cout<<vertices[i]->adj[j]->v->name;
            std::cout<<"***";
            j++;
        }
        std::cout<<vertices[i]->adj[j]->v->name;
        std::cout<<std::endl;
        i++;
    }

}

void Graph::findDistricts() {
    int i=0;
    int j=1;
    while (i<Graph::vertices.size()) {
        if (Graph::vertices[i]->district == -1) {
            Graph::BFTraversalLabel(Graph::vertices[i], j);
            j++;
        }
        i++;
    }
}


void Graph::shortestPath(std::string start, std::string end) {
    Graph::setUnvisited(); //reset
    vertex* v1 = Graph::findVertex(start);
    vertex* v2 = Graph::findVertex(end);
    if (!v1 || !v2) {
        std::cout<<"One or more cities doesn't exist"<<std::endl;
        return;
    }
    if (v1->district != v2->district) {
        std::cout<<"No safe path between cities"<<std::endl;
        return;
    }
    if (v1->district == -1) {
        std::cout<<"Please identify the districts before checking distances"<<std::endl;
        return;
    }

    std::queue<queueVertex*> Q;
    std::vector<queueVertex*> paths;
    queueVertex* c;
    queueVertex* m;
    std::vector<vertex*> path;
    int i;

    path.push_back(v1);
    Q.push(new queueVertex(0, path));
    while (!Q.empty()) {
        c = Q.front();
        Q.pop();
        c->path.back()->visited = true;
        if (c->path.back() == v2) {
            paths.push_back(c);
        }
        i=0;
        while (i<c->path.back()->adj.size()) {
            if (!(c->path.back()->adj[i]->v->visited)) {
                path = c->path;
                path.push_back(c->path.back()->adj[i]->v);
                Q.push(new queueVertex(c->distance + 1, path));
            }
            i++;
        }
    }

    int minLength = 10000;
    queueVertex* shortest;
    for (i=0; i<paths.size(); i++) {
        if (paths[i]->distance < minLength) {
            minLength = paths[i]->distance;
            shortest = paths[i];
        }
    }
    std::cout<<minLength;
    for (i=0; i<shortest->path.size(); i++) {
        std::cout<<","<<shortest->path[i]->name;
    }
    std::cout<<std::endl;
    Graph::setUnvisited(); //reset
}