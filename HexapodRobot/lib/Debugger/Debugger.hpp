#ifndef DEBUGGER_HPP
#define DEBUGGER_HPP

#include <Arduino.h>

String FormatString(const char* format, ...)
{
    String stg;
	char buffer[256];
    va_list argptr;
    va_start(argptr, format);
    vsnprintf (buffer, 255, format, argptr);
	stg = String(buffer);
    va_end(argptr);
    return stg;
}

void DebuggerPrint(const char * format, ...)
{
	char buffer[256];
    va_list argptr;
    va_start(argptr, format);
    vsnprintf (buffer, 255, format, argptr);
	Serial.print(buffer);
    va_end(argptr);
}

#endif