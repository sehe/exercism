#include "robot_name.h"
#include <random>
#include <set>
#include <mutex>
#include <thread>

using namespace std;

namespace robot_name {
    static mutex            protection;
    static set<std::string> known_used_names;

    std::string robot::generate_name() {
        lock_guard<mutex> lk(protection);
        // TODO exhaustion check?

        static mt19937 engine;
        static uniform_int_distribution<char> adist {'A','Z'};
        static uniform_int_distribution<char> ndist {'0','9'};
        auto alpha = [&] { return adist(engine); };
        auto digit = [&] { return ndist(engine); };

        do {
            std::string newly_generated;
            newly_generated += alpha();
            newly_generated += alpha();
            newly_generated += digit();
            newly_generated += digit();
            newly_generated += digit();

            if (known_used_names.insert(newly_generated).second)
                return newly_generated;
        } while (true); // TODO max effort?
    }

    std::string const& robot::name() const { return _name; }

    void robot::release_name() {
        lock_guard<mutex> lk(protection);
        known_used_names.erase(_name); // might check for empty name...
    }

    void robot::reset() {
        release_name();
        _name = generate_name();
    }

    robot::~robot() {
        release_name();
    }
}

