/**
 * @author wesen
 * @copyright 2021 wesen <wesen-ac@web.de>
 */

#include "../demoparser/MessageStream/Message.h"
#include "../demoparser/MessageStream/Messages/Client.h"
#include "../demoparser/PacketStream/Packet.h"
#include "../demoparser/ParsedDemo.h"
#include <vector>

#ifndef DEMO_WRITER
#define DEMO_WRITER

class DemoWriter
{
  private:
    std::vector<std::string> messageTypesToRemove;
    Client* currentClientMessage;

    void writeDemoHeader(stream*, demoheader*);
    void writePacket(stream*, Packet*, ucharbuf*);
    void generatePacketPayload(Packet*, ucharbuf*);
    void generatePacketPayloadFromMessageStream(MessageStream*, ucharbuf*);
    bool shouldMessageBeRemoved(Message*);
    void removeMessage(Message*);
    void addMessage(Message*, ucharbuf*);
    void addCurrentClientMessage(ucharbuf*);
    void restoreOriginalPacketPayload(Packet*, ucharbuf*);

  public:
    DemoWriter(std::vector<std::string>);

    void writeDemo(stream*, ParsedDemo*);
};

#endif
