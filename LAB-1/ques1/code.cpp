#include<bits/stdc++.h>
using namespace std;


int main(){
    const char* inputFilePath = "input.txt";
    const char* outputFilePath = "output.txt";
    ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file: " << inputFilePath << std::endl;
        return 0;
    }

    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file: " << outputFilePath << std::endl;
        inputFile.close();
        return 0;
    }
    int dataPoint;
    int maxi=INT_MIN;
    int seMaxi=INT_MIN;
    while (inputFile >> dataPoint) {
            if(dataPoint>=maxi){
                seMaxi = maxi;
                maxi=dataPoint;
            }
            else if(dataPoint >= seMaxi){
                seMaxi = dataPoint;
            }
    }
    outputFile << maxi+seMaxi << " ";
    inputFile.close();
    outputFile.close();

    return 0;
}
