#include <iostream>
#include <vector>
using namespace std;

class KMP {
public:
    // Function to compute the prefix function (partial match table)
    void computePrefixFunction(const string& pattern, vector<int>& P) {
        int m = pattern.size();
        P[0] = 0;
        int k = 0; // length of the previous longest prefix suffix

        for (int i = 1; i < m; ++i) {
            // Adjust k until pattern[k] matches pattern[i]
            while (k > 0 && pattern[k] != pattern[i]) {
                k = P[k - 1];  // Shift based on previous values in the table
            }
            if (pattern[k] == pattern[i]) {
                k++;
            }
            P[i] = k;  // Store the length of the current longest prefix suffix
        }
    }

    // KMP search function
    void search(const string& text, const string& pattern) {
        int n = text.size();
        int m = pattern.size();

        // Create the partial match table
        vector<int> P(m);
        computePrefixFunction(pattern, P);

        int q = 0;  // Number of characters matched

        // Loop through the text
        for (int i = 0; i < n; ++i) {
            // Find the longest prefix suffix that matches
            while (q > 0 && pattern[q] != text[i]) {
                q = P[q - 1];  // Shift based on the partial match table
            }

            if (pattern[q] == text[i]) {
                q++;
            }

            // If we have a full match
            if (q == m) {
                cout << "Pattern found at index " << i - m + 1 << endl;
                q = P[q - 1];  // Continue searching
            }
        }
    }
};

int main() {
    string text, pattern;

    // Take input for text and pattern
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    // Create an object of KMP and search for the pattern
    KMP kmp;
    kmp.search(text, pattern);

    return 0;
}
