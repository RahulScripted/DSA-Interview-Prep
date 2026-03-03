// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

// There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

// Implement the Solution class:

//     1 - Solution() Initializes the object of the system.
//     2 - String encode(String longUrl) Returns a tiny URL for the given longUrl.
//     3 - String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<string, string> codeDB, urlDB;
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    string getCode() {
        string code = "";
        for (int i = 0; i < 6; i++) code += chars[rand() % 62];
        return "http://tinyurl.com/" + code;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (urlDB.find(longUrl) != urlDB.end()) return urlDB[longUrl];
        string code = getCode();
        while (codeDB.find(code) != codeDB.end()) code = getCode();
        codeDB[code] = longUrl;
        urlDB[longUrl] = code;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codeDB[shortUrl];
    }
};

int main() {
    Solution* obj = new Solution();
    string longUrl = "https://leetcode.com/problems/design-tinyurl";
    string shortUrl = obj->encode(longUrl);
    cout << "Short URL: " << shortUrl << endl;
    cout << "Decoded URL: " << obj->decode(shortUrl) << endl;
    return 0;
}