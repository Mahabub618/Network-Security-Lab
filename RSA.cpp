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


// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;
    
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

// Function to compute the modular multiplicative inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; ++x) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Function to generate RSA keys
void generateRSAKeys(int p, int q, int& publicKey, int& privateKey) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Find public key (e)
    publicKey = 2;
    while (publicKey < phi) {
        if (__gcd(publicKey, phi) == 1)
            break;
        publicKey++;
    }

    // Find private key (d)
    privateKey = modInverse(publicKey, phi);
}

int bigmod(int a, int b, int m){if(b==0) return 1%m;int x=bigmod(a, b/2, m);x=(x*x)%m;if(b%2==1)x=(x*a)%m;return x;}
int encryptRSA(int message, int publicKey, int n) {
    return bigmod(message, publicKey, n);
}

int decryptRSA(int encryptedMessage, int privateKey, int n) {
    return bigmod(encryptedMessage, privateKey, n);
}

int main() {
    init_code();
    int p, q;
    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;

    if (!isPrime(p) or !isPrime(q)) {
        cout << "\np and q must be prime numbers!" << endl;
        exit(0);
    }

    int publicKey, privateKey;
    generateRSAKeys(p, q, publicKey, privateKey);

    cout << "Public Key (e): " << publicKey << endl;
    cout << "Private Key (d): " << privateKey << endl;

    int message;
    cout << "Enter the message to encrypt: ";
    cin >> message;

    int encryptedMessage = encryptRSA(message, publicKey, p * q);
    cout << "Encrypted Message: " << encryptedMessage << endl;

    int decryptedMessage = decryptRSA(encryptedMessage, privateKey, p * q);
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}

