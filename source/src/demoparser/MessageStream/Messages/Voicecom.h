/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_VOICECOM
#define PARSER_MESSAGE_VOICECOM

class Voicecom: public Message
{
  public:
    Voicecom(): Message(SV_VOICECOM)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int voicecomSoundId;
};

#endif
