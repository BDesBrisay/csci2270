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

void deleteBSTNodeHelper() {

}

void MovieTree::deleteMovieNode(std::string title) {
    if (root == NULL) return;

    MovieNodeBST* rightNode = searchBST(root, title);
    if (rightNode != NULL) {
        if (rightNode->head->next == nullptr) {
            cout << "One" << endl;
            if (rightNode->head->title == title) {
                cout << "One2" << endl;
                if (rightNode->leftChild == NULL && rightNode->rightChild == NULL) {
                    cout << "One3" << endl;
                    if (!rightNode->parent) {
                        delete rightNode;
                        return;
                    } else if (rightNode->letter > rightNode->parent->letter) {
                        rightNode->parent->rightChild = NULL;
                        delete rightNode;
                        return;
                    } else {
                        rightNode->parent->leftChild = NULL;
                        delete rightNode;
                        return;
                    }
                } else if (rightNode->leftChild == NULL && rightNode->rightChild != NULL) {
                    cout << "One4" << endl;
                    if (!rightNode->parent) {
                        root = rightNode->rightChild;
                        rightNode->rightChild->parent = NULL;
                        delete rightNode;
                        return;
                    } else if (rightNode->letter > rightNode->parent->letter) {
                        rightNode->parent->rightChild = rightNode->rightChild;
                        rightNode->rightChild->parent = rightNode->parent;
                        delete rightNode;
                        return;
                    } else {
                        rightNode->parent->leftChild = rightNode->rightChild;
                        rightNode->rightChild->parent = rightNode->parent;
                        delete rightNode;
                        return;
                    }
                } else if (rightNode->leftChild != NULL && rightNode->rightChild == NULL) {
                    cout << "One5" << endl;
                    if (!rightNode->parent) {
                        root = rightNode->leftChild;
                        rightNode->leftChild->parent = NULL;
                        delete rightNode;
                        return;
                    } else if (rightNode->letter > rightNode->parent->letter) {
                        rightNode->parent->rightChild = rightNode->leftChild;
                        rightNode->leftChild->parent = rightNode->parent;
                        delete rightNode;
                        return;
                    } else {
                        rightNode->parent->leftChild = rightNode->leftChild;
                        rightNode->leftChild->parent = rightNode->parent;
                        delete rightNode;
                        return;
                    }
                } else if (rightNode->leftChild != NULL && rightNode->rightChild != NULL) {
                    cout << "One6" << endl;
                    MovieNodeBST* replacement = treeMinimum(rightNode->rightChild);
                    replacement->parent->leftChild = NULL;

                    cout << "One6" << endl;
                    if (!rightNode->parent) {
                    cout << "1" << endl;
                        rightNode->rightChild->parent = replacement;
                        replacement->rightChild = rightNode->rightChild;
                        replacement->leftChild = rightNode->leftChild;
                        delete rightNode;
                        return;
                    } else if (rightNode->letter > rightNode->parent->letter) {
                    cout << "2" << endl;
                        rightNode->parent->rightChild = replacement;
                        rightNode->leftChild->parent = replacement; 
                        rightNode->rightChild->parent = replacement; 
                        replacement->parent = rightNode->parent;
                        replacement->rightChild = rightNode->rightChild;
                        replacement->leftChild = rightNode->leftChild;
                        delete rightNode;
                        return;
                    } else {
                    cout << "3" << endl;
                        rightNode->parent->leftChild = replacement;
                    cout << "3" << endl;
                        // rightNode->leftChild->parent = replacement; 
                    cout << "3" << endl;
                        rightNode->rightChild->parent = replacement; 
                    cout << "3" << endl;
                        replacement->parent = rightNode->parent;
                    cout << "3" << endl;
                        replacement->rightChild = rightNode->rightChild;
                    cout << "3" << endl;
                        replacement->leftChild = rightNode->leftChild;
                        delete rightNode;
                        return;
                    }
                }
            }
        } else {
            cout << "Multiple" << endl;
            MovieNodeLL* place = rightNode->head;

            if (place->title == title) {
                if (place->next != nullptr) {
                    rightNode->head = place->next;
                    rightNode->head->next = nullptr;
                    delete place;
                    return;
                }
            }

            while (place->next != nullptr) {
                if (place->next->title == title) {
                    MovieNodeLL* temp = place->next->next;
                    delete place->next;
                    place->next = temp;
                    return;
                }
                place = place->next;
            }
            cout << "Movie not found." << endl;
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

MovieNodeBST* addMovieBSTNodeHelper(MovieNodeBST* node, MovieNodeBST* prev, MovieNodeLL* movieNode) {
    char letter = movieNode->title[0];
    if (node == NULL) {
        MovieNodeBST* newNode = new MovieNodeBST(letter);
        newNode->parent = prev;
        newNode->head = addMovieLLNodeHelper(nullptr, movieNode);
        return newNode;
    } else if (node->letter == letter) {
        node->head = addMovieLLNodeHelper(node->head, movieNode);
        return node;
    } else if (node->letter > letter) {
        node->leftChild = addMovieBSTNodeHelper(node->leftChild, node, movieNode);
    } else if (node->letter < letter) {
        node->rightChild = addMovieBSTNodeHelper(node->rightChild, node, movieNode);
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
        addMovieBSTNodeHelper(root, NULL, newMovie);
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
    MovieNodeLL* place = head;

    while (place != nullptr) {
        if (place->title == title) {
            return place;
        }
        place = place->next;
    }

    return nullptr;
} //use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node) {
    MovieNodeBST* temp = node;

    while (temp->leftChild != NULL) {
        temp = temp->leftChild;
    }

    return temp;
} //use this to find the left most leaf node of the BST, you'll need this in the delete function
    