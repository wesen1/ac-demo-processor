/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_EDITMODE
#define PARSER_MESSAGE_EDITMODE

class Editmode: public Message
{
  public:
    Editmode(): Message(SV_EDITMODE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int isEditModeEnabled;
};

#endif
