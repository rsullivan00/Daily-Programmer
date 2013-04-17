#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	char vowels[7] = {'a', 'e', 'i', 'o', 'u', 'y'};
	ifstream inFile("input.txt");
	string word;
	while(inFile >> word){
		for(int i = 0; i < word.size(); i++){
			tolower(word[i]);
		}
		unsigned int count = 0;
		bool wordSucks = false;
		for(int i = 0; i < word.size(); i++){
			if(count == 7)	
				break;
			for(int j = 0; j < 7; j++){
				if(word[i] == vowels[j]){	//if the current letter is a vowel
					if(j == count){	//If found the correct next vowel
						count++;
						break;
					} else {	//wrong vowel
						wordSucks = true;
						break;
					}
				}
			}
			if(wordSucks)
				break;
			if(count == 6){	//If all vowels in word
				cout << word << endl;
			}
		}
	}
	return 0;
}
