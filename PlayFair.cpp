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

const int SIZE = 5;

string prepareKey(const string& key) {
    string preparedKey;
    bool visited[26] = { false };

    for (char c : key) {
        if (isalpha(c) && !visited[tolower(c) - 'a']) {
            preparedKey += tolower(c);
            visited[tolower(c) - 'a'] = true;
        }
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        if (c != 'j' && !visited[c - 'a']) {
            preparedKey += c;
            visited[c - 'a'] = true;
        }
    }

    return preparedKey;
}

void generateMatrix(const string& key, char matrix[SIZE][SIZE]) {
    string preparedKey = prepareKey(key);
    int k = 0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = preparedKey[k++];
        }
    }
}

void findPosition(const char matrix[SIZE][SIZE], char ch, int& row, int& col) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string encrypt(const string& plaintext, const string& key) {
    char matrix[SIZE][SIZE];
    generateMatrix(key, matrix);

    string encryptedText;
    string normalizedText;
    
    for (char c : plaintext) {
        if (isalpha(c)) {
            normalizedText += tolower(c);
            if (c == 'j') {
                normalizedText += 'i';
            }
        }
    }
    

    int length = normalizedText.length();
    int index = 0;

    while (index < length) {
        char ch1 = normalizedText[index++];
        char ch2 = (index < length) ? normalizedText[index++] : 'x';

        int row1, col1, row2, col2;
        findPosition(matrix, ch1, row1, col1);
        findPosition(matrix, ch2, row2, col2);

        char encryptedCh1, encryptedCh2;
        if (row1 == row2) {
            encryptedCh1 = matrix[row1][(col1 + 1) % SIZE];
            encryptedCh2 = matrix[row2][(col2 + 1) % SIZE];
        }
        else if (col1 == col2) {
            encryptedCh1 = matrix[(row1 + 1) % SIZE][col1];
            encryptedCh2 = matrix[(row2 + 1) % SIZE][col2];
        }
        else {
            encryptedCh1 = matrix[row1][col2];
            encryptedCh2 = matrix[row2][col1];
        }

        encryptedText += encryptedCh1;
        encryptedText += encryptedCh2;
    }

    return encryptedText;
}

string decrypt(const string& ciphertext, const string& key) {
    char matrix[SIZE][SIZE];
    generateMatrix(key, matrix);

    string decryptedText;

    int length = ciphertext.length();
    int index = 0;

    while (index < length) {
        char ch1 = ciphertext[index++];
        char ch2 = ciphertext[index++];

        int row1, col1, row2, col2;
        findPosition(matrix, ch1, row1, col1);
        findPosition(matrix, ch2, row2, col2);
        
        char decryptedCh1, decryptedCh2;
        if (row1 == row2) {
            decryptedCh1 = matrix[row1][(col1 - 1 + SIZE) % SIZE];
            decryptedCh2 = matrix[row2][(col2 - 1 + SIZE) % SIZE];
        }
        else if (col1 == col2) {
            decryptedCh1 = matrix[(row1 - 1 + SIZE) % SIZE][col1];
            decryptedCh2 = matrix[(row2 - 1 + SIZE) % SIZE][col2];
        }
        else {
            decryptedCh1 = matrix[row1][col2];
            decryptedCh2 = matrix[row2][col1];
        }

        decryptedText += decryptedCh1;
        decryptedText += decryptedCh2;
    }

    return decryptedText;
}
int main() {
    init_code();
    string plaintext, ciphertext;
    string key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "\nEnter the keywords: ";
    getline(cin, key);
    
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower);
    transform(key.begin(), key.end(), key.begin(), ::tolower);
        
    string cipher = encrypt(plaintext, key);

    cout << "\nCiphertext: " << cipher << endl;
    
    cout << "Enter the ciphertext: ";
    getline(cin, ciphertext);
    cout << "\nEnter the keywords: ";
    getline(cin, key);
    
    transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), ::tolower);
    transform(key.begin(), key.end(), key.begin(), ::tolower);
        
    string Plaintext = decrypt(ciphertext, key);
    
    cout << "\nPlaintext: " << Plaintext << endl;
    return 0;
}

