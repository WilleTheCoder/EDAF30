#ifndef LAB4_TAGREMOVER_H
#define LAB4_TAGREMOVER_H

#include "iostream"

class TagRemover {
public:
    TagRemover(std::istream& in);

    void print(std::ostream& out);

private:
    std::string text;
};


#endif 