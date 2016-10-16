#include <cctype>
#include <cstring>
#include "strtype.h"

void StrType::MakeEmpty(){
	letters[0] = '\0';

}



void StrType::GetString(bool skip, InType charsAllowed){

}



void StrType::GetStringFile(bool skip, InType charsAllowed,std::ifstream& inFile){
	switch (charsAllowed){
		case ALPHA_NUM : 
			GetAlphaNum(skip, letters, inFile);
		break;
		
		case ALPHA : 
			GetAlpha(skip, letters, inFile);
		break;
		
		case NON_WHITE : 
			GetNonWhite(skip, letters, inFile);
		break;
		
		case NOT_NEW : 
			GetTilNew(skip, letters, inFile);
		break;
		
	}
}


void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile){
	// Post: If skip is true, non-alphanumeric letters are skipped.
	// Alphanumeric characters are read and stored until a
	// non-alphanumeric character is read or MAX_CHARS characters
	// have been stored. If the stream is not in the fail state,
	// the last character read was a non-alphanumeric character.

	using namespace std;
	char letter;
	int count = 0;
	
	if (skip){					// Skip non-alphanumeric characters.
		inFile.get(letter);
		
		while (!isalnum(letter) && inFile)
			inFile.get(letter);
		
	}
	else
		inFile.get(letter);
	
	if (!inFile || !isalnum(letter))	// No legal character found; empty string returned.
		letters[0] = '\0';
	else{						// Read and collect characters.
		do{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} 
		while(isalnum(letter) && inFile && (count < MAX_CHARS));
			letters[count] = '\0';
		
		if (count == MAX_CHARS && isalnum(letter)){
			do{
				inFile.get(letter);
			} 
			while (isalnum(letter) && inFile);
		}
	}
}

void GetAlpha(bool skip, char letters[], std::ifstream & inFile){
	// Post: If skip is true, non-alpha letters are skipped.
	// Alpha characters are read and stored until a
	// non-alpha character is read or MAX_CHARS characters
	// have been stored. If the stream is not in the fail state,
	// the last character read was a non-alpha character.
	using namespace std;
	char letter;
	int count = 0;

	if (skip) {					// Skip non-alpha characters.
		inFile.get(letter);

		while (!isalpha(letter) && inFile)
			inFile.get(letter);

	}
	else
		inFile.get(letter);

	if (!inFile || !isalpha(letter))	// No legal character found; empty string returned.
		letters[0] = '\0';
	else {						// Read and collect characters.
		do {
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} while (isalpha(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';

		if (count == MAX_CHARS && isalpha(letter)) {
			do {
				inFile.get(letter);
			} while (isalpha(letter) && inFile);
		}
	}
}

void GetNonWhite(bool skip, char letters[], std::ifstream & inFile){
	// Post: If skip is true, non-white-space letters are skipped.
	// white-space characters are read and stored until a
	// non-white-space character is read or MAX_CHARS characters
	// have been stored. If the stream is not in the fail state,
	// the last character read was a non-alpha character.
	using namespace std;
	char letter;
	int count = 0;

	if (skip) {					// Skip non-white-space characters.
		inFile.get(letter);

		while (isspace(letter) && inFile)
			inFile.get(letter);

	}
	else
		inFile.get(letter);

	if (!inFile || isspace(letter))	// No legal character found; empty string returned.
		letters[0] = '\0';
	else {						// Read and collect characters.
		do {
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} while (!isspace(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';

		if (count == MAX_CHARS && isspace(letter)) {
			do {
				inFile.get(letter);
			} while (!isspace(letter) && inFile);
		}
	}

}

void GetTilNew(bool skip, char letters[], std::ifstream& inFile){
	// Post: If skip is true, newline characters are skipped.
	// All characters are read and stored until a newline
	// character is read or MAX_CHARS characters have been
	// stored. If the stream is not in the fail state, the
	// last character read was a newline character.

	using namespace std;
	char letter;
	int count = 0;
	
	if (skip){			// Skip newlines.
		inFile.get(letter);
		while ((letter == '\n') &&inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	
	if (!inFile || letter == '\n')
		letters[0] = '\0';
	else{			// Read and collect characters.
		do{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} 
		while ((letter != '\n') && inFile && (count < MAX_CHARS));
			letters[count] = '\0';
		
		if (count == MAX_CHARS && letter != '\n') // Skip extra characters if necessary.
			do{
				inFile.get(letter);
			} 
			while ((letter != '\n') && inFile);
	}
}

void StrType::PrintToScreen(bool newLine){
	using namespace std;
	
	if (newLine)
		cout << endl;
	
	cout << letters;
}

void StrType::PrintToFile(bool newLine, std::ofstream & outFile){
	using namespace std;

	if (newLine)
		outFile << endl;

	outFile << letters;
}

void StrType::CopyString(StrType& newString){
	std::strcpy(newString.letters, letters);
}

int StrType::LengthIs(){
	return std::strlen(letters);
}