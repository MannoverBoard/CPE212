#include "project01.hpp"

#include <iostream>
#include <fstream>


// prints the matrix.
// if a 1 is found in the slot, print a "*"
// if a 0 is found int he slot, print a "0"
// if a -1 is found, print a "-"
// otherwise, print an "X"
void Print(const Image& image);
void Bars();

using namespace std;

int main(int argc, char * const argv[])
{

    // Output usage message if test input file name is not provided
    if (argc != 2)
    {
        cout << "Usage:\n  project01  <inputfile>\n";
        return -1;
    }

    ifstream input;
    // Attempt to open test input file -- terminate if file does not open
    input.open(argv[1]);
    if (!input)
    {
        cout << "Error - unable to open input file" << endl;
        return 1;
    }

    Image image;
    string line;
    getline(input, line);

    cout << endl << line << endl << endl;
    // main loop goes here
    char op;
    input >> op;
    while(input)
    {
        switch(op)
        {
            case '#':
                getline(input, line);
                cout << "# " << line << endl;
                break;
            case 'p':
                Print(image);
                break;

            case 'b':
                Bars();
                break;

            case 'i':
            {
                string imageFile;
                input >> imageFile;
                if(!LoadImage(imageFile, image))
                {
                    cout << "Invalidly caught a return false";
                }
                break;
            }
            /*
            case '+':
                if(!Rotate(image, Rotation::Clockwise))
                {
                    cout << "Invalidly caught a return false";
                }

                break;

            case '-':
                if(!Rotate(image, Rotation::CounterClockwise))
                {
                    cout << "Invalidly caught a return false";
                }
                break;

            case 'v':
                if(!Flip(image, Direction::Vertical))
                {
                    cout << "Invalidly caught a return false";
                }
                break;
            case 'h':
                if(!Flip(image, Direction::Horizontal))
                {
                    cout << "Invalidly caught a return false";
                }
                break;
            case 't':
                Transpose(image);
                break;
            default:
                cout << "Unrecognized command: " << op << endl;
                cout << "Terminating" << endl;
                return -2;
                break;
                */
        }
        cout << endl;
        input >> op;
    }

    return 0;
}

/// DO NOT MODIFY THIS CODE


void Print(const Image& image) {
  for(int r = 0; r < arrayLen(image.data); ++r) {
    for(int c = 0; c < arrayLen(image.data[0]);++c) {
      switch(image.data[r][c]) {
        case 1:  cout << "*"; break;
        case 0:  cout << "-"; break;
        default: cout << "X"; break;
      }
    }
    cout << '\n';
  }
}

void Bars() {
  cout << "#################################################################\n"
       << "#################################################################"
       << endl;
}
