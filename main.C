#include <stdio.h>

enum VehicleState
{
    OFF,
    ON,
    QUIT
};

int main()
{
    enum VehicleState state = OFF;

    while (state != QUIT)
    {
        printf("\nVehicle Control System:\n");
        printf("a. Turn on the vehicle engine\n");
        printf("b. Turn off the vehicle engine\n");
        printf("c. Quit the system\n");
        
        // Discard newline
        getchar();
        char userInput = getchar();

        switch (userInput)
        {
        case 'a':
            if (state == OFF)
            {
                printf("Turning on the vehicle engine...\n");
                state = ON;
                //remaining code for the vehicle
            }
            else
            {
                printf("The engine is already on.\n");
            }
            break;

        case 'b':
            if (state == ON)
            {
                printf("Turning off the vehicle engine...\n");
                // Implement safe engine shutdown logic here (e.g., gradual RPM decrease)
                state = OFF;
            }
            else
            {
                printf("The engine is already off.\n");
            }
            break;

        case 'c':
            printf("Quitting the system...\n");
            state = QUIT;
            break;

        default:
            printf("Invalid input. Please enter a, b, or c.\n");
        }
    }

    return 0;
}
