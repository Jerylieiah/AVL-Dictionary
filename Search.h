//#include <utility>

//
// Created by jbrogniez on 28/5/2019.
//

#ifndef AVLDICTIONARY_SEARCH_H
#define AVLDICTIONARY_SEARCH_H

#include "Data_Dictionary.h"

class Search
{
private:
    AvlTree<wordNode, string> *Dictionary{};

    bool compare = [](wordNode f1, wordNode f2) {return (f1.frequency < f2.frequency);};
    priority_queue<wordNode, vector<wordNode>, decltype(compare)> pQueue;


public:
    Search() = default;
    Search(AvlTree<wordNode, string> *d) {Dictionary = d;};
    void retrieveWord(string);
};

void Search::retrieveWord(string word)
{
    vector<wordNode> list;
    list = Dictionary->AVL_Retrieve(move(word));
    for ( int i = 0; i < list.size(); i++ )
        pQueue.push(list[i]);

    for ( int i = 0; i < pQueue.size(); i++ )
    {
        wordNode w;
        w = pQueue.top();
        cout << w.key << " (Number of occurences: " << w.numTimes << ")" << endl;
        pQueue.pop();
    }
}


#endif //AVLDICTIONARY_SEARCH_H
