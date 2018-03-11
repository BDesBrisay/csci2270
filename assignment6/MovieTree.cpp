#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

MovieTree::MovieTree() {
    root = nullptr;
}

MovieTree::~MovieTree() {

}

void MovieTree::printMovieInventory() {
    printMovieInventory(root);
}

int MovieTree::countMovieNodes() {

}

void MovieTree::deleteMovieNode(std::string title) {
    if (root == NULL) return;

    MovieNodeBST* rightNode = searchBST(root, title);
    if (rightNode != NULL) {
        if (rightNode->head->next == nullptr) {
            cout << "One node in linked list" << endl;
        } else {
            cout << "Multiple node in linked list" << endl;
        }
    } else {
        cout << "Movie not found." << endl;
    }
}

MovieNodeLL* addMovieLLNodeHelper(MovieNodeLL* head, MovieNodeLL* movieNode) {
    if (head == nullptr) {
        head = movieNode;
    } else {
        MovieNodeLL* place = head;
        if (place->title > movieNode->title) {
            MovieNodeLL* temp = place;
            movieNode->next = temp;
            head = movieNode;
            return head;
        }
        while (place->next != nullptr) {
            if (place->next->title > movieNode->title) {
                MovieNodeLL* temp = place->next;
                movieNode->next = temp;
                place->next = movieNode;
                return head;
            }
            place = place->next;
        }
        place->next = movieNode;
    }
    return head;
}

MovieNodeBST* addMovieBSTNodeHelper(MovieNodeBST* node, MovieNodeLL* movieNode) {
    char letter = movieNode->title[0];
    if (node == NULL) {
        MovieNodeBST* newNode = new MovieNodeBST(letter);
        newNode->head = addMovieLLNodeHelper(nullptr, movieNode);
        return newNode;
    } else if (node->letter == letter) {
        node->head = addMovieLLNodeHelper(node->head, movieNode);
        return node;
    } else if (node->letter > letter) {
        node->leftChild = addMovieBSTNodeHelper(node->leftChild, movieNode);
    } else if (node->letter < letter) {
        node->rightChild = addMovieBSTNodeHelper(node->rightChild, movieNode);
    }
}

void MovieTree::addMovieNode(int rank, std::string title, int year, int quantity) {
    if (root == nullptr) {
        MovieNodeBST* newNode = new MovieNodeBST(title[0]);
        MovieNodeLL* newMovie = new MovieNodeLL(rank, title, year, quantity);
        newNode->head = addMovieLLNodeHelper(nullptr, newMovie);
        root = newNode;
    } else {
        MovieNodeLL* newMovie = new MovieNodeLL(rank, title, year, quantity);
        addMovieBSTNodeHelper(root, newMovie);
    }
}

void MovieTree::findMovie(std::string title) {

}

void MovieTree::rentMovie(std::string title) {

}

void MovieTree::DeleteAll(MovieNodeBST * node) {

} //use this for the post-order traversal deletion of the tree

void MovieTree::printMovieInventory(MovieNodeBST * node) {
    if (node == NULL) return;
 
    printMovieInventory(node->leftChild);
 
    MovieNodeLL* place = node->head;
    while (place != NULL) {
        cout << "Movie: " << place->title << " " << place->quantity << endl;
        place = place->next;
    }
 
    printMovieInventory(node->rightChild);
}

void MovieTree::countMovieNodes(MovieNodeBST *node, int *c) {

}

MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, std::string title) {
    if (node == NULL || node->letter == title[0]) {
        return node;
    } else if (node->letter > title[0]) {
        return searchBST(node->leftChild, title);
    } else if (node->letter < title[0]) {
        return searchBST(node->rightChild, title);
    }
} //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE

MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title) {

} //use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node) {
    MovieNodeBST* temp = node;

    while (temp->leftChild != NULL) {
        temp = temp->leftChild;
    }

    return temp;
} //use this to find the left most leaf node of the BST, you'll need this in the delete function
    