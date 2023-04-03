#include <../include/kittyLogs/log.h>
#include <iostream>

int main()
{
    kittyLogs::logger::init(kittyLogs::logger::consoleSink);
    kittyLogs::logger::init(kittyLogs::logger::networkSink);

    _KI("dupa", "KOT info " << 1234);
    _KW("dupa", "KOT warning " << 1234);
    _KE("dupa", "KOT error " << 1234);

    _KI("dupa", "KOT info " << 1234);
    _KW("dupa", "KOT warning " << 1234);
    _KE("dupa", "KOT error " << 1234);
    return 0;
}
