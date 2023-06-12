/* prototype decralation */
#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <errno.h>
#include <string.h>
#include <filesystem>
#include <algorithm>

#define WORK_TIME 8 // work time (hour ) per day

#define PRIO 0
#define EVE_IDX 1
#define NAME 2

using namespace std;
namespace fs = std::filesystem;


enum cmd_t {
    add_,
    set_,
    get_,
    del_,
    print_,
    schedule_,
    help_,
    quit_,
    unkown_
};


class Tokens {
public:
    string cmd;
    int time;
    string name;
    int prio;
    // forward declarations
    Tokens();
    ~Tokens();
    int init(void);
};


// scheduler.cpp
cmd_t which_cmd(string cmd);
bool isFileExist(const std::string& name);
int do_add(string name, int time, int prio);
int do_set(string name, int time, int prio);
int do_get(string name);
int do_del(string name);
int do_schedule(void);


// show.cpp
void show_howtouse(void);
void show_events(void);
void show_help(void);
#endif