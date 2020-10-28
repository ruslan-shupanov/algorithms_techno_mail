//
// Created by oleg on 01.11.18.
//

#ifndef SEMINAR_RIGHT_RANDOM_H
#define SEMINAR_RIGHT_RANDOM_H

class FastRandom {
private:
    unsigned long long rnd;
public:
    FastRandom() {
        rnd = 1;
    }
    void seed(unsigned long long seed) {
        rnd = seed;
    }
    unsigned long long rand() {
        rnd ^= rnd << 21;
        rnd ^= rnd >> 35;
        rnd ^= rnd << 4;
        return rnd;
    }
};
#endif //SEMINAR_RIGHT_RANDOM_H
