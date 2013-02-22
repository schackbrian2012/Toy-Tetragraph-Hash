//
//  main.cpp
//  Toy Tetragraph Hash
//
//  Created by Brian Schack on 2/19/13.
//  Copyright (c) 2013 Brian Schack. All rights reserved.
//

#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

string toyTetragraphHash(string message) {
    // First, tth divides the message into blocks of 16 letters, ignoring spaces, punctuation, and capitalization
    int characterIndex = 0;
    vector<string> blocksOfCharacters;
    string blockOfCharacters = "";
    blocksOfCharacters.push_back(blockOfCharacters);
    while (true) {
        if (characterIndex >= message.size()) {
            break;
        }
        char character = message.at(characterIndex);
        if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')) {
            if (blocksOfCharacters.at(blocksOfCharacters.size() - 1).size() >= 16) {
                blocksOfCharacters.push_back(blockOfCharacters);
            }
            if (character >= 'A' && character <= 'Z') {
                character += 32;
            }
            blocksOfCharacters.at(blocksOfCharacters.size() - 1) += character;
        }
        characterIndex++;
    }
    
    // If the message length is not divisible by 16, it is padded out with nulls
    while (true) {
        if (blocksOfCharacters.at(blocksOfCharacters.size() - 1).size() < 16) {
            blocksOfCharacters.at(blocksOfCharacters.size() - 1) += 'a';
        } else {
            break;
        }
    }
    
    // blocksOfCharacters
    int blockIndex = 0;
    while (true) {
        // cout << blocksOfCharacters.at(blockIndex) << '\n';
        blockIndex++;
        if (blockIndex >= blocksOfCharacters.size()) {
            break;
        }
    }
    
    // A four-number running total is maintained that starts out with the value (0, 0, 0, 0)
    vector<int> totals(4);
    
    // totals
    int totalIndex = 0;
    while (true) {
        // cout << totals.at(totalIndex) << ' ';
        totalIndex++;
        if (totalIndex >= 4) {
            // cout << '\n';
            break;
        }
    }
    
    // Get the next block of text and arrange it as a row-wise 4 x 4 block of text and covert it to numbers (A = 0, B = 1, ...)
    vector<vector<int>> blocksOfNumbers;
    vector<int> blockOfNumbers;
    blocksOfNumbers.push_back(blockOfNumbers);
    while (true) {
        blockOfCharacters = blocksOfCharacters.at(blocksOfNumbers.size() - 1);
        char character = blockOfCharacters.at(blocksOfNumbers.at(blocksOfNumbers.size() - 1).size());
        blocksOfNumbers.at(blocksOfNumbers.size() - 1).push_back(character - 97);
        if (blocksOfNumbers.at(blocksOfNumbers.size() - 1).size() >= 16) {
            if (blocksOfNumbers.size() < blocksOfCharacters.size()) {
                blocksOfNumbers.push_back(blockOfNumbers);
            } else {
                break;
            }
        }
    }
    
    // blocksOfNumbers
    blockIndex = 0;
    int numberIndex = 0;
    while (true) {
        // cout << blocksOfNumbers.at(blockIndex).at(numberIndex) << ' ';
        numberIndex++;
        if (numberIndex >= 16) {
            // cout << '\n';
            blockIndex++;
            numberIndex = 0;
            if (blockIndex >= blocksOfNumbers.size()) {
                break;
            }
        }
    }
    
    // Then add each column mod 26 and add the result to the running total mod 26
    blockIndex = 0;
    int columnIndex = 0;
    while (true) {
        blockOfNumbers = blocksOfNumbers.at(blockIndex);
        totals.at(columnIndex) += blockOfNumbers.at(columnIndex) + blockOfNumbers.at(columnIndex + 4) + blockOfNumbers.at(columnIndex + 8) + blockOfNumbers.at(columnIndex + 12);
        totals.at(columnIndex) = totals.at(columnIndex) % 26;
        columnIndex++;
        if (columnIndex >= 4) {
            blockIndex++;
            columnIndex = 0;
            if (blockIndex >= blocksOfNumbers.size()) {
                break;
            }
        }
    }
    
    // totals
    totalIndex = 0;
    while (true) {
        // cout << totals.at(totalIndex) << ' ';
        totalIndex++;
        if (totalIndex >= 4) {
            // cout << '\n';
            break;
        }
    }
    
    // Using the matrix from round 1, rotate the first row left by 1, second row left by 2, third row left by 3, and reverse the order of the fourth row
    vector<vector<int>> rotatedBlocks;
    vector<int> rotatedBlock;
    rotatedBlocks.push_back(rotatedBlock);
    while (true) {
        blockOfNumbers = blocksOfNumbers.at(rotatedBlocks.size() - 1);
        vector<int> rotations {1, 2, 3, 0, 6, 7, 4, 5, 11, 8, 9, 10, 15, 14, 13, 12};
        int rotation = rotations.at(rotatedBlocks.at(rotatedBlocks.size() - 1).size());
        rotatedBlocks.at(rotatedBlocks.size() - 1).push_back(blockOfNumbers.at(rotation));
        if (rotatedBlocks.at(rotatedBlocks.size() - 1).size() >= blockOfNumbers.size()) {
            if (rotatedBlocks.size() < blocksOfNumbers.size()) {
                rotatedBlocks.push_back(rotatedBlock);
            } else {
                break;
            }
        }
    }
    
    // rotatedBlocks
    blockIndex = 0;
    numberIndex = 0;
    while (true) {
        // cout << rotatedBlocks.at(blockIndex).at(numberIndex) << ' ';
        numberIndex++;
        if (numberIndex >= 16) {
            // cout << '\n';
            blockIndex++;
            numberIndex = 0;
            if (blockIndex >= rotatedBlocks.size()) {
                break;
            }
        }
    }
    
    // Now add each column mod 26 and add the result to the running total
    blockIndex = 0;
    columnIndex = 0;
    while (true) {
        rotatedBlock = rotatedBlocks.at(blockIndex);
        totals.at(columnIndex) += rotatedBlock.at(columnIndex) + rotatedBlock.at(columnIndex + 4) + rotatedBlock.at(columnIndex + 8) + rotatedBlock.at(columnIndex + 12);
        totals.at(columnIndex) = totals.at(columnIndex) % 26;
        columnIndex++;
        if (columnIndex >= 4) {
            blockIndex++;
            columnIndex = 0;
            if (blockIndex >= rotatedBlocks.size()) {
                break;
            }
        }
    }
    
    // totals
    totalIndex = 0;
    while (true) {
        // cout << totals.at(totalIndex) << ' ';
        totalIndex++;
        if (totalIndex >= 4) {
            // cout << '\n';
            break;
        }
    }
    
    // After the final block is processed, convert the final running total to letters.
    string hash = "";
    totalIndex = 0;
    while (true) {
        hash += totals.at(totalIndex) + 97;
        totalIndex++;
        if (totalIndex >= 4) {
            break;
        }
    }
    
    return hash;
}

int main(int argc, const char* argv[]) {
    // This problem introduces a hash function similar in spirit to SHA that operates on letters instead of binary data. It is called the toy tetragraph hash (tth).
    cout << "Toy Tetragraph Hash\n";
    cout << "Brian Schack\n";
    
    assert(toyTetragraphHash("ABCDEFGHIJKLMNOP") == "fhjl");
    assert(toyTetragraphHash("I leave twenty million dollars to my friendly cousin Bill.") == "bfqg");
    assert(toyTetragraphHash("AYHGD") == "bfqg");
    
    // Given a message consisting of a sequence of letters, tth produces a hash value consisting of four letters.
    cout << "Message? ";
    string message;
    getline(cin, message);
    cout << toyTetragraphHash(message);
    
    return 0;
}