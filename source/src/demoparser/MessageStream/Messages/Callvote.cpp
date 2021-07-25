/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Callvote.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Callvote::extractDataFromBuffer(ucharbuf* _buffer)
{
  voteType = getint(*_buffer);

  if (voteType == -1)
  {
    voterClientNumber = getint(*_buffer);
    numberOfYesVotes = getint(*_buffer);
    numberOfNoVotes = getint(*_buffer);
    voteType = getint(*_buffer);
  }

  switch (voteType)
  {
    case SA_MAP:
      getstring(text, *_buffer);
      firstNumber = getint(*_buffer);
      secondNumber = getint(*_buffer);
      break;

    case SA_KICK:
    case SA_BAN:
      firstNumber = getint(*_buffer);
      getstring(text, *_buffer);
      break;

    case SA_SERVERDESC:
      getstring(text, *_buffer);
      break;

    case SA_STOPDEMO:
    case SA_REMBANS:
    case SA_SHUFFLETEAMS:
      break;

    case SA_FORCETEAM:
      firstNumber = getint(*_buffer);
      secondNumber = getint(*_buffer);
      break;

    default:
      firstNumber = getint(*_buffer);
      break;
  }
}
