#pragma once
#include "func.h"
#include "countTime.h"
ll a = 3, b = 5;

int main()
{
    count_ver0(a, b);
    count_ver1_basic(a, b);
    count_ver1_update(a, b);
    count_ver2_basic(a, b);
    count_ver2_update(a, b);
    return 0;
}