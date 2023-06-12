#include "scheduler.hpp"
int main(int argc, char* argv[]) {
    string buf;
    Tokens tokens;
    show_howtouse();
    while(1) {
        // init tokens
        if(tokens.init()) {
            cerr << "tokens init failed" << endl;
            exit(1);
        }
        // get a input
        cout << "> ";
        getline(cin,buf);
        istringstream iss(buf);
        // split the buf into the tokens
        iss >> tokens.cmd >> tokens.name >> tokens.time >> tokens.prio;
        
        // process the command
        switch(which_cmd(tokens.cmd)) {
            case add_:
                // check each token.
                do_add(tokens.name, tokens.time, tokens.prio);
                break;
            case set_:
                do_set(tokens.name, tokens.time, tokens.prio);
                break;
            case get_:
                do_get(tokens.name);
                break;
            case del_:
                do_del(tokens.name);
                break;
            case print_:
                show_events();
                break;
            case schedule_:
                do_schedule();
                break;
            case help_:
                show_help();
                break;
            case quit_:
                exit(0);
                break;
            default:
                cout << "unkown" << endl;
                break;
        }
    }
    exit(0);
}