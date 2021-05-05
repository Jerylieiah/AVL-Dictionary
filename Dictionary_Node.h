#include <utility>

//
// Created by jbrogniez on 24/5/2019.
//

#ifndef AVLDICTIONARY_DICTIONARY_NODE_H
#define AVLDICTIONARY_DICTIONARY_NODE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <queue>

using namespace std;

struct wordNode {
    string key;
    int numTimes = 0;
    double frequency = 0;
    static int totalWord;
    wordNode() = default;
    wordNode(string w, int n, double f);

};

wordNode::wordNode(string w, int n, double f) : key(move(w)), numTimes(n), frequency(f) {};

#endif //AVLDICTIONARY_DICTIONARY_NODE_H
