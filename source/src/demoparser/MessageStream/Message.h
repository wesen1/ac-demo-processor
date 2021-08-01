/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "cube.h"

#ifndef PARSER_MESSAGE
#define PARSER_MESSAGE

class Message
{
  private:
    int type;
    ucharbuf rawDataBuffer;
    Message* parentClientMessage;

  protected:
    int demoprotocol;

  public:
    Message(int);
    void setDemoProtocol(int);
    void setRawDataBuffer(ucharbuf);
    int getType();
    Message* getParentClientMessage();
    void setParentClientMessage(Message*);

    int getClientNumberFromParentClientMessage();
    const char* getTypeName();

    virtual void extractDataFromBuffer(ucharbuf*) = 0;
    virtual void writeToBuffer(ucharbuf*);
};

#endif
