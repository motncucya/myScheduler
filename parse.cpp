#include "scheduler.hpp"

cmd_t which_cmd(string cmd) {
    if(cmd == "add") {
        return add_;
    }else if(cmd == "set") {
        return set_;
    }else if(cmd == "get") {
        return get_;
    }else if(cmd == "del") {
        return del_;
    }else if(cmd == "print") {
        return print_;
    }else if(cmd == "schedule") {
        return schedule_;
    }else if(cmd == "help") {
        return help_;
    }else if(cmd == "quit") {
        return quit_;
    }else{
        return unkown_;
    }
    return unkown_;
 }
