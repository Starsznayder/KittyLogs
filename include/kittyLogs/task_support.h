#ifndef KITTY_LOGS_DETAILS_TASK_SUPPORT_H
#define KITTY_LOGS_DETAILS_TASK_SUPPORT_H

#include "Logger.h"

#define LOGGER_ADD_TASK_NAME(name) BOOST_LOG_SCOPED_THREAD_ATTR("Task", attrs::constant<std::string>(name));

#endif // KITTY_LOGS_TASK_SUPPORT_H
