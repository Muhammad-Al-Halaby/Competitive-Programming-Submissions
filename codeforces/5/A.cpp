#include <iostream>
#include <string>

using namespace std;

int main(){
    string command;
    getline(cin, command);
    int people = 0;
    int amount = 0;
    while (command != "") {
        if(command != ""){
            if(command.find('+') != string::npos){
                    people++;
            }
            else if(command.find('-') != string::npos){
                people--;
            }
            else if(command.find(':') != string::npos){
                int pos = command.find(':');
                string message = command.substr(pos+1,command.length()-1);
                amount += people * message.length();
            }
        }
                getline(cin, command);
    }
    cout << amount << endl;
}