//
// Created by jbrogniez on 21/5/2019.
//

#ifndef AVLDICTIONARY_DATA_DICTIONARY_H
#define AVLDICTIONARY_DATA_DICTIONARY_H

#include "AVL_ADT.h"


using namespace std;



class Data_Dictionary {
private:
    AvlTree<wordNode, string> Dictionary;

    ifstream inFile;

public:
    //Data_Dictionary();



    void readTxt();
    void trimWord(string);
    void printDictionary();
    void printAVLTree();
    AvlTree<wordNode, string> *getDictionary();

};

void Data_Dictionary::readTxt()
{
    bool success = false;
    string x;
    while ( !success )
    {
        cout << "Type in the name of the text file you want to read in (eg. article.txt). Write exit to cancel: " << endl;
        string fileName;
        cin >> fileName;
        string location = "C:\\Users\\jerem\\Desktop\\Uni Resources\\2019 Autumn\\Data Structures and Algorithms\\Assignments\\Assignment 2\\AVLDictionary\\";
        location += fileName;
        //inFile.open(fileName);
        //inFile.open(R"(C:\Users\jerem\CLionProjects\Assignment2\requestList.txt)");
        inFile.open(location);

        if ( fileName == "exit")
            return;

        else if ( !inFile )
            cout << "Unable to open file. Try again" << endl;

        else
            success = true;
    }

    while ( inFile >> x )
    {
        trimWord(x);
    }
    inFile.close();

    //Dictionary.
}

void Data_Dictionary::trimWord(string word)
{
    //string testWord;
    istringstream iss(word);
    vector<string> tokens;
    copy (istream_iterator<string>(iss),
          istream_iterator<string>(),
          back_inserter(tokens));
    for ( int i = 0; i < tokens.size(); i++ )
    {
        //testWord = tokens[i];
        int length = tokens[i].length();
        for ( int j = 0; j < length; j++ )
        {
            if ( !isalpha(tokens[i][j]) )
            {
                tokens[i].erase(j, 1);
                j--;
                length--;
            }
        }
        if ( tokens[i] != "" )
        {
            cout << tokens[i] << endl;

            wordNode n(tokens[i], 1, 1 / (Dictionary.AVL_Return_Count() + 1) );

            Dictionary.AVL_Insert(n);
        }
    }
}


void Data_Dictionary::printDictionary()
{
    Dictionary.AVL_Traverse();
}

void Data_Dictionary::printAVLTree()
{
    Dictionary.AVL_Print();
}

AvlTree<wordNode, string> * Data_Dictionary::getDictionary() {
    return &Dictionary;
}


#endif //AVLDICTIONARY_DATA_DICTIONARY_H
