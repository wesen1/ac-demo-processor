/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_VOICECOMTEAM
#define PARSER_MESSAGE_VOICECOMTEAM

class Voicecomteam: public Message
{
  public:
    Voicecomteam(): Message(SV_VOICECOMTEAM)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int clientNumber;
    int voicecomSoundId;
};

#endif
