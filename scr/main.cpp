// Victoria Avila
// Cis-7, discrete Structures
// Due 12/10/23
// Final Project Case 3: Vigenere Cipher Decryption
// Program used: Replit

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void introToProject();
string getUserName();
void userMenu();
void decryptMsg();
void encryptMsg();

int main() 
{
  int choice;
  
  introToProject();
  string userName = getUserName(); 
  
  do {
    userMenu();
    cin >> choice;
    switch (choice) {
      case 1:
        encryptMsg();
        break;
      case 2:
        decryptMsg();
        break;
      case 3:
        cout << "Exiting program. Goodbye " << userName << "!" << endl;
        break;
      default:
        cout << "Invalid choice. Please only enter a number between 1 and 3." << endl;
    }
      
  } while (choice != 3);
  return 0;
}

//===================================
// introduces the user to the program 
// and its purpose
//===================================
void introToProject()
{
  cout << "Hello, welcome to the Vigenere Cipher Decryption Program.\n";
  cout << "This program will decrypt or encrypt a message for you.\n";
}

//===================================
// asks the user for their name for 
// a personalized experience
//===================================
string getUserName()
{
  string name, correctName;
  char yesNo;
  cout << "To proceed, please Enter your name: ";
  do {
    cin >> name;

    cout << "\nYou entered: " << name << endl;
    cout << "Is this correct? (y/n): ";
    cin >> yesNo;

    if (yesNo != 'y' && 'Y')
    {
      cout << "REenter your name: ";
    }
    else
    {
      correctName = name;
    }
  } while (yesNo != 'y' && 'Y');
  
  cout << "\nHello " << name << ", Nice to meet you.\n";
  return name;
}

//===================================
// provides 3 options for the user to
// select. en/decrypt, or to exit
//===================================
void userMenu()
{
  cout << "\nPlease select an option from the menu:\n";
  cout << "1. encrypt a message\n";
  cout << "2. decrypt a message\n";
  cout << "3. exit program\n";
  cout << "Enter your choice: (1-3): ";
}
//===================================
// collects user's input for the
// plain text and key
//===================================

void encryptMsg()
{
  //state user choice
  cout << "You have selected: encrypt a message.\n";
  
  string plain, keyword, result;
  
  // give user instructions
  cout << "\nThe program will now ask for plain text and keyword.\n";
  cout << "Please enter the following text in only uppercase & alphabetical characters.\n";

  // plain text prompt
  cout << "\nPlease input text: ";
  cin >> plain;
  // prompt user for keyword
  cout << "Next, enter a keyword. Do not use spaces: ";
  cin >> keyword;

  //display user input
  cout << "\nYou have entered the following text: \n";
  cout << "Plain text: " << plain << endl;
  cout << "Keyword: " << keyword << endl;

  //encryption begins
  int keyLength = keyword.length();
  int plainLength = plain.length();

  // Generate the key
    string generatedKey;
    for (int i = 0; i < plainLength; ++i) {
        generatedKey += keyword[i % keyLength];
    }

    // Encrypt the message
    for (int i = 0; i < plainLength; ++i) {
        char c = plain[i];
        if (isalpha(c)) {
            char shift = isupper(c) ? 'A' : 'a';
            char encryptedChar = (c - shift + generatedKey[i] - 'A') % 26 + shift;
            result += encryptedChar;
        } else {
            result += c;
        }
    }

    // Display result
    cout << "\nEncrypted message: " << result << endl;
}

void decryptMsg()
{
  string encrypted, keyword, result;
  //state user choice
  cout << "You have selected: decrypt a message.\n";

  cout << "\nThe program will now ask for encrypted text and keyword.\n";
  cout << "Please enter the following text in only uppercase & alphabetical characters.\n";

  cout << "Input encrypted text: ";
  cin >> encrypted;
  cout << "Input keyword: ";
  cin >> keyword;

  //display user input
  cout << "\nYou have entered the following text: \n";
  cout << "Encrypted text: " << encrypted << endl;
  cout << "Keyword: " << keyword << endl;

  //decrypt begins here
  int keyLength = keyword.length();
  int encryptedLength = encrypted.length();

  string generatedKey;
  for (int i = 0; i < encryptedLength; ++i) 
    {
      generatedKey += keyword[i % keyLength];
    }

  for (int i = 0; i < encryptedLength; ++i) {
    char c = encrypted[i];
    if (isalpha(c)) {
        char shift = isupper(c) ? 'A' : 'a';
        char decryptedChar = (c - shift - (generatedKey[i] - 'A') + 26) % 26 + shift;
        result += decryptedChar;
    } else {
        result += c;
    }
  }
  // Display result
  cout << "\nDecrypted message: " << result << std::endl;
}