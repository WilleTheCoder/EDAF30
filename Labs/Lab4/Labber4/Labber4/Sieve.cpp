#include "sieve.h"
#define upper_bound 100000
#include <math.h> 
using namespace std;
/*
int main(){
    Sieve s{35};
    s.test();
    cout << "Listing primes up to " << 35 <<".."<< endl;

    for (auto prim : s.get_primes()){
        cout << prim << " ";
    }
        cout << endl;
   

    Sieve s2{upper_bound};
    cout << "Highest prime less than " << upper_bound << endl
        << s2.get_highest_prime() << endl;

    Sieve s3{ 200 };
    cout << "Listing primes up to " << 200 << ".." << endl;
    for (auto prim : s3.get_primes()) {
        cout << prim << " ";
    }
    cout << endl;
    
}
*/


Sieve::Sieve(size_t nbrs){
    primes.assign(nbrs + 1, 'P'); //all are primes
    primes[0] = 'C'; // 0 no prime standard
    primes[1] = 'C'; // 1 no prime standard

    int x = sqrt(primes.length());

    for (size_t i = 2; i < x; i++){

        if (primes[i] == 'P'){
            //all multiples of i within range assign C (no_prime)
            size_t multiple = i * 2; 
            while (multiple <= nbrs){
                primes[multiple] = 'C';
                multiple += i;
            }
        }
    }
}

//add primes to vector
vector<int> Sieve::get_primes(){
    vector<int> v{};
    for (size_t i = 0; i < primes.length(); i++){
        if (primes.at(i) == 'P')
            v.push_back(i);
    }
    return v;
}

int Sieve::get_highest_prime(){
    return primes.rfind('P'); //print out last element,that is highest prime
}

//compare result to correct result for 35
void Sieve::test(){
    assert(primes.compare(correct) == 0);
}
