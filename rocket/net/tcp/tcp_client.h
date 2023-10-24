#ifndef ROCKET_NET_TCP_CLIENT_H
#define ROCKET_NET_TCP_CLIENT_H


#include "rocket/net/eventloop.h"
#include "rocket/net/tcp/tcp_connection.h"
#include "rocket/net/tcp/net_addr.h"
#include "rocket/net/coder/abstract_protocol.h"



namespace rocket {


class TcpClient {
public:
    TcpClient(NetAddr::s_ptr peer_addr);
    ~TcpClient();
    
    void connect(std::function<void()> done); // 异步conn操作

    void writeMessage(AbstractProtocol::s_ptr message, std::function<void(AbstractProtocol::s_ptr)> done);
    void readMessage(const std::string& req_id, std::function<void(AbstractProtocol::s_ptr)> done);

private:
    NetAddr::s_ptr m_peer_addr;
    EventLoop* m_event_loop {NULL};

    int m_fd;
    FdEvent* m_fd_event {NULL};
    TcpConnection::s_ptr m_connection {NULL};
};

}


#endif