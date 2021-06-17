#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
	char letter;
	std::string randomWord;
	int tries{ 6 };
	bool shouldTryBeRemoved{ true };

	std::string text = "C:\\Users\\Lukas\\Desktop\\Test\\Begriffe.txt";
	std::ifstream myFile(text, std::ios::in);
	std::vector<std::string> words;
	std::vector<int> occurencesOfLetter;

	if (myFile) {
		for (std::string line; std::getline(myFile, line);) {
			words.push_back(line);
		}
	}

	myFile.close();

	auto randomNumber = std::rand() % 10;

	randomWord = words[randomNumber];

	std::string mysteryWord(randomWord.length(), '*');

	std::cout << " Hangman " << std::endl;
	std::cout << "_________________________" << std::endl;
	std::cout << "|               }        " << std::endl;
	std::cout << "|               O        " << std::endl;
	std::cout << "|               |        " << std::endl;
	std::cout << "|             / | \\     " << std::endl;
	std::cout << "|            /  |  \\    " << std::endl;
	std::cout << "|               |        " << std::endl;
	std::cout << "|              / \\      " << std::endl;
	std::cout << "|             /   \\     " << std::endl;
	std::cout << "|                        " << std::endl;
	std::cout << "|                        " << std::endl;
	std::cout << "|________________________" << std::endl;
	std::cout << "\nTip in any letter and enter to start the game:" << std::endl;

	std::cin >> letter;

	while (tries >= 0) {

		std::cout << "The word is:" << std::endl;
		std::cout << mysteryWord << std::endl;
		std::cout << "The word is this long: " << mysteryWord.length() << std::endl;
		std::cout << "You have " << tries << " guesses left" << std::endl;
		std::cin >> letter;

		if (mysteryWord.rfind(letter) == std::string::npos && mysteryWord.rfind(::toupper(letter)) == std::string::npos) {
			for (int i = 0; i < randomWord.size(); i++) {
				if (::tolower(randomWord[i]) == letter) {
					mysteryWord[i] = randomWord[i];
					shouldTryBeRemoved = false;
				}
			}

			if (shouldTryBeRemoved) {
				tries--;
				std::cout << "That letter is not correct. Remove one guess. Now you have: " << tries << " left." << std::endl;
			}
		}
		else {
			std::cout << "Letter is already used. Try again." << std::endl;
		}
		shouldTryBeRemoved = true;

		if (randomWord == mysteryWord) {
			std::cout << "Congratulations, you win the hangman game " << std::endl;
			break;
		}

		switch (tries) {

		case 6:
			std::cout << "_________________________" << std::endl;
			std::cout << "|               }        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|________________________" << std::endl;
			break;
		case 5:
			std::cout << "_________________________" << std::endl;
			std::cout << "|               }        " << std::endl;
			std::cout << "|               O        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|________________________" << std::endl;
			break;
		case 4:
			std::cout << "_________________________" << std::endl;
			std::cout << "|               }        " << std::endl;
			std::cout << "|               O        " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|________________________" << std::endl;
			break;
		case 3:
			std::cout << "_________________________" << std::endl;
			std::cout << "|               }        " << std::endl;
			std::cout << "|               O        " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|             / |        " << std::endl;
			std::cout << "|            /  |        " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|________________________" << std::endl;
			break;
		case 2:
			std::cout << "_________________________" << std::endl;
			std::cout << "|               }        " << std::endl;
			std::cout << "|               O        " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|             / | \\     " << std::endl;
			std::cout << "|            /  |  \\    " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|________________________" << std::endl;
			break;
		case 1:
			std::cout << "_________________________" << std::endl;
			std::cout << "|               }        " << std::endl;
			std::cout << "|               O        " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|             / | \\     " << std::endl;
			std::cout << "|            /  |  \\    " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|              /         " << std::endl;
			std::cout << "|             /          " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|________________________" << std::endl;
			break;
		case 0:
			std::cout << "_________________________" << std::endl;
			std::cout << "|               }        " << std::endl;
			std::cout << "|               O        " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|             / | \\     " << std::endl;
			std::cout << "|            /  |  \\    " << std::endl;
			std::cout << "|               |        " << std::endl;
			std::cout << "|              / \\      " << std::endl;
			std::cout << "|             /   \\     " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|                        " << std::endl;
			std::cout << "|________________________" << std::endl;
			std::cout << " Hangman you lose " << std::endl;
			tries = -1;
			break;
		default:
			std::cout << "There is an error. " << std::endl;
		}
	}

	return 0;
}