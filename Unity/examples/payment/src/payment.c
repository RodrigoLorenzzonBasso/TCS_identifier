#include "payment.h"
#include <string.h>
#include <math.h>

int payment(float value, char status[20])
{
    if(value <= 0.009 || value > 99999.00)
        return 1;
    else if(!(strcmp(status,"regular") != 0) ||
            !(strcmp(status,"aposentado") != 0) ||
            !(strcmp(status,"estudante") != 0) ||
            !(strcmp(status,"VIP") != 0))
        return 0;
    else
        return 2;
}