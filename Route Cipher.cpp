#include<bits/stdc++.h>
using namespace std;

void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}

const int MAX_SIZE = 100;
char matrix[MAX_SIZE][MAX_SIZE];
string spiralTraversalClockwise(int rows, int cols) {
    int startRow = 0, endRow = rows - 1;
    int startCol = 0, endCol = cols - 1;
    
    string cipher;
    while (startRow <= endRow && startCol <= endCol) {
        for (int col = startCol; col <= endCol; ++col) {
            
            cipher+=matrix[startRow][col];
        }
        ++startRow;

        for (int row = startRow; row <= endRow; ++row) {
            cipher+=matrix[row][endCol];
        }
        --endCol;

        if (startRow <= endRow) {
            for (int col = endCol; col >= startCol; --col) {
                cipher+=matrix[endRow][col];
            }
            --endRow;
        }

        if (startCol <= endCol) {
            for (int row = endRow; row >= startRow; --row) {
                cipher+=matrix[row][startCol];
            }
            ++startCol;
        }
    }
    return cipher;
}
string spiralTraversalAntiClockwise(int rows, int cols) {
    int startRow = 0, endRow = rows - 1;
    int startCol = 0, endCol = cols - 1;
    
    string cipher;
    while (startRow <= endRow && startCol <= endCol) {
        for (int col = endCol; col >= startCol; --col) {
            cipher+= matrix[startRow][col];
        }
        ++startRow;

        for (int row = startRow; row <= endRow; ++row) {
            cipher+= matrix[row][startCol];
        }
        ++startCol;

        if (startRow <= endRow) {
            for (int col = startCol; col <= endCol; ++col) {
                cipher+= matrix[endRow][col];
            }
            --endRow;
        }

        if (startCol <= endCol) {
            for (int row = endRow; row >= startRow; --row) {
                cipher+= matrix[row][endCol];
            }
            --endCol;
        }
    }
    return cipher;
}

pair<string, string> encrypt(string& plaintext, int numRows, int numCols) {
    int length = plaintext.length();
    int numChars = numRows * numCols;

    if (length < numChars) {
        int numPadding = numChars - length;
        for (int i = 0; i < numPadding; ++i) {
            plaintext += 'x';
        }
    }
    string temp = plaintext;
    reverse(temp.begin(), temp.end());
    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
            matrix[row][col] = temp.back();
            temp.pop_back();
        }
    }

    string Anticlockwise = spiralTraversalAntiClockwise(numRows, numCols);
    string clockwise = spiralTraversalClockwise(numRows, numCols);
    
    return {clockwise, Anticlockwise};
}
string decrypt(pair<string, string>& ciphertext, int numRows, int numCols) {
    int length = ciphertext.first.length();
    int numChars = numRows * numCols;
    string plaintext;
    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
            plaintext += matrix[row][col];
        }
    }
    while(!plaintext.empty() and plaintext.back() == 'x') plaintext.pop_back();
    return plaintext;
}

int main() {
    init_code();
    string plaintext;
    int numRows, numCols, matrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "\nEnter the number of columns: ";
    cin >> numCols;
    cin.ignore(); 
    cout <<endl;
    plaintext.erase(std::remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());
    
    numRows = (plaintext.size()+numCols-1)/numCols;
    auto ciphertext = encrypt(plaintext, numRows, numCols);
    cout << "Ciphertext in spiral inwards clockwise: " << ciphertext.first << endl;
    cout << "Ciphertext in spiral inwards Anticlockwise: " << ciphertext.second << endl;
    
    string decryptedText = decrypt(ciphertext, numRows, numCols);
    cout << "Deciphertext is: " << decryptedText << endl;

    return 0;
}

