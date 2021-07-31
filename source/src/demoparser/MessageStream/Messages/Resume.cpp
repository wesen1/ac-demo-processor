/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Resume.h"


// Public Methods

/**
 * Extracts the values for this message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message values from
 */
void Resume::extractDataFromBuffer(ucharbuf* _buffer)
{
  loopi(MAXCLIENTS)
  {
    int cn = getint(*_buffer);
    if(_buffer->overread() || cn < 0) break;
    int state = getint(*_buffer),
        lifesequence = getint(*_buffer),
        primary = getint(*_buffer),
        gunselect = getint(*_buffer),
        flagscore = getint(*_buffer),
        frags = getint(*_buffer),
        deaths = getint(*_buffer),
        health = getint(*_buffer),
        armour = getint(*_buffer),
        points = getint(*_buffer);

    int teamkills;
    if(demoprotocol > 1132) teamkills = getint(*_buffer);

    int ammo[NUMGUNS], mag[NUMGUNS];
    loopi(NUMGUNS) ammo[i] = getint(*_buffer);
    loopi(NUMGUNS) mag[i] = getint(*_buffer);
  }
}
