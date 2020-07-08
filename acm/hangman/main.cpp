#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	while( cin != -1 ){
		string in_word, guess;
		getline(cin, in_word);
		getline(cin, guess);

		vector<char> word;
		for (int i = 0; i < in_word.length(); i++){
			word.push_back(in_word[i]);	
		}

		for (int i = 0; i < guess.length(); i++) {
			if(find(word.begin(), word.end(), guess[i]))
		}
	}
	return 0;
}

