#pragma once

#include "book.h"

class members{
private:
    unordered_map<string, pair<tm, tm>> allMembers;

public:
    members();
    ~members();

    bool isValidMember(string name);
};

members::members()
{
}

members::~members()
{
}
