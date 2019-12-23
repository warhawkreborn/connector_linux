#ifndef MESSAGE_SERVER_H
#define MESSAGE_SERVER_H

#include <vector>

#include "udp_server.h"

class MessageHandler
{
  public:

    virtual ~MessageHandler( )
    {
    }

    virtual void OnReceivePacket( sockaddr_storage client, std::vector< uint8_t > data ) = 0;

  protected:

  private:
};


#endif // MESSAGE_SERVER_H
