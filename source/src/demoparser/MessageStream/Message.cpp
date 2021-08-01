/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Message.h"
#include "Messages/Client.h"


/**
 * Message constructor.
 *
 * @param int _type The message type (One of the SV_* constants)
 */
Message::Message(int _type)
{
  type = _type;
  parentClientMessage = NULL;
}


// Getters and Setters

/**
 * Sets the demo protocol version.
 *
 * @param int _demoprotocol The demo protocol version
 */
void Message::setDemoProtocol(int _demoprotocol)
{
  demoprotocol = _demoprotocol;
}

/**
 * Sets the data buffer that contains the raw data string from which this Message was parsed.
 *
 * @param ucharbuf _rawDataBuffer The raw data buffer
 */
void Message::setRawDataBuffer(ucharbuf _rawDataBuffer)
{
  rawDataBuffer = _rawDataBuffer;
}

/**
 * Returns the message type.
 *
 * @return int The message type
 */
int Message::getType()
{
  return type;
}

/**
 * Sets the parent Client message.
 *
 * @param Message _parentClientMessage The parent Client message
 */
void Message::setParentClientMessage(Message* _parentClientMessage)
{
  parentClientMessage = _parentClientMessage;
}


// Public Methods

/**
 * Returns the client number of the parent Client message.
 *
 * @return int The client number of the parent Client message
 */
int Message::getClientNumberFromParentClientMessage()
{
  if (!parentClientMessage) return -1;

  Client* clientMessage = static_cast<Client*>(parentClientMessage);
  return clientMessage->clientNumber;
}

/**
 * Returns the type name of this message type.
 *
 * @return char* The type name of this message type
 */
const char* Message::getTypeName()
{
  static const char* typeNames[] = {
    "SV_SERVINFO",
    "SV_WELCOME",
    "SV_INITCLIENT",
    "SV_POS",
    "SV_POSC",
    "SV_POSN",
    "SV_TEXT",
    "SV_TEAMTEXT",
    "SV_TEXTME",
    "SV_TEAMTEXTME",
    "SV_TEXTPRIVATE", // 10
    "SV_SOUND",
    "SV_VOICECOM",
    "SV_VOICECOMTEAM",
    "SV_CDIS",
    "SV_SHOOT",
    "SV_EXPLODE",
    "SV_SUICIDE",
    "SV_AKIMBO",
    "SV_RELOAD",
    "SV_AUTHT", // 20
    "SV_AUTHREQ",
    "SV_AUTHTRY",
    "SV_AUTHANS",
    "SV_AUTHCHAL",
    "SV_GIBDIED",
    "SV_DIED",
    "SV_GIBDAMAGE",
    "SV_DAMAGE",
    "SV_HITPUSH",
    "SV_SHOTFX", // 30
    "SV_THROWNADE",
    "SV_TRYSPAWN",
    "SV_SPAWNSTATE",
    "SV_SPAWN",
    "SV_SPAWNDENY",
    "SV_FORCEDEATH",
    "SV_RESUME",
    "SV_DISCSCORES",
    "SV_TIMEUP",
    "SV_EDITENT", // 40
    "SV_ITEMACC",
    "SV_MAPCHANGE",
    "SV_ITEMSPAWN",
    "SV_ITEMPICKUP",
    "SV_PING",
    "SV_PONG",
    "SV_CLIENTPING",
    "SV_GAMEMODE",
    "SV_EDITMODE",
    "SV_EDITH", // 50
    "SV_EDITT",
    "SV_EDITS",
    "SV_EDITD",
    "SV_EDITE",
    "SV_NEWMAP",
    "SV_SENDMAP",
    "SV_RECVMAP",
    "SV_REMOVEMAP",
    "SV_SERVMSG",
    "SV_ITEMLIST", // 60
    "SV_WEAPCHANGE",
    "SV_PRIMARYWEAP",
    "SV_FLAGACTION",
    "SV_FLAGINFO",
    "SV_FLAGMSG",
    "SV_FLAGCNT",
    "SV_ARENAWIN",
    "SV_SETADMIN",
    "SV_SERVOPINFO",
    "SV_CALLVOTE", // 70
    "SV_CALLVOTESUC",
    "SV_CALLVOTEERR",
    "SV_VOTE",
    "SV_VOTERESULT",
    "SV_SETTEAM",
    "SV_TEAMDENY",
    "SV_SERVERMODE",
    "SV_IPLIST",
    "SV_LISTDEMOS",
    "SV_SENDDEMOLIST", // 80
    "SV_GETDEMO",
    "SV_SENDDEMO",
    "SV_DEMOPLAYBACK",
    "SV_CONNECT",
    "SV_SWITCHNAME",
    "SV_SWITCHSKIN",
    "SV_SWITCHTEAM",
    "SV_CLIENT",
    "SV_EXTENSION",
    "SV_MAPIDENT", // 90
    "SV_HUDEXTRAS",
    "SV_POINTS",
    "SV_NUM"
  };

  if (type >= 0 && type <= SV_NUM)
  {
    return typeNames[type];
  }
  else
  {
    return "Unknown type";
  }
}

/**
 * Writes this Message to a given data buffer.
 * By default this writes the raw data buffer from which this Message was parsed to the given buffer.
 *
 * @param ucharbuf _buffer The buffer to write this Message to
 */
void Message::writeToBuffer(ucharbuf* _buffer)
{
  _buffer->put(rawDataBuffer.buf, rawDataBuffer.remaining());
}
