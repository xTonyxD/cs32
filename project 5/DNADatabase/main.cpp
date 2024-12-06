//
//  main.cpp
//  DNADatabase
//

#include <iostream>
#include <cassert>
#include <string>

#include "TrieNode.h"

#include "Trie.h"
#include "DNADatabase.h"


int main( ) {
    int type = 0;
    
    if (type == 1) {
        using namespace cs32;
        using namespace std;

        Trie trie;
        DNADatabase database;
        bool endProgram = false;

        cout.setf(ios::boolalpha);
        string command, data;
        const string prompt = "(T)rie (D)NADatabase (Q)uit: ";
        const string trieprompt = "(C)ontains howMany(W)ords howMany(N)onWords (S)ize (H)eight (T)oString: ";
        const string databaseprompt = "(C)ountAllGs (A)ddSequence (F)indSequence (I)sValid (S)ize (H)eight: ";

        do
        {
            cout << prompt;
            cin >> command;
            switch (command.at(0))
            {
            case 'Q':
            case 'q':
                endProgram = true;
                break;
            case 'T':
            case 't':
                cout << trieprompt;
                cin >> command;
                switch (command.at(0))
                {
                case 'C':
                case 'c':
                    cout << "provide some data: ";
                    cin >> data;
                    cout << trie.contains(data) << endl;
                    break;
                case 'W':
                case 'w':
                    cout << trie.howManyWords() << endl;
                    break;
                case 'N':
                case 'n':
                    cout << trie.howManyNonWords() << endl;
                    break;
                case 'S':
                case 's':
                    cout << trie.size() << endl;
                    break;
                case 'H':
                case 'h':
                    cout << trie.height() << endl;
                    break;
                case 'T':
                case 't':
                    cout << trie.to_string() << endl;
                    break;
                }
                break;
            case 'D':
            case 'd':
                cout << databaseprompt;
                cin >> command;
                switch (command.at(0))
                {
                case 'C':
                case 'c':
                    cout << database.countAllGs() << endl;
                    break;
                case 'A':
                case 'a':
                    cout << "provide some data: ";
                    cin >> data;
                    cout << database.addSequence(data) << endl;
                    break;
                case 'F':
                case 'f':
                    cout << "provide some data: ";
                    cin >> data;
                    cout << database.findSequence(data) << endl;
                    break;
                case 'S':
                case 's':
                    cout << database.size() << endl;
                    break;
                case 'H':
                case 'h':
                    cout << database.height() << endl;
                    break;
                case 'I':
                case 'i':
                    cout << "provide some data: ";
                    cin >> data;
                    cout << database.isValid(data) << endl;
                    break;
                }
                break;
            }
        } while (!endProgram);


        return(0);
    }

    else if (type == 0) {
        using namespace std;
        using namespace cs32;


        // Tests for TrieNodes
        TrieNode* node = new TrieNode();
        TrieNode* node2 = new TrieNode();

        //cout << node->to_string() << endl;
        //cout << node2->to_string() << endl;

        cout << node->size() << " size =? 1" << endl << endl;
        cout << node->height() << " height =? 0" << endl << endl;
        cout << node->howManyWords() << " HMW =? 0" << endl << endl;
        cout << node->howManyNonWords() << " HMNW =? 1" << endl << endl;
        cout << !node->isEndOfWord() << " EOW 1" << endl << endl;
        cout << !node->dataExists('c') << "exists 1" << endl << endl;

        node->setMapNode('c', node2);
        node2->setEndOfWord();
        //cout << node->to_string() << endl;
        //cout << node2->to_string() << endl << endl;

        cout << node2->isEndOfWord() << " EOW" << endl << endl;
        cout << node->size() << " size =? 2" << endl << endl;
        cout << node->height() << " height =? 1" << endl << endl;
        cout << node->howManyWords() << " HMW =? 1" << endl << endl;
        cout << node->howManyNonWords() << " HMNW =? 1" << endl << endl;
        cout << node->dataExists('c') << "c exists node" << endl << endl;
        cout << !node2->dataExists('c') << "c exists node2" << endl << endl;
        std::map< char, TrieNode* >::const_iterator iter = node->find('c');
        cout << iter->first << " first =? 'c'" << endl << endl;

        // Tests for Tries
        Trie trie;
        cout << !trie.contains("howard") << " contains howard" << endl << endl ;
        cout << trie.howManyWords() << " HMW =? 0" << endl << endl;
        cout << trie.howManyNonWords() << " HMNW =? 1" << endl << endl;
        cout << trie.size() << " size =? 1" << endl << endl;
        cout << trie.height() << " height =? 0" << endl << endl;
        trie.insert("howard");
        cout << trie.howManyWords() << " HMW =? 1" << endl << endl;
        cout << trie.howManyNonWords() << " HMNW =? 6" << endl << endl;
        cout << trie.size() << " size =? 7" << endl << endl;
        cout << trie.height() << " height =? 6" << endl << endl;
        cout << trie.contains("howard") << "contains howard" << endl << endl;
        cout << !trie.contains("pixie") << "contains pixie" << endl << endl;
        cout << !trie.contains("how") << "contains how" << endl << endl;
        trie.insert("how");
        cout << trie.howManyWords() << " HMW =? 2" << endl << endl;
        cout << trie.howManyNonWords() << " HMNW =? 5" << endl << endl;
        cout << trie.size() << " size =? 7" << endl << endl;
        cout << trie.height() << " height =? 6" << endl << endl;

        cout << "********************DATABASE************************" << endl << endl;
        // Tests for DNADatabase
        DNADatabase database;
        cout << database.countAllGs() << " countallgs =? 0" << endl << endl;
        cout << database.size() << " size =? 1" << endl << endl;
        cout << database.height() << " height =? 0" << endl << endl;
        cout << database.isValid("AGCT") << "isvalid AGCT" << endl << endl;
        cout << !database.isValid("agct") << "isvalid agct" << endl << endl;
        cout << !database.isValid("AGrCT") << "isvalid AGrCT" << endl << endl;
        cout << !database.findSequence("howard") << "findseq howard" << endl << endl;
        cout << !database.findSequence("AGCT") << "findseq AGCT" << endl << endl;
        cout << database.addSequence("AGCT") << "addseq AGCT" << endl << endl;
        cout << database.size() << " size =? 5" << endl << endl;
        cout << database.height() << " height =? 4" << endl << endl;
        cout << !database.addSequence("howard") << "addseq howard" << endl << endl;
        cout << database.findSequence("AGCT") << "findseq AGCT" << endl << endl;
        cout << database.size() << " size =? 5" << endl << endl;
        cout << database.height() << " height=? 4" << endl << endl;
        cout << database.countAllGs() << " countallgs =? 0" << endl << endl;
        cout << database.addSequence("G") << " addseq G" << endl << endl;
        cout << database.countAllGs() << " countallgs =? 1" << endl << endl;
        cout << database.addSequence("GG") << "addseq GG" << endl << endl;
        cout << database.countAllGs() << " =? 2" << endl << endl;

        cout << "all tests passed!" << endl;
        return(0);
        
    }
} 
