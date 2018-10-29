/**************************************************************
 * Filename: testDeque.cc
 * Author: Hayden Ivatts
 * Professor Kadady MWF 1 to 1:50
 * Date: 10/15/18 
 * HW 3
 * Course: CSCI 132
 * Purpose: Test deque functions
 **************************************************************/

#include <iostream>
#include <string>
#include <locale>
#include "deque.h"

using namespace std;

char get_command();
void help();
bool do_command(char, Deque &);

/* Post: Accepts commands from user as a menu-driven demonstration program
   for the class deque.
   Uses: The class deque and the functions introduction, get_command,
   and do_command. 
*/
int main( ) {
    Deque test_deque;
    help( );
    while (do_command(get_command( ), test_deque));
} // end main( )

void help()
/*
  Post: A help screen for the program is printed, giving the meaning of each
  command that the user may enter.
*/
{
    cout << endl
         << "This program allows the user to enter one command" << endl
         << "(but only one)on each input line." << endl
         << "For example, if the command S is entered, then" << endl
         << "the program will serve the front of the queue." << endl
         << endl
         << " The valid commands are:" << endl
         << "A - Append the next input character to the rear." << endl
         << "P - Push the next input character to the front." << endl
         << "S - Serve the front of the queue" << endl
         << "X - Extract the rear of the queue" << endl
         << "R - Retrieve and print the front entry." << endl
         << "W - Retrieve and write the rear entry." << endl
         << "H - This help screen" << endl
         << "Q - Quit" << endl
         << "Press <Enter> to continue." << flush;

    char c;
    do {
        cin.get(c);
    } while (c != '\n');
}  //end help( )

bool do_command(char c, Deque &test_deque)
/*
  Pre: c represents a valid command.
  Post: Performs the given command c on the Deque test_deque.
  Returns false if c == 'q', otherwise returns true.
  Uses: The class Deque.
*/
{
    bool continue_input = true;
    Queue_entry x;
    //Depending on command entered, switch tests is the deque functions properly
 switch (c){
    case 'h': help();
        break;
    case 'q':
        cout << "Deque demonstration finished." << endl;
        continue_input = false;
        break;
    case 'a':
        cout << "Enter new key to insert:";
        cin >> x;
        if(test_deque.append_rear(x) == overflow) {
            cout << "Deque is full." << endl;
        } else {
            cout << x << " appended to rear of deque." << endl;
        }
        cout << endl;
        break;
    case 'p':
        cout << "Enter new key to insert:";
        cin >> x;
        if(test_deque.append_front(x) == overflow) {
            cout << "Deque is full." << endl;
        } else {
            cout << x << " appended to front of deque." << endl;
        }
        cout << endl;
        break;
    case 's':
        if(test_deque.serve_front() == underflow) {
            cout << "Serve failed, the Deque is empty." << endl;
        } else {
            cout << "Successfully served the front of the deque." << endl;
        }
        cout << endl;
        break;
    case 'x':
        if(test_deque.serve_rear() == underflow) {
            cout << "Serve failed, the Deque is empty." << endl;
        } else {
            cout << "Successfully served the rear of the deque." << endl;
        }
        cout << endl;
        break;
    case 'r':
        if(test_deque.retrieve_front(x) == underflow) {
            cout << "Deque is empty." << endl;
        } else {
            cout << "The first entry is: " << x << endl;
        }
        cout << endl;
        break;
    case 'w':
        if(test_deque.retrieve_rear(x) == underflow) {
            cout << "Deque is empty." << endl;
        } else {
            cout << "The last entry is: " << x << endl;
        }
        cout << endl;
        break;
    } //end switch on deque option

    return continue_input;
} //end do_command()

char get_command()
/*
  Post: Gets a valid command from the user and,
  after converting it to lower case if necessary,
  returns it.
*/
{
    cout << "Select command and press <Enter>:";
    char c; //Char that stores user input
    cin >> c;
    c = tolower(c);
    //Tests to see if the user input is valid. If it is not, enter again.
    while(c != 'a' && c != 'p' && c != 's' && c != 'x' && c != 'r' && c != 'w'
          && c != 'h' && c != 'q') {
        cout << "Please enter a valid command:";
        cin >> c;
        c = tolower(c);
    }
    return c;
} //end get_command

