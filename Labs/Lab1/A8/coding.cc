#include "coding.h"
#include <iostream>


 unsigned char encode(unsigned char c)
{
    return ++c;
}
 unsigned char decode(unsigned char c)
{
    return --c;
}