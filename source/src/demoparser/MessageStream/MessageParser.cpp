/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "MessageParser.h"
#include "Messages/Arenawin.h"
#include "Messages/Authchal.h"
#include "Messages/Authreq.h"
#include "Messages/Callvoteerr.h"
#include "Messages/Callvote.h"
#include "Messages/Callvotesuc.h"
#include "Messages/Cdis.h"
#include "Messages/Client.h"
#include "Messages/Clientping.h"
#include "Messages/Discscores.h"
#include "Messages/Editent.h"
#include "Messages/Edith.h"
#include "Messages/Editmode.h"
#include "Messages/Flagcnt.h"
#include "Messages/Flaginfo.h"
#include "Messages/Flagmsg.h"
#include "Messages/Forcedeath.h"
#include "Messages/Gamemode.h"
#include "Messages/Gibdamage.h"
#include "Messages/Gibdied.h"
#include "Messages/Hitpush.h"
#include "Messages/Hudextras.h"
#include "Messages/Initclient.h"
#include "Messages/Iplist.h"
#include "Messages/Itemacc.h"
#include "Messages/Itemlist.h"
#include "Messages/Itemspawn.h"
#include "Messages/Mapchange.h"
#include "Messages/Mapident.h"
#include "Messages/Newmap.h"
#include "Messages/Points.h"
#include "Messages/Pong.h"
#include "Messages/Reload.h"
#include "Messages/Resume.h"
#include "Messages/Senddemolist.h"
#include "Messages/Servermode.h"
#include "Messages/Servinfo.h"
#include "Messages/Servmsg.h"
#include "Messages/Servopinfo.h"
#include "Messages/Setteam.h"
#include "Messages/Shotfx.h"
#include "Messages/Sound.h"
#include "Messages/Spawndeny.h"
#include "Messages/Spawn.h"
#include "Messages/Spawnstate.h"
#include "Messages/Switchname.h"
#include "Messages/Switchskin.h"
#include "Messages/Switchteam.h"
#include "Messages/Teamdeny.h"
#include "Messages/Teamtextme.h"
#include "Messages/Textme.h"
#include "Messages/Textprivate.h"
#include "Messages/Thrownade.h"
#include "Messages/Timeup.h"
#include "Messages/Voicecom.h"
#include "Messages/Voicecomteam.h"
#include "Messages/Vote.h"
#include "Messages/Voteresult.h"
#include "Messages/Weapchange.h"
#include "Messages/Welcome.h"
#include "NullMessage.h"


/**
 * MessageParser constructor.
 *
 * @param int _demoprotocol The protocol version of the demo
 */
MessageParser::MessageParser(int _demoprotocol)
{
  demoprotocol = _demoprotocol;
}


// Public Methods

/**
 * Extracts and returns the next message from a given buffer.
 *
 * @param int _channel The channel of the message
 * @param ucharbuf _buffer The buffer to extract the message from
 *
 * @return Message The next message from the given buffer
 */
Message* MessageParser::parseNextMessageFromBuffer(int _channel, ucharbuf* _buffer)
{
  if (_channel == 0) return parseNextMessageFromPositionMessagesBuffer(_buffer);
  else if (_channel == 1) return parseNextMessageFromGeneralMessagesBuffer(_buffer);
  else if (_channel == 2) return parseNextMessageFromFileTransmissionMessagesBuffer(_buffer);
  else
  { // Unknown channel
    clientlogf("Unknown channel %d", _channel);
    return NULL;
  }
}


// Private Methods

/**
 * Extracts and returns the next position channel message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message from
 *
 * @return Message The next message from the given buffer
 */
Message* MessageParser::parseNextMessageFromPositionMessagesBuffer(ucharbuf* _buffer)
{ // Position messages are not needed yet, so not implemented
  //clientlogf("Skipped channel (position messages)");
  return NULL;
}

/**
 * Extracts and returns the next general channel message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message from
 *
 * @return Message The next message from the given buffer
 */
Message* MessageParser::parseNextMessageFromGeneralMessagesBuffer(ucharbuf* _buffer)
{
  int type = getint(*_buffer);
  if(demoprotocol == 1132)
  {
    if(type > SV_IPLIST) --type;            // SV_WHOIS removed
    if(type >= SV_TEXTPRIVATE) ++type;      // SV_TEXTPRIVATE added
    if(type == SV_SWITCHNAME)               // SV_SPECTCN removed
    {
      getint(*_buffer);
      return new NullMessage(-99);
    }
    else if(type > SV_SWITCHNAME) --type;
  }


  Message* message = createMessageForMessageType(type);
  message->setDemoProtocol(demoprotocol);
  message->extractDataFromBuffer(_buffer);

  return message;
}

/**
 * Extracts and returns the next file transmission channel message from a given buffer.
 *
 * @param ucharbuf _buffer The buffer to extract the message from
 *
 * @return Message The next message from the given buffer
 */
Message* MessageParser::parseNextMessageFromFileTransmissionMessagesBuffer(ucharbuf* _buffer)
{ // File transmission messages are not needed yet, so not implemented
  return NULL;
}

/**
 * Creates and returns a Message instance from a given message type constant.
 *
 * @param int _type The message type constant
 *
 * @return Message An instance of the corresponding Message class
 */
Message* MessageParser::createMessageForMessageType(int _type)
{
  switch (_type)
  {
    case SV_SERVINFO:
      return new Servinfo();
    case SV_WELCOME:
      return new Welcome();
    case SV_CLIENT:
      return new Client();
    case SV_SOUND:
      return new Sound();
    case SV_VOICECOMTEAM:
      return new Voicecomteam();
    case SV_VOICECOM:
      return new Voicecom();
    case SV_TEAMTEXTME:
    case SV_TEAMTEXT:
      return new Teamtextme(_type);
    case SV_TEXTME:
    case SV_TEXT:
      return new Textme(_type);
    case SV_TEXTPRIVATE:
      return new Textprivate();
    case SV_MAPCHANGE:
      return new Mapchange();
    case SV_ITEMLIST:
      return new Itemlist();
    case SV_MAPIDENT:
      return new Mapident();
    case SV_SWITCHNAME:
      return new Switchname();
    case SV_SWITCHTEAM:
      return new Switchteam();
    case SV_SWITCHSKIN:
      return new Switchskin();
    case SV_INITCLIENT:
      return new Initclient();
    case SV_CDIS:
      return new Cdis();
    case SV_EDITMODE:
      return new Editmode();
    case SV_SPAWN:
      return new Spawn();
    case SV_SPAWNSTATE:
      return new Spawnstate();
    case SV_SHOTFX:
      return new Shotfx();
    case SV_THROWNADE:
      return new Thrownade();
    case SV_RELOAD:
      return new Reload();
    case SV_AUTHREQ:
      return new Authreq();
    case SV_AUTHCHAL:
      return new Authchal();
    case SV_GIBDAMAGE:
    case SV_DAMAGE:
      return new Gibdamage(_type);
    case SV_POINTS:
      return new Points();
    case SV_HUDEXTRAS:
      return new Hudextras();
    case SV_HITPUSH:
      return new Hitpush();
    case SV_GIBDIED:
    case SV_DIED:
      return new Gibdied(_type);
    case SV_RESUME:
      return new Resume();
    case SV_DISCSCORES:
      return new Discscores();
    case SV_ITEMSPAWN:
      return new Itemspawn();
    case SV_ITEMACC:
      return new Itemacc();
    case SV_EDITH:
    case SV_EDITT:
    case SV_EDITS:
    case SV_EDITD:
    case SV_EDITE:
      return new Edith(_type);
    case SV_NEWMAP:
      return new Newmap();
    case SV_EDITENT:
      return new Editent();
    case SV_PONG:
      return new Pong();
    case SV_CLIENTPING:
      return new Clientping();
    case SV_GAMEMODE:
      return new Gamemode();
    case SV_TIMEUP:
      return new Timeup();
    case SV_WEAPCHANGE:
      return new Weapchange();
    case SV_SERVMSG:
      return new Servmsg();
    case SV_FLAGINFO:
      return new Flaginfo();
    case SV_FLAGMSG:
      return new Flagmsg();
    case SV_FLAGCNT:
      return new Flagcnt();
    case SV_ARENAWIN:
      return new Arenawin();
    case SV_SPAWNDENY:
      return new Spawndeny();
    case SV_FORCEDEATH:
      return new Forcedeath();
    case SV_SERVOPINFO:
      return new Servopinfo();
    case SV_TEAMDENY:
      return new Teamdeny();
    case SV_SETTEAM:
      return new Setteam();
    case SV_SERVERMODE:
      return new Servermode();
    case SV_CALLVOTE:
      return new Callvote();
    case SV_CALLVOTESUC:
      return new Callvotesuc();
    case SV_CALLVOTEERR:
      return new Callvoteerr();
    case SV_VOTE:
      return new Vote();
    case SV_VOTERESULT:
      return new Voteresult();
    case SV_IPLIST:
      return new Iplist();
    case SV_SENDDEMOLIST:
      return new Senddemolist();
    default:
      return new NullMessage(_type);
  }
}
