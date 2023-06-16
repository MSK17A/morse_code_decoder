#include <string>
#include "map"
#include "morse.h"

std::string decodeMorse(std::string morseCode) {
    // ToDo: Accept dots, dashes and spaces, return human-readable message
    std::map<std::string, char> MORSE_CODE;
    MORSE_CODE_MAP_INIT(MORSE_CODE);
    std::string str = "";
    int space_counter = 0;          // Count the spaces in order to decide the space
    bool put_space = false;         // Flags whether to put space or not
    bool start_of_string = false;   // Flags the start of the string
    std::string decoded;

    int index = 0;

    for( auto p : morseCode ) {
      // if it is not a space then added to the string.
      if (p != ' ') {
        start_of_string = true;
        if (put_space) {
          decoded += " ";
          put_space = false;
        }
        str += p;
        space_counter = 0;
      }
      // if it a space then count it and get the corresponded letter from the string str.
      if (p == ' ') {
        space_counter++;
        decoded += MORSE_CODE[str];
        str = "";
      }
      // If the spaces repeated in a row more than 2 times then add a space intro the decoded string.
      if (space_counter > 2 && !put_space && start_of_string) {
        put_space = true;
      }
      // Adds the last letter in a string.
      if (index == morseCode.size() -1 && p != ' ') {
        decoded += MORSE_CODE[str];
      }
      index++;
    }
    return decoded;
}