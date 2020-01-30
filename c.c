#include <stdio.h>
#include <stdlib.h>
#include "a.h"

int func2() {
    func0();
    return 0;
}

int __attribute__ ((visibility ("hidden"))) getaddrinfo(const char *hostname, const char *servname, const struct addrinfo *hints, struct addrinfo **res) {
    return 0;
}
