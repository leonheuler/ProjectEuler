#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;


vector<int> decryptMessage(vector<int> message, vector<int> key)
{
    vector<int> result;
    for (auto i = 0; i < message.size(); i++)
        result.push_back(message[i] ^ key[i % key.size()]);
    return result;
}

int main()
{

    ifstream filei("p059_cipher.txt");
    vector<int> message;
    string str;
    while (getline(filei, str, ','))
        message.push_back(stoi(str));

    vector<int> result_msg;           // result message with most spaces
    vector<int> result_key;
    int spaces_max = 0;
    vector<int> key;
    vector<int> dmes;                 // decrypted message
    for (char a = 'a'; a <= 'z'; ++a) // bruteforcing through all possible keys looking for text with most spaces
        for (char b = 'a'; b <= 'z'; ++b)
            for (char c = 'a'; c <= 'z'; ++c)
            {
                key = {a, b, c};
                dmes = decryptMessage(message, key);

                // count spaces to find decrypted message with most spaces
                
                int spaces = 0;
                for (auto letter : dmes)
                    if (isspace(letter))
                        spaces++;

                if (spaces > spaces_max)
                {
                    result_key = key;
                    result_msg = dmes;
                    spaces_max = spaces;
                }
            }

    for (auto k : result_key)
        cout << (char)k;
    cout << endl;
    for (auto c : result_msg)
        cout << (char)c;
    cout << endl;

    cin.get();
}