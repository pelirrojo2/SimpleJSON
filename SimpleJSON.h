#ifndef _SIMPLE_JSON_H_
#define _SIMPLE_JSON_H_

void writeJsonOpening(char* buffer);
void writeJsonString(char* buffer, const char* name, const char* value);
void writeJsonString(char* buffer, const char* name, int value);
void writeJsonClosing(char* buffer);

#endif
