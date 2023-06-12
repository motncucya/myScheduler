#include "scheduler.hpp"
void show_howtouse(void) {
    cout << "input \"help\" to get information" << endl;
}

void show_events(void) {
    string s;
    for ( const fs::directory_entry& e : fs::directory_iterator("events/") ) {
      ifstream fevent(e.path());
      getline(fevent, s);
      istringstream iss(s);
      iss >> s;
      cout << s << " ";
      iss >> s;
      cout << s << " ";
      iss >> s;
      cout << s << " " << endl;
    }
}

void show_help(void) {
    cout << "add <name> <time> <priority>    : add a new event" << endl;
    cout << "set <name> <time> <priority>    : change an existing event" << endl;
    cout << "del <name>                      : delete an existing event" << endl;
    cout << "get <name>                      : get an existing event" << endl;
    cout << "print                           : print all the events" << endl;
    cout << "schedule                        : split the work time based on the share of the priorities" << endl;
    cout << "help                            : print this help" << endl;
    cout << "quit                            : quit myScheduler" << endl;
}