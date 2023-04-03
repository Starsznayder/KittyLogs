#ifndef KITTY_LOGS_LOG_H
#define KITTY_LOGS_LOG_H

#include "Logger.h"
#include "task_support.h"
#include <boost/log/utility/manipulators/add_value.hpp>

namespace kittyLogs {

using logger = kittyLogs::Logger<>;

}

#define CL_(lvl, proc) BOOST_LOG_NAMED_SCOPE(__FUNCTION__) \
BOOST_LOG_SEV((kittyLogs::logger::get()), lvl ) << boost::log::add_value("File", kittyLogs::logger::CutFilePath(__FILE__)) \
                                          << boost::log::add_value("Line", __LINE__) \
                                          << boost::log::add_value("Function", __FUNCTION__) \
                                          << boost::log::add_value("Process", proc)

//Rozwiązanie bezpieczne
#define _Dsafety(type, proc, message) {std::ostringstream ss; ss << message; CL_(type, proc) << ss.str();}
#define _KI(proc, message) _Dsafety(kittyLogs::logger::level_type::info, proc, message)
#define _KW(proc, message) _Dsafety(kittyLogs::logger::level_type::warning, proc, message)
#define _KE(proc, message) _Dsafety(kittyLogs::logger::level_type::error, proc, message)

#endif /* KITTY_LOGS_LOG_H */
