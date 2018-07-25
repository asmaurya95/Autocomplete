// Include C++ header files
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct TrieNode
{
	struct TrieNode* character[26];
	bool isWord;
};

TrieNode* createNode()
{
	TrieNode* newNode = new TrieNode();
	int i;
	for(i = 0; i < 26; i++)
	{
		newNode -> character[i] = NULL;
	}
	newNode -> isWord = false;
	return newNode;
}

void updateTrie(TrieNode* root, string word)
{
	int i = 0;
	while(i < word.length())
	{
		if(root -> character[word[i] - 'a'] == NULL)
			root -> character[word[i] - 'a'] = createNode();
		root = root -> character[word[i] - 'a'];
		i++;
	}
	// Now set isWord as true
	// to indicate end of a word
	root -> isWord = true;
}

void completeWord(TrieNode* root, string word) {
	int i = 0;
	while(i < word.length()) {
		if(root -> character[word[i] - 'a'] == NULL) {
			cout << "NO SUCH WORD NOT FOUND IN DICTIONARY !\n";
			return;
		}
		root = root -> character[word[i] - 'a'];
		i++;
	}
	if(root -> isWord)
		cout << word << endl;
	else {
	}
}

int main()
{
	// Variable Declaration
	ifstream myfile;
	string word;

	// Opening the word dictionary
	myfile.open("res/words.txt", ifstream::in);

	// Creating and initializing the Trie
	TrieNode* root = createNode();


	// Reading each word from the file and updating the Trie
	while(getline(myfile, word))
	{
		updateTrie(root, word);
	}

	cin >> word;

	// Convert each letter into its lowercase
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	completeWord(root, word);

	// Closing the word dictionary
	myfile.close();
	return 0;
}
