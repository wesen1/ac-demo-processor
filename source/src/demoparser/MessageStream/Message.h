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
    Message* parentClientMessage;

  protected:
    int demoprotocol;

  public:
    Message(int);
    void setDemoProtocol(int);
    int getType();
    void setParentClientMessage(Message*);
    int getClientNumberFromParentClientMessage();
    const char* getTypeName();

    virtual void extractDataFromBuffer(ucharbuf*) = 0;
};

#endif
