#ifndef SIEVE_H
#define SIEVE_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

class Sieve {
public:
    Sieve(size_t nbrs);
    vector<int> get_primes();
    int get_highest_prime();
    void test();
private:
    string primes;
    string correct = "CCPPCPCPCCCPCPCCCPCPCCCPCCCCCPCPCCCC";
};


#endif