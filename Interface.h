//
// Created by jbrogniez on 22/5/2019.
//

#ifndef AVLDICTIONARY_INTERFACE_H
#define AVLDICTIONARY_INTERFACE_H



#include "Data_Dictionary.h"
#include "Search.h"

class Interface {
private:
    Data_Dictionary dictionary;
    Search search;

public:
    void menu();
    void inputWord();

};


void Interface::menu()
{
    int num;
    do {
        cout << endl;
        cout << "Type a number and press enter to select from the menu: " << endl;
        cout << "1. Read a text file into the dictionary." << endl;
        cout << "2. Print dictionary in alphabetical order." << endl;
        cout << "3. Print the AVL tree with all its properties." << endl;
        cout << "4. Search and predict a word." << endl;
        cout << "Type 0 to exit." << endl;
        cin >> num;
        cout << endl;
        if (num == 1)
            dictionary.readTxt();
        else if (num == 2)
            dictionary.printDictionary();
        else if (num == 3)
            dictionary.printAVLTree();
        else if (num == 4)
        {
            Search search(dictionary.getDictionary());
            inputWord();
        }
        else if (num == 5)
            dictionary.trimWord("And I feel fine...");
        else if (num == 0)
            return;
        else
            cout << "Menu option doesn't exist. Try again." << endl;
    } while ( num != 0 );
}

void Interface::inputWord()
{
    while ( true )
    {
        string searchWord;
        cout << "Input word (Type 0 to exit): " << endl;
        cin >> searchWord;
        for ( int i = 0; i < searchWord.size(); i++ )
            if ( searchWord[i] == '0' )
                return;

        search.retrieveWord(searchWord);
    }
}

#endif //AVLDICTIONARY_INTERFACE_H
