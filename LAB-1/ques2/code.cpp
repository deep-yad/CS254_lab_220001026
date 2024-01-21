#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack(const  vector<Item>& items, int maxWeight) {
    int numItems = items.size();
     vector< vector<int>> dp(numItems + 1,  vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= numItems; ++i) {
        for (int w = 0; w <= maxWeight; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] =  max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[numItems][maxWeight];
}

void processInputFile(const char* inputFilePath, const char* outputFilePath) {
     ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
         cerr << "Error: Unable to open input file: " << inputFilePath <<  endl;
        return;
    }

    int numTestCases;
    inputFile >> numTestCases;

     ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
         cerr << "Error: Unable to open output file: " << outputFilePath <<  endl;
        inputFile.close();
        return;
    }

    for (int testCase = 1; testCase <= numTestCases; ++testCase) {
        int numItems, maxWeight;
        inputFile >> numItems;

         vector<Item> items(numItems);
        for (int i = 0; i < numItems; ++i) {
            inputFile >> items[i].weight;
        }

        for (int i = 0; i < numItems; ++i) {
            inputFile >> items[i].value;
        }

        inputFile >> maxWeight;

        int result = knapsack(items, maxWeight);
        outputFile << "Test Case " << testCase << ": " << result <<  endl;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    const char* inputFilePath = "input.txt";
    const char* outputFilePath = "output.txt";

    processInputFile(inputFilePath, outputFilePath);

     cout << "Knapsack problems solved. Results saved to 'output.txt'" <<  endl;

    return 0;
}
