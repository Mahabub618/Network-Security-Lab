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

string encryptRailFence(const string& plaintext, int rails) {
    vector<vector<char>> fence(rails, vector<char>(plaintext.length(), ' '));

    int rail = 0;
    bool goingDown = false;

    for (char c : plaintext) {
        fence[rail].push_back(c);

        if (rail == 0 || rail == rails - 1)
            goingDown = !goingDown;

        rail += goingDown ? 1 : -1;
    }

    string ciphertext;
    for (const auto& row : fence) {
        for (char c : row) {
            if (c != ' ')
                ciphertext += c;
        }
    }

    return ciphertext;
}

string decryptRailFence(const string& ciphertext, int rails) {
    vector<vector<char>> fence(rails, vector<char>(ciphertext.length(), ' '));

    int rail = 0;
    bool goingDown = false;

    for (int i = 0; i < ciphertext.length(); ++i) {
        if (rail == 0 || rail == rails - 1)
            goingDown = !goingDown;

        fence[rail][i] = '*';
        rail += goingDown ? 1 : -1;
    }

    int index = 0;
    for (int i = 0; i < rails; ++i) {
        for (int j = 0; j < ciphertext.length(); ++j) {
            if (fence[i][j] == '*' && index < ciphertext.length())
                fence[i][j] = ciphertext[index++];
        }
    }

    string plaintext;
    rail = 0;
    goingDown = false;

    for (int i = 0; i < ciphertext.length(); ++i) {
        plaintext += fence[rail][i];

        if (rail == 0 || rail == rails - 1)
            goingDown = !goingDown;

        rail += goingDown ? 1 : -1;
    }

    return plaintext;
}

int main() {
    init_code();
    string plaintext;
    int rails;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "\nEnter the number of rails: ";
    cin >> rails;
    
    plaintext.erase(std::remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower);
    
    string ciphertext = encryptRailFence(plaintext, rails);
    cout << "\nCiphertext: " << ciphertext << endl;

    string decryptedText = decryptRailFence(ciphertext, rails);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

