
#ifndef ROCKET_NET_FDEVENT_H
#define ROCKET_NET_FDEVENT_H

#include <functional>
#include <sys/epoll.h>

namespace rocket {

// 每个fd和event的对应
class FdEvent {
public:
    enum TriggerEvent {
        IN_EVENT = EPOLLIN,
        OUT_EVENT = EPOLLOUT,
        ERROR_EVENT = EPOLLERR,
    };

    FdEvent(int fd);
    FdEvent();

    ~FdEvent();

    std::function<void()> handler(TriggerEvent event_type); //返回触发事件回调

     void listen(TriggerEvent event_type, std::function<void()> callback, std::function<void()> error_callback = nullptr); //设置cb 保存epoll_events

    int getFd() const {
        return m_fd;
    }

    epoll_event getEpollEvent() {
        return m_listen_events;
    }

    void setNonBlock();
    void cancle(TriggerEvent type);

protected:
    int m_fd {-1};

    epoll_event m_listen_events;

    std::function<void()> m_read_callback {nullptr};
    std::function<void()> m_write_callback {nullptr};
    std::function<void()> m_error_callback {nullptr};

};

}

#endif