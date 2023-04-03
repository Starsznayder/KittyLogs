#ifndef KITTY_LOGS_DETAILS_COLOR_H
#define KITTY_LOGS_DETAILS_COLOR_H

#include <boost/log/trivial.hpp>

namespace kittyLogs {
namespace details {

struct Color
{
    using value_type = const char*;
    constexpr static const char* RESET = "\033[0m";
    constexpr static const char* RED = "\033[31m";
    constexpr static const char* GREEN = "\033[32m";
    constexpr static const char* YELLOW  = "\033[33m";
};

namespace logging = boost::log;

template <typename Level = logging::trivial::severity_level>
Color::value_type severityColor(Level lvl)
{
    switch (lvl)
    {
    case Level::info:
        return Color::GREEN;
    case Level::warning:
        return Color::YELLOW;
    case Level::error:
        return Color::RED;
    default:
        return Color::RESET;
    }
}

}
}

#endif /* KITTY_LOGS_DETAILS_COLOR_H */
