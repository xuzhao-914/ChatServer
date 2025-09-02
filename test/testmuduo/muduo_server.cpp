/*
muduo网络库主要给用户提供了两个主要的类
TcpServer和TcpClient

*/

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>
#include <iostream>

using namespace muduo;
using namespace muduo::net;

class EchoServer {
public:
    EchoServer(EventLoop* loop, const InetAddress& listenAddr)
        : server_(loop, listenAddr, "EchoServer") {
        server_.setConnectionCallback([&](const TcpConnectionPtr& conn){
            LOG_INFO << (conn->connected() ? "UP" : "DOWN");
        });
        server_.setMessageCallback([&](const TcpConnectionPtr&,
                                       Buffer* buf, Timestamp){
            std::string msg = buf->retrieveAllAsString();
            // 回显
            // conn->send(msg);  // 如果需要回发，捕获 conn
            std::cout << msg;
        });
        server_.setThreadNum(1);
    }
    void start() { server_.start(); }
private:
    TcpServer server_;
};

int main() {
    EventLoop loop;
    InetAddress listenAddr(2007);
    EchoServer server(&loop, listenAddr);
    server.start();
    loop.loop();
    return 0;
}
