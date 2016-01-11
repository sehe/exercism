#pragma once
#include <string>

namespace  robot_name {
    struct robot {
        robot(robot const&) = delete;
        robot() = default;

        std::string const& name() const;
        void reset();
        ~robot();
      private:
        static std::string generate_name();
        void release_name();
        std::string _name = generate_name();
    };

}
