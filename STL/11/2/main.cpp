#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ofstream writeToFile ( "words.txt", ios::out );

    if ( !writeToFile ) {
        cerr << "Can not open file" << endl;
        exit( 1 );
    }

    cout << "enter words: ";
    string word;
    while (cin >> word) {
        writeToFile << word << " ";
    }
    writeToFile.close();

    ifstream readFromFile ( "words.txt", ios::in );
    ofstream writeToShortWords ( "shortwords.txt", ios::out );

    if ( !readFromFile ) {
        cerr << "Can not open file" << endl;
        exit( 1 );
    }
    if ( !writeToShortWords ) {
        cerr << "Can not open file" << endl;
        exit( 1 );
    }

    while ( readFromFile >> word ) {
        if (word.size() < 10) {
            writeToShortWords << word << " ";
            cout << word << " ";
        }
    }
    readFromFile.close();
    writeToShortWords.close();
    cout << "" << endl;
    return 0;
}
