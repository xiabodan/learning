#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>

using namespace std;

// 该示例需要转换的Host name
const string kTestHostName1 = "www.blog4jimmy.com";
const string kTestHostName2 = "www.baidu.com";

int main()
{
    struct hostent *hostent1, *hostent2;
    char **pptr;
    char str[32];

    hostent1 = gethostbyname(kTestHostName1.c_str());
    if(hostent1 == nullptr) {
        cout << "gethostbyname error for host:" << kTestHostName1 << endl;
    }
    else
    {
        cout << "For " << kTestHostName1 << ": " << endl;
        // 打印主机的规范名
        cout << "h_name: " << hostent1->h_name << endl;

        // 打印主机的别名
        pptr = hostent1->h_aliases;
        for(;*pptr != nullptr; pptr++)
            cout << "h_aliases: " << *pptr << endl;

        // 打印主机的IP地址
        switch(hostent1->h_addrtype) {
        case AF_INET:
        case AF_INET6:
            pptr = hostent1->h_addr_list;
            for(; *pptr != nullptr; pptr++) {
                cout << "IP Addr: " << inet_ntop(hostent1->h_addrtype, *pptr, str, sizeof(str)) << endl;
            }
        }

        // 打印主机的首先IP地址
        cout << "First address: " << inet_ntop(hostent1->h_addrtype, hostent1->h_addr, str, sizeof(str)) << endl;
    }

    // 打印的内容和上面的一样，这里不多做讲解
    hostent2 = gethostbyname(kTestHostName2.c_str());
    if(hostent2 == nullptr) {
        cout << "gethostbyname error for host:" << kTestHostName1 << endl;
    }
    else
    {
        cout << endl;
        cout << "For " << kTestHostName2 << ": " << endl;
        cout << "h_name: " << hostent2->h_name << endl;
        pptr = hostent2->h_aliases;
        for(;*pptr != nullptr; pptr++)
            cout << "h_aliases: " << *pptr << endl;

                switch(hostent1->h_addrtype) {
        case AF_INET:
        case AF_INET6:
            pptr = hostent1->h_addr_list;
            for(; *pptr != nullptr; pptr++) {
                cout << "IP Addr: " << inet_ntop(hostent1->h_addrtype, *pptr, str, sizeof(str)) << endl;
            }
        }

        cout << "First address: " << inet_ntop(hostent1->h_addrtype, hostent1->h_addr, str, sizeof(str)) << endl;
    }

    return 0;
}
