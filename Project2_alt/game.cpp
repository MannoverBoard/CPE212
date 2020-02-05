#include <iostream>
#include <fstream>
#include <string>
#include "character.hpp"
#include "inventory.hpp"
#include "rogue.hpp"
#include "mage.hpp"
#include "warrior.hpp"
#include "goblin.hpp"
#include "cleric.hpp"

#include <memory>
#include <map>
#include <functional>
using namespace std;

void Bar();

int main (int argc, char * const argv[])
{
    std::shared_ptr<Character> warrior{nullptr};
    std::shared_ptr<Character> cleric {nullptr};
    std::shared_ptr<Character> rogue  {nullptr};
    std::shared_ptr<Character> mage   {nullptr};
    std::shared_ptr<Character> goblin {nullptr};
    const std::map<char,decltype(warrior)*> char2char{
      {'w',&warrior},
      {'c',&cleric },
      {'r',&rogue  },
      {'m',&mage   },
      {'g',&goblin },
    };
    std::function<std::shared_ptr<Character>(const char c)> getChar = [&](const char c) {
      auto it = char2char.find(c);
      if(it!=char2char.end()) { return *(it->second); }
      return std::shared_ptr<Character>{};
    };
    const std::map<char,Race> char2race{
      {'h',Race::Human  },
      {'e',Race::Elf    },
      {'d',Race::Dwarf  },
      {'n',Race::Gnome  },
      {'g',Race::Goblin },
    };
    auto getRace = [&](const char c) {
      auto it = char2race.find(c);
      if(it==char2race.end()) { return Race::Human; }
      return it->second;
    };

    std::ifstream inputs;					     // Input file stream variable for test file
    char op, ch, r, d, c, a;							 // Hold operation and optional char input from test file
    std::string   comment;                      // Holds comment string input from test file
    std::string name;
    Race race;

    // Output usage message if test input file name is not provided
    if (argc != 2) {
      cout << "Usage:\n  Game  <inputfile>\n";
      return 1;
    }

    // Attempt to open test input file -- terminate if file does not open
    inputs.open(argv[1]);
    if (!inputs) {
      cout << "Error - unable to open input file" << endl;
      return 1;
    }

    // Process comment line from input file
    getline(inputs, comment);                          // Input file header comment
    cout << endl << comment << endl << endl;           // Output file header comment

    // Below is the primary loop that processes each operation appearing within the test file.
    // Starts with an initial priming read of first operation

    inputs >> op;				                         // Attempt to input first test operation from file

    while (inputs) {
      // While Not-EOF
      switch (op) {
      // Process operation input from test file
      case '#':   // Test file comment
        getline(inputs, comment);          // Input and echo the comment appearing in the test file
        cout << '#' << comment << endl;
        break;
      case 's':
        inputs >> c;    // Job Type to see the Status
        {
          const auto character = getChar(c);
          if(character!=nullptr) {
            character->Status();
          }
        }
        break;
      case 'i':
        inputs >> c;    // Job Type to see the Status
        {
          const auto character = getChar(c);
          if(character!=nullptr) {
            character->ShowInventory();
          }
        }
        break;

      case 'b':   // Print Bar
        Bar();         // Function definition appears at the end of this file
        break;

      case '+':   // Constructor
        inputs >> ch;     // Job to create
        inputs >> r;     // Race
        inputs >> name;   // Name

        race = getRace(r);
        try {
          switch (ch) {
          case 'w': warrior = make_shared<Warrior>(name, race); break;
          case 'm': mage    = make_shared<Mage   >(name, race); break;
          case 'r': rogue   = make_shared<Rogue  >(name, race); break;
          case 'c': cleric  = make_shared<Cleric >(name, race); break;
          case 'g': goblin  = make_shared<Goblin >(name, race); break;
          default:
            cout << "The game does not support that Job" << endl;
            break;
          }
        } catch ( ... ) {
          // Catch any exception thrown above
          cout << "Failed";
        }
        cout << endl;
        break;

      case '-':   // Destructor
        inputs >> d;
        switch (d) {
        case 'w': warrior = nullptr; break;
        case 'm': mage    = nullptr; break;
        case 'r': rogue   = nullptr; break;
        case 'c': cleric  = nullptr; break;
        case 'g': goblin  = nullptr; break;
        default:
          cout << "The game does not support that Job" << endl;
          break;
        }
        break;

      case 'a': // Attack
        inputs >> d;    // Target or Character Type: w, m, r, c
        inputs >> r;    // Attack method: a for regular and s or special class specific attack
        {
          auto actor = getChar(d);
          auto target = getChar('g');
          if(d=='g' || (d=='c' && r=='s')) {
            inputs >> c;
            target = getChar(c);
          }
          if(actor==nullptr || target==nullptr) { break; }
          if(r=='a') {
            actor->Attack(target);
          } else{
            actor->SpecialAttack(target);
          }
        }
        break;

      default:    // Error
        cout << "Error - unrecognized operation '" << op << "'" << endl;
        cout << "Terminating now..." << endl;
        return 1;
        break;
      }
      inputs >> op;	                                 // Attempt to input next command
    }
    return 0;
}

void Bar() {
    cout << "-------------------------" << endl;
}
