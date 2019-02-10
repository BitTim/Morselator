//BitTim Morselator
//Copyright (c) BitTim 2019
//
//Translate Morse Code into Normal Letters and vice versa!

#ifdef __linux__
int os = 1;
#endif

#ifdef _WIN64
int os = 2;
#endif

#ifdef _WIN32
int os = 2;
#endif

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool quit = false;
string raw_cmd, cmd, prefix = "";
string morse, text;

int argnum = 0;
vector<string> args;

void parse_cmd(string in, string &cmd, int &arg_count, vector<string> &arguments)
{
    arguments.clear();
    arg_count = 0;
    in += " ";
    cmd = "";

    string tmp;
    bool arg_mode = false;

    for(char c : in)
    {
        if(c != ' ' && !arg_mode) cmd += c;
        else if(c != ' ' && arg_mode) tmp += c;
        else if(c == ' ' && !arg_mode) arg_mode = true;
        else if(c == ' ' && arg_mode)
        {
            arg_count++;
            arguments.push_back(tmp);
            tmp = "";
        }
    }

    arg_mode = false;
}

string mtt(string morse_string)
{
    vector<char> letter;
    string text_string;
    int curr_pos = 0;

    for(char c : morse_string)
    {
        if(c == '.' || c == '-' || c == '/') letter.push_back(c);
        else if(c != ' ') return "err1";

        if(c == ' ')
        {
            string tmp(letter.begin(), letter.end());
            letter.clear();

            if(tmp == "/"    ) text_string += " "; else
            if(tmp == ".-"   ) text_string += "A"; else
            if(tmp == "-..." ) text_string += "B"; else
            if(tmp == "-.-." ) text_string += "C"; else
            if(tmp == "-.."  ) text_string += "D"; else
            if(tmp == "."    ) text_string += "E"; else
            if(tmp == "..-." ) text_string += "F"; else
            if(tmp == "--."  ) text_string += "G"; else
            if(tmp == "...." ) text_string += "H"; else
            if(tmp == ".."   ) text_string += "I"; else
            if(tmp == ".---" ) text_string += "J"; else
            if(tmp == "-.-"  ) text_string += "K"; else
            if(tmp == ".-.." ) text_string += "L"; else
            if(tmp == "--"   ) text_string += "M"; else
            if(tmp == "-."   ) text_string += "N"; else
            if(tmp == "---"  ) text_string += "O"; else
            if(tmp == ".--." ) text_string += "P"; else
            if(tmp == "--.-" ) text_string += "Q"; else
            if(tmp == ".-."  ) text_string += "R"; else
            if(tmp == "..."  ) text_string += "S"; else
            if(tmp == "-"    ) text_string += "T"; else
            if(tmp == "..-"  ) text_string += "U"; else
            if(tmp == "...-" ) text_string += "V"; else
            if(tmp == ".--"  ) text_string += "W"; else
            if(tmp == "-..-" ) text_string += "X"; else
            if(tmp == "-.--" ) text_string += "Y"; else
            if(tmp == "--.." ) text_string += "Z"; else
            if(tmp == ".----") text_string += "1"; else
            if(tmp == "..---") text_string += "2"; else
            if(tmp == "...--") text_string += "3"; else
            if(tmp == "....-") text_string += "4"; else
            if(tmp == ".....") text_string += "5"; else
            if(tmp == "-....") text_string += "6"; else
            if(tmp == "--...") text_string += "7"; else
            if(tmp == "---..") text_string += "8"; else
            if(tmp == "----.") text_string += "9"; else
            if(tmp == "-----") text_string += "0";
        }

        curr_pos++;
    }

    return text_string;
}

string ttm(string text_string)
{
    string morse_string;

    for(char c : text_string)
    {
        if(c == ' ') morse_string += "/ "    ; else
        if(c == 'A') morse_string += ".- "   ; else
        if(c == 'B') morse_string += "-... " ; else
        if(c == 'C') morse_string += "-.-. " ; else
        if(c == 'D') morse_string += "-.. "  ; else
        if(c == 'E') morse_string += ". "    ; else
        if(c == 'F') morse_string += "..-. " ; else
        if(c == 'G') morse_string += "--. "  ; else
        if(c == 'H') morse_string += ".... " ; else
        if(c == 'I') morse_string += ".. "   ; else
        if(c == 'J') morse_string += ".--- " ; else
        if(c == 'K') morse_string += "-.- "  ; else
        if(c == 'L') morse_string += ".-.. " ; else
        if(c == 'M') morse_string += "-- "   ; else
        if(c == 'N') morse_string += "-. "   ; else
        if(c == 'O') morse_string += "--- "  ; else
        if(c == 'P') morse_string += ".--. " ; else
        if(c == 'Q') morse_string += "--.- " ; else
        if(c == 'R') morse_string += ".-. "  ; else
        if(c == 'S') morse_string += "... "  ; else
        if(c == 'T') morse_string += "- "    ; else
        if(c == 'U') morse_string += "..- "  ; else
        if(c == 'V') morse_string += "...- " ; else
        if(c == 'W') morse_string += ".-- "  ; else
        if(c == 'X') morse_string += "-..- " ; else
        if(c == 'Y') morse_string += "-.-- " ; else
        if(c == 'Z') morse_string += "--.. " ; else
        if(c == '1') morse_string += ".---- "; else
        if(c == '2') morse_string += "..--- "; else
        if(c == '3') morse_string += "...-- "; else
        if(c == '4') morse_string += "....- "; else
        if(c == '5') morse_string += "..... "; else
        if(c == '6') morse_string += "-.... "; else
        if(c == '7') morse_string += "--... "; else
        if(c == '8') morse_string += "---.. "; else
        if(c == '9') morse_string += "----. "; else
        if(c == '0') morse_string += "----- "; else
        morse_string += "err1";
    }

    return morse_string;
}

int main()
{
    cout << endl << "Welcome to Morselator! Please enter \"help\" for a list of commands." << endl;
    while(!quit)
    {
        cout << prefix << "> ";

        cin.clear();
        fflush(stdin);

        getline(cin, raw_cmd);
        parse_cmd(raw_cmd, cmd, argnum, args);

        if(cmd == "help")
        {
            cout << endl;
            cout << "List of commands:" << endl;
            cout << "-----------------------------------" << endl;
            cout << "help  -  Display a list of commands" << endl;
            cout << "clr   -  Clear the Display" << endl;
            cout << "prefx -  Change the Prefix before the \'>\'" << endl;
            cout << "mtt   -  Convert Morse to Text" << endl;
            cout << "ttm   -  Convert Text to Morse" << endl;
            cout << "exit  -  Quit the Program" << endl << endl;
            cout << "Use \"<command> -h\" to get help for a specific command. Only some commands support this" << endl << endl;
        }
        else if(cmd == "mtt")
        {
            if(argnum > 1) cout << "Too many arguments" << endl;
            else if(argnum == 1)
            {
                if(args[0] == "-h")
                {
                    cout << endl;
                    cout << "Morse to Text Help" << endl;
                    cout << "----------------------------" << endl;
                    cout << "You just Enter a Morse String in the following format: " << endl;
                    cout << "Dots are represented by    \'.\'" << endl;
                    cout << "Dashes are represented by  \'-\'" << endl;
                    cout << "Spaces are represented by  \'/\'" << endl << endl;
                    cout << "Example: .... . .-.. .-.. --- / .-- --- .-. .-.. -.." << endl;
                    cout << "Returned by command: HELLO WORLD" << endl << endl;
                }
                else
                {
                    cout << "Unknown argument" << endl;
                }   
            }
            else if(argnum == 0)
            {
                cout << endl;
                cout << "Morse to Text" << endl;
                cout << "-----------------------" << endl;
                cout << "Enter the Morse String:" << endl;

                getline(cin, morse);
                text = mtt(morse + " ");

                cout << endl;
                cout << "Converted Text:" << endl;
                cout << text << endl << endl;
            }
        }
        else if(cmd == "ttm")
        {
            if(argnum > 1) cout << "Too many arguments" << endl;
            else if(argnum == 1)
            {
                if(args[0] == "-h")
                {
                    cout << endl;
                    cout << "Morse to Text Help" << endl;
                    cout << "----------------------------" << endl;
                    cout << "You just enter some Text in the following Format:" << endl;
                    cout << "It has to be all UPPERCASE" << endl;
                    cout << "It can only contain LETTERS and NUMBERS" << endl << endl;
                    cout << "Example: HELLO WORLD" << endl;
                    cout << "Returned by command: .... . .-.. .-.. --- / .-- --- .-. .-.. -.." << endl << endl;
                }
                else
                {
                    cout << "Unknown argument" << endl;
                }   
            }
            else if(argnum == 0)
            {
                cout << endl;
                cout << "Text to Morse" << endl;
                cout << "---------------" << endl;
                cout << "Enter the Text:" << endl;

                getline(cin, text);
                morse = ttm(text);

                cout << endl;
                cout << "Converted Morse String:" << endl;
                cout << morse << endl << endl;
            }
        }
        else if(cmd == "clr")
	{
	    if(os == 1) cout << "\033[2J\033[1;1H";
	    if(os == 2) system("cls");
	}
        else if(cmd == "prefx")
        {
            cout << "Please Enter a new Prefix: ";
            getline(cin, prefix);
        }
        else if(cmd == "exit") quit = true;
        else
        {
            cout << "Command not found. Enter \"help\" for a list of commands." << endl;
        } 
    }

    return 0;
}