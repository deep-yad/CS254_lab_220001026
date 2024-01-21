#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Item {
    int weight;
    int value;
};

void generateInputFile(const char* filePath, int numTestCases) {
     ofstream file(filePath);
    if (!file.is_open()) {
         cerr << "Error: Unable to open file for writing: " << filePath << endl;
        return;
    }

    srand(time(0));

    file << numTestCases << '\n';

    for (int testCase = 1; testCase <= numTestCases; ++testCase) {
        int numItems = rand() % 5 + 1; 
        file << numItems << '\n';

        for (int i = 0; i < numItems; ++i) {
            int weight = rand() % 10 + 1;
            file << weight << ' ';
        }
        file << '\n';

        for (int i = 0; i < numItems; ++i) {
            int value = rand() % 20 + 1; 
            file << value << ' ';
        }
        file << '\n';

        int maxWeight = rand() % 30 + 10;
        file << maxWeight << '\n';
    }

    file.close();
}

int main() {
    const char* inputFilePath = "input.txt";
    int numTestCases = 10000; 
    generateInputFile(inputFilePath, numTestCases);

     cout << "Random input generated and saved to 'input.txt'" <<  endl;

    return 0;
}
