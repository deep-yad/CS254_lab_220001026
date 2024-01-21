#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

void generateDataFile(const char* filePath, int numElements) {
    ofstream outputFile(filePath);

    std::srand(std::time(0));

    for (int i = 0; i < numElements; ++i) {
        int dataPoint = std::rand() % 1000000 + 1;
        outputFile << dataPoint << '\n';
    }

    outputFile.close();
}

int main() {
    const char* filePath = "input.txt";
    int numElements = 10000000; 
    generateDataFile(filePath, numElements);
    return 0;
}
