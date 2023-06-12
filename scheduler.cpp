#include "scheduler.hpp"

string dir = "events/";
Tokens::Tokens() {
    cmd = "";
    time = -1;
    name = "";
    prio = -1;
}

Tokens:: ~Tokens() {

}
int Tokens::init() {
    cmd = "";
    time = -1;
    name = "";
    prio = -1;
    return 0;
}

/*
Events::Events() {
    time = {};
    name = {};
    prio = {};
}

Events::~Events() {
}
*/

bool isEventExist(const std::string& name) {
    return fs::is_regular_file(name);
}


int do_add(string name, int time, int prio) {
    // check each token.
    if(time < 0) {
        cerr << "error: <time> must be non-negative" << endl;
        return -1;
    }
    if(prio < 0) {
        cerr << "error: <priority> must be non-negative" << endl;
        return -1;
    }
    string path = dir + name;
    if(isEventExist(path)) {
        cerr << "error" << name << " already exist" << endl;
        return -1;
    }
    // make a file to record an event
    ofstream new_event;
    new_event.open(path);
    if(!new_event) {
        cerr << "error: new event cannot create" << endl;
        return -1;
    }
    // fname is <name>
    new_event << name << " " << time << " " << prio << endl;
    new_event.close();
    return 0;
}

int do_set(string name, int time, int prio) {
    // do_del;
    if(do_del(name) != 0) {
        return -1;
    }
    if(do_add(name, time, prio)) {
        return -1;
    }
    // do_add;
    /*
    cout << "do_set" << endl;
    string path = dir + name;
    if(!isEventExist(path)) {
        cout << name << " does not exist" << endl;
        return -1;
    }
    ifstream event(path);
    // open file named <name>

    // change <time> or <priority>
    event.close();
    */
    return 0;
}

int do_get(string name) {
    string path = dir + name;
    // open file name <name>
    ifstream file(path);
    if(!isEventExist(path)) {
        cerr << "error: " << name << " does not exist" << endl;
        return -1;
    }
    // show <name> <time> <prio>
    string str;
    getline(file, str);
    cout << str << endl;
    return 0;
}

int do_del(string name) {
    string path = dir + name;
    if(!isEventExist(path)) {
        cerr << "error: " << name << " does not exist" << endl;
        return -1;
    }
    if(remove(path.c_str()) != 0) {
        cerr << "error: cannot delete " << name << endl;
        printf("fopen error(%s)\n", strerror(errno));
    }
    return 0;
}

int do_schedule(void) {
    string s;
    int cnt = 0;
    int prio_sum = 0;
    vector<tuple<int, int, string>> events;
    // get the <name> and <prio> of all the events
    for (const fs::directory_entry& e : fs::directory_iterator("events/") ) {
      ifstream fevent(e.path());
      getline(fevent, s);
      istringstream iss(s);
      tuple<int,int,string> new_event{-1,-1,""};
      iss >> s;
      get<NAME>(new_event) = s;
      iss >> s;
      get<EVE_IDX>(new_event) = cnt++;
      iss >> s;
      get<PRIO>(new_event) = atoi(s.c_str());
      events.push_back(new_event);
    }
    // record_i consists of record.name[i], record.time[i], record.prio[i].
    
    // ascending
    // sort(events.begin(),events.end());
    // descending
    sort(events.rbegin(),events.rend()); // ordering by priority

    for(int i=0;i<events.size();i++) {
        prio_sum += get<PRIO>(events[i]);
    }
    if(prio_sum == 0) {
         for(int i=0;i<events.size();i++) {
            cout << get<NAME>(events[i]) << " " << 0 << "h" << endl;
        }
    }else{
        for(int i=0;i<events.size();i++) {
            cout << get<NAME>(events[i]) << " " << WORK_TIME*((double)get<PRIO>(events[i])/(double)prio_sum) << "h" << endl;
        }
    }
    
    return 0;
}
