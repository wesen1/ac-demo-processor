/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "Player.h"

/**
 * Player constructor.
 *
 * @param int _clientNumber The client number of the player
 */
Player::Player(int _clientNumber)
{
  clientNumber = _clientNumber;
  name = new char[MAXNAMELEN];
  ip = -1;
}


// Getters and Setters

/**
 * Returns the client number.
 *
 * @return int The client number
 */
int Player::getClientNumber()
{
  return clientNumber;
}

/**
 * Returns the player name.
 *
 * @return char[] The player name
 */
char* Player::getName()
{
  return name;
}

/**
 * Returns the player IP number.
 *
 * @return int The IP number
 */
int Player::getIp()
{
  return ip;
}


// Public Methods

/**
 * Processes the player data from a given Initclient message.
 *
 * @param Initclient _initclientMessage The Initclient message to process
 */
void Player::processInitclientMessage(Initclient* _initclientMessage)
{
  changeName(_initclientMessage->name);
  ip = _initclientMessage->address;
}

/**
 * Processes the player data from a given Switchname message.
 *
 * @param Switchname _switchNameMessage The Switchname message to process
 */
void Player::processSwitchnameMessage(Switchname* _switchNameMessage)
{
  changeName(_switchNameMessage->newName);
}

/**
 * Generates and returns a IP string from the IP number.
 *
 * @return string The generated IP string
 */
std::string Player::getIpString()
{
  if (ip == -1) return "";

  char ipString[14];
  uint2ip(ip, initPlayerIpDigits);
  sprintf(
    ipString,
    "%d.%d.%d.x",
    initPlayerIpDigits[0],
    initPlayerIpDigits[1],
    initPlayerIpDigits[2]
  );

  return std::string(ipString);
}


// Private Methods

/**
 * Changes the name to a given new name.
 *
 * @param char[] _newName The new name
 */
void Player::changeName(char* _newName)
{
  filtertext(name, _newName, 0, MAXNAMELEN);
  if(!name[0]) copystring(name, "unarmed");
}
