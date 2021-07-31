/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_SOUND
#define PARSER_MESSAGE_SOUND

class Sound: public Message
{
  public:
    Sound(): Message(SV_SOUND)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int soundId;
};

#endif
