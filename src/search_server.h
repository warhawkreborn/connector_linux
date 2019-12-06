#ifndef SEARCH_SERVER_H
#define SEARCH_SERVER_H

#include <iostream>
#include <vector>

#include "message_handler.h"
#include "net.h"
#include "server.h"
#include "server_entry.h"


class SearchServer : public MessageHandler
{
  public:

    SearchServer( Server * );
    ~SearchServer( );

    void run( );

    void OnReceivePacket( sockaddr_storage client, std::vector< uint8_t > data ) override;

  protected:

  private:

    const std::string m_DiscoveryPacket =
      "c381b800001900b6018094004654000005000000010000000000020307000000c0a814ac000000002d27000000000000010000005761726861"
      "776b00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002801800ffffffff000000"
      "00000000004503d7e0000000000000005a";

    std::mutex                  m_mutex;
    std::vector< ServerEntry >  m_entries;
    Server                     *m_server;
};

#endif // SEARCH_SERVER_H
