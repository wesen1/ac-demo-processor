/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_EDITENT
#define PARSER_MESSAGE_EDITENT

class Editent: public Message
{
  public:
    Editent(): Message(SV_EDITENT)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    unsigned int entityIndex;
    int type;
    int x;
    int y;
    int z;
    int attr1;
    int attr2;
    int attr3;
    int attr4;
};

#endif
