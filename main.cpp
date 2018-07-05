// All C++ header files included
#include <iostream>
#include <fstream>

struct TrieNode
{
	struct TrieNode* character[26];
};



int main()
{
	// Variable Declaration
	std::ifstream f;
	std::string word;

	// Opening the word dictionary
	f.open("words_alpha.txt", std::ifstream::in);



	// Closing the word dictionary
	f.close();
	return 0;
}
