#ifndef ROCKET_NET_TIMER_H
#define ROCKET_NET_TIMER_H

#include <map>
#include "rocket/common/mutex.h"
#include "rocket/net/fd_event.h"
#include "rocket/net/timer_event.h"


namespace rocket {
class Timer : public FdEvent {
public:
    Timer();
    ~Timer();

    void addTimerEvent(TimerEvent::s_ptr event);
    void delTimerEvent(TimerEvent::s_ptr event);

    void onTimer(); // 发送io事件 - eventloop执行此函数
    void resetArriveTime();

private:
    std::multimap<int64_t, TimerEvent::s_ptr> m_pending_events;
    Mutex m_mutex;
};

}


#endif