#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char battery_charge_dir[] = "/sys/class/power_supply/BAT1/charge_now";
const char battery_max_dir[] = "/sys/class/power_supply/BAT1/charge_full";

float battery_percentage()
{

    FILE * battery_now = fopen(battery_charge_dir, "r");
    char battery_amount[25];
    fgets(battery_amount, 25, battery_now);

    FILE * battery_max_file = fopen(battery_max_dir, "r");
    char battery_max[25];
    fgets(battery_max, 25, battery_max_file);

    float battery_now_int = atof(battery_amount);
    float battery_max_int = atof(battery_max);

    float battery_status = (battery_now_int / battery_max_int);

    return battery_status;

}

int main()
{

    while(1)
    {

        float battery_amount = battery_percentage();
        printf("\rCurrent battery: %%%.0f", (battery_amount * 100));

        sleep(1);
        fflush(stdout);

    }
    return 0;
}
