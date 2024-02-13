#include <stdio.h>
#include <stdlib.h>
#include "vehicle.h"

#define WITH_ENGINE_TEMP_CONTROLLER 0

void handleEngineStart(struct Vehicle *vehicle);
void handleEngineShutdown(struct Vehicle *vehicle);
void handleUserInput(struct Vehicle *vehicle, char userInput);

int main() {

    // Dynamically allocate memory for the struct Vehicle
    struct Vehicle *DB11 = (struct Vehicle *)malloc(sizeof(struct Vehicle));
    if (DB11 == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Initialize the vehicle
    SetVehicleSpeed(DB11, 0);
    SetRoomTemperature(DB11, 20);
    SetVehicleState(DB11, OFF);
    SetEngineTemperature(DB11, 125);

    while (GetVehicleState(DB11) != QUIT) {
        printf("\nVehicle Control System:\n");
        printf("a. Turn on the vehicle engine\n");
        printf("b. Turn off the vehicle engine\n");
        printf("c. Quit the system\n");

        char userInput;
        scanf(" %c", &userInput);

        handleUserInput(DB11, userInput);
    }

    // Free dynamically allocated memory
    free(DB11);

    return 0;
}

void handleUserInput(struct Vehicle *vehicle, char userInput) {
    switch (userInput) {
        case 'a':
            handleEngineStart(vehicle);
            break;
        case 'b':
            handleEngineShutdown(vehicle);
            break;
        case 'c':
            printf("Quitting the system...\n");
            vehicle->state = QUIT;
            break;
        default:
            printf("Invalid input. Please enter a, b, or c.\n");
            break;
    }
}

void handleEngineStart(struct Vehicle *vehicle) {
    if (GetVehicleState(vehicle) == OFF) {
        printf("Turning on the vehicle engine...\n");
        SetVehicleState(vehicle, ON);

        char userInput;
        int room_temp_reading, engine_temp_reading;
        while (GetVehicleState(vehicle) == ON) {
            userInput = SensorStateMenu();
            switch (userInput) {
                case 'a':
                    SetVehicleSpeed(vehicle, 0);
                    SetVehicleState(vehicle, OFF);
                    break;
                case 'b':
                    handleTrafficLightInput(vehicle);
                    break;
                case 'c':
                    room_temp_reading = InputRoomTemperature();
                    handleRoomTemperatureInput(vehicle, room_temp_reading);
                    break;
                #if WITH_ENGINE_TEMP_CONTROLLER
                case 'd':
                    engine_temp_reading = InputEngineTemperature();
                    handleEngineTemperatureInput(vehicle, engine_temp_reading);
                    break;
                #endif // WITH_ENGINE_TEMP_CONTROLLER
                default:
                    printf("Invalid input. Please enter a, b, c, or d.\n");
                    break;
            }

            adjustVehicleParameters(vehicle);
            PrintVehicleState(*vehicle);
        }
    } else {
        printf("The engine is already on.\n");
    }
}

void handleEngineShutdown(struct Vehicle *vehicle) {
    if (GetVehicleState(vehicle) == ON) {
        printf("Turning off the vehicle engine...\n");
        // Implement safe engine shutdown logic here (e.g., gradual RPM decrease)
        SetVehicleState(vehicle, OFF);
    } else {
        printf("The engine is already off.\n");
    }
}

void handleTrafficLightInput(struct Vehicle *vehicle) {
    char traffic_light = InputTrafficLightColor();
    switch (traffic_light) {
        case 'g':
            SetVehicleSpeed(vehicle, 100);
            break;
        case 'o':
            SetVehicleSpeed(vehicle, 30);
            break;
        case 'r':
            SetVehicleSpeed(vehicle, 0);
            break;
        default:
            printf("Invalid input. Please enter g, o, or r.\n");
            break;
    }
}

void handleRoomTemperatureInput(struct Vehicle *vehicle, int room_temp_reading) {
    if (room_temp_reading < 10 || room_temp_reading > 30) {
        SetAC(vehicle, AC_ON);
        SetRoomTemperature(vehicle, 20);
    } else {
        SetAC(vehicle, AC_OFF);
        SetRoomTemperature(vehicle, room_temp_reading);
    }
}

#if WITH_ENGINE_TEMP_CONTROLLER
void handleEngineTemperatureInput(struct Vehicle *vehicle, int engine_temp_reading) {
    if (engine_temp_reading < 100 || engine_temp_reading > 150) {
        SetEngineTemperatureController(vehicle, CONTROLLER_ON);
        SetEngineTemperature(vehicle, 125);
    } else {
        SetEngineTemperatureController(vehicle, CONTROLLER_OFF);
        SetEngineTemperature(vehicle, engine_temp_reading);
    }
}
#endif // WITH_ENGINE_TEMP_CONTROLLER
void adjustVehicleParameters(struct Vehicle *vehicle) {
    if (GetVehicleSpeed(vehicle) == 30) {
        if (GetVehicleState(vehicle) == AC_OFF) {
            SetAC(vehicle, AC_ON);
            int new_room_temp = (GetRoomTemperature(vehicle) * 0.2) + 1;
            SetRoomTemperature(vehicle, new_room_temp);
        }
        #if WITH_ENGINE_TEMP_CONTROLLER
        if (GetEngineTemperatureControllerState(vehicle) == CONTROLLER_OFF) {
            SetEngineTemperatureController(vehicle, CONTROLLER_ON);
            int new_engine_temp = (GetEngineTemperature(vehicle) * 0.2) + 1;
            SetEngineTemperature(vehicle, new_engine_temp);
        }
        #endif // WITH_ENGINE_TEMP_CONTROLLER
    }
}
