// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> newTree;
  std::ifstream file(filename);
  std::string word = "";
  if (file.is_open()) {
    while (!file.eof()) {
      word = "";
      while (true) {
        char letter = file.get();
        if ((letter >= 97 && letter <= 122) || (letter >= 65 && letter <= 90)) {
          char s = tolower(letter);
          word = word + s;
        } else {
          break;
        }
      }
      newTree.add(word);
    }
    return newTree;
  }
}
