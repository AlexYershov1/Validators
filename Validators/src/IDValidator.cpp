#pragma once
#include "IDValidator.h"


IDValidator::IDValidator()
{
}

void IDValidator::IsValid(const uint32_t& ID) const
{
    auto sum = ID % DIGIT_DIV;   // check digit
    std::stack<int> IDStack;
    auto counter = 0;

    for (auto id = ID / DIGIT_DIV; id != 0; id /= DIGIT_DIV) {
        IDStack.push(id % DIGIT_DIV);
        counter++;
    }
    if (counter != ID_SIZE - 1) {  // Make sure ID is formatted properly
        throw NoValid("ID size invalid");
    }
    auto incNum = 0, i = 0;
    while (!IDStack.empty()) {
        incNum = IDStack.top() * ((i % 2) + 1);  // Multiply number by 1 or 2
        IDStack.pop();
        sum += (incNum > ID_SIZE) ? incNum - ID_SIZE : incNum;  // Sum the digits up and add to total
        i++;
    }
    if (sum % DIGIT_DIV)
        throw NoValid("Invalid ID");
}

IDValidator::~IDValidator()
{
}