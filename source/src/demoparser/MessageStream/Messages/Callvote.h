/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../Message.h"

#ifndef PARSER_MESSAGE_CALLVOTE
#define PARSER_MESSAGE_CALLVOTE

class Callvote: public Message
{
  public:
    Callvote(): Message(SV_CALLVOTE)
    {
    }

    void extractDataFromBuffer(ucharbuf*);


    int voteType;
    int voterClientNumber;
    int numberOfYesVotes;
    int numberOfNoVotes;

    int firstNumber;
    int secondNumber;

    /*
     * SA_MAP: Map name
     * SA_KICK, SA_BAN: Reason
     * SA_SERVERDESC: Description
     */
    char text[MAXTRANS];
};

#endif
