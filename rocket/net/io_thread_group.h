#ifndef ROCKET_NET_IO_GROUP_H
#define ROCKET_NET_IO_GROUP_H


#include <vector> 

#include "rocket/net/io_thread.h"


namespace rocket {

// io 线程池
// 只有主线程才会调用io线程池的方法 不需要mutex
class IOThreadGroup {
public:
    IOThreadGroup(size_t size);
    ~IOThreadGroup();

    void start();
    void join();

    IOThread* getIOThread();

private:
    size_t m_size {0};
    size_t m_index {0};    //当前下标
    std::vector<IOThread*> m_io_thread_groups;
};


}
#endif
