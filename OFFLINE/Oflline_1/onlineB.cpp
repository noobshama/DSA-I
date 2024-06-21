#include <iostream>
#include <cstring>

const int MAX_SIZE = 100;

bool canSplitIntoAnagrams(const char* input) {
    int count[26] = {0};

    // Count the occurrences of each character in the input string
    for (int i = 0; input[i] != '\0'; i++) {
        count[input[i] - 'a']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) {
            oddCount++;
        }
    }

    return oddCount <= 1;
}

void findAnagrams(const char* input, char* anagram1, char* anagram2) {
    int count[26] = {0};
    int len = strlen(input);
    int midpoint = len / 2;

    // Initialize anagram arrays
    for (int i = 0; i < 26; i++) {
        anagram1[i] = anagram2[i] = '\0';
    }

    // Count the occurrences of each character in the input string
    for (int i = 0; i < len; i++) {
        count[input[i] - 'a']++;
    }

    // Construct the first anagram
    int idx1 = 0;
    for (int i = 0; i < 26; i++) {
        int occurrences = count[i] / 2;
        while (occurrences--) {
            anagram1[idx1++] = 'a' + i;
        }
    }

    // Construct the second anagram
    int idx2 = 0;
    for (int i = 0; i < 26; i++) {
        int occurrences = count[i] / 2;
        while (occurrences--) {
            anagram2[idx2++] = 'a' + i;
        }
    }

    anagram1[midpoint] = '\0';
    anagram2[midpoint] = '\0';
}

int main() {
    char input[MAX_SIZE];
    std::cin >> input;

    if (canSplitIntoAnagrams(input)) {
        std::cout << "YES" << std::endl;

        char anagram1[MAX_SIZE], anagram2[MAX_SIZE];
        findAnagrams(input, anagram1, anagram2);

        std::cout << anagram1 << " " << anagram2 << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}