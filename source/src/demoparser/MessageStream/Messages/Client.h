/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"
#include <vector>

#ifndef PARSER_MESSAGE_CLIENT
#define PARSER_MESSAGE_CLIENT

class Client: public Message
{
  private:
    std::vector<Message*> childMessages;

  public:
    Client(): Message(SV_CLIENT)
    {
    }

    void addChildMessage(Message*);
    void removeChildMessage(Message*);

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    ucharbuf clientMessagesBuffer;
};

#endif
