#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#include "AVL_ADT.h"
#include "AVL_ADT_Ext.h"
#include "CIndex.h"

void menu (){
    CIndex Index;
    //AvlTree<DATA, string> tree;
   // AVLTreeExt<DATA, string> tree;
    int selection = 10;
    while(selection != 0) {
        cout << " please select from one of the menu items below: " << endl;
        cout << "--------------------------------------" << endl;
        cout << "    1. Learn an index dictionary from a file (without phrases)." << endl;
        cout << "    2. Print the index dictionary." << endl;
        cout << "    3. Print the AVL tree of the dictionary." << endl;
        cout << "    4. Output the dictionary to a text file." << endl;
        cout << "    5. Load dictionary from a file." << endl;
        cout << "    6. Learn an index dictionary from a set of files (without phrases)." << endl;
        cout << "    7. Search for a word/phrase with input suggestions." << endl;
        cout << "    8. Learn an index dictionary from a file (with phrases)." << endl;
        cout << "    9. Delete low frequency words from the dictionary." << endl;
        cout << "    0. Quit. " << endl;
        cout << "--------------------------------------" << endl;

        cin >> selection;

        switch (selection) {

            case 0:
                exit(0);

            case 1:
                Index.readFile();
                break;
            case 2:
                Index.printDictionary();
                break;
            case 3:
                Index.printAVLTree();
                Index.getTotalWord();
                break;
            case 4:
                Index.printD2File();
                break;
            case 5:
                Index.LoadDictionary();
                break;
            case 6:
                Index.readFiles();
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                //Index.DeleteLowFreqWords
                break;
        }

    }

}


int main() {
   menu();
   //fin.close();
   //fout.close();
   return 0;
}
