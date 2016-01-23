#include "SimpleJSON.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <alloca.h>

#define JSON_OPENING "{"
#define JSON_CLOSING "}"
#define JSON_SEPERATOR ":"
#define JSON_VALUE_SEPERATOR ","

void writeJsonOpening(char* buffer)
{
  sprintf(buffer, JSON_OPENING);
}

void writeJsonString(char* buffer, const char* name, const char* value)
{
  if(strlen(buffer) != strlen(JSON_OPENING))
    {
      strcat(buffer + strlen(buffer), JSON_VALUE_SEPERATOR);
    }
  sprintf(buffer + strlen(buffer), "%s%s%s%s", "\"", name, "\"", "\0");
  sprintf(buffer + strlen(buffer), "%s%s", JSON_SEPERATOR, "\0");
  sprintf(buffer + strlen(buffer), "%s%s%s%s", "\"", value, "\"", "\0");
}

void writeJsonString(char* buffer, const char* name, int value)
{
  int valueLength = integerLength(value);
  char* valueBuffer = (char*)alloca(integerLength(value));
  itoa(value, valueBuffer, 10);
  writeJsonString(buffer, name, valueBuffer);
}

void writeJsonClosing(char* buffer)
{
  sprintf(buffer  + strlen(buffer), JSON_CLOSING);
}
