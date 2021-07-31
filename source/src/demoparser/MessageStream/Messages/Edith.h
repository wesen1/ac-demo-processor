/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_EDITH
#define PARSER_MESSAGE_EDITH

class Edith: public Message
{
  public:
    using Message::Message;

    void extractDataFromBuffer(ucharbuf*);


    int x;
    int y;
    int xs;
    int ys;
    int v;
    int heightxy;
    int texxy;
};

#endif
