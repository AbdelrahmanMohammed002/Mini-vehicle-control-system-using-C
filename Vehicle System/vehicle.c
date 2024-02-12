/*
 * vehicle.c
 *
 *  Created on: Feb 12, 2024
 *      Author: HP
 */
#include <stdio.h>
#include <stdlib.h>
#include "vehicle.h"



int GetVehicleState(const  Vehicle * vehicle)
{
    return vehicle->state;
}

void SetVehicleState( Vehicle * vehicle, VehicleState state)
{
    vehicle->state = state;
}


char SensorStateMenu()
{
    // Implementation of SensorStateMenu
    printf("\nSensor Set Menu:\n");
    printf("a. Turn off the vehicle engine\n");
    printf("b. Set the traffic light color\n");
    printf("c. Set the room temperature (Temperature sensor)\n");
    printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
    char userInput; // Read user input
    scanf(" %c", &userInput);               // Consume the newline character

    return userInput;
}

char InputTrafficLightColor()
{
    printf("Enter traffic light (g, o, r): ....\n");
    char traffic_Light;
    scanf(" %c", &traffic_Light);               // Consume the newline character
    return traffic_Light;
}

void SetVehicleSpeed(struct Vehicle *vehicle, int speed)
{
    // Implementation of SetVehicleSpeed
    vehicle->speed = speed;
}

int GetVehicleSpeed(const struct Vehicle * vehicle)
{
    return vehicle->speed;
}

void PrintVehicleState(struct Vehicle vehicle)
{
    // Implementation of PrintVehicleState
    printf("\nEngine State: %s\n", vehicle.state == OFF ? "OFF" : (vehicle.state == ON ? "ON" : "QUIT"));
    printf("AC: %s\n", vehicle.ac == AC_ON ? "ON" : "OFF");
    printf("Engine Temperature Controller State: %s\n", vehicle.controller_state == CONTROLLER_ON ? "ON" : "OFF");
    printf("Vehicle Speed: %d\n", vehicle.speed);
    printf("Room Temperature: %d\n", vehicle.room_temp);
    printf("Engine Temperatuer: %d\n", vehicle.engine_temp);
}

int InputRoomTemperature()
{
    printf("Enter Room Temperature (sensor value): ");
    int room_temp;
    scanf("%d", &room_temp);
    return room_temp;
}


void SetAC(struct Vehicle *vehicle, ACState ac_status)
{
    // Implementation of SetAC
    if (ac_status == AC_ON)
    {
        vehicle->ac = AC_ON;
    }
    else
    {
        vehicle->ac = AC_OFF;
    }
}

ACState GetACState(const Vehicle *vehicle)
{
	return vehicle->ac;
}

void SetRoomTemperature(struct Vehicle *vehicle, int room_temp)
{
    // Implementation of SetRoomTemperature
    vehicle->room_temp = room_temp;
}

int GetRoomTemperature(const Vehicle *vehicle)
{
    return vehicle->room_temp;
}

int InputEngineTemperature()
{
    printf("Enter Engine Temperature (sensor value)....\n");
    int engine_temp;
    scanf("%d", &engine_temp);
    return engine_temp;
}

void SetEngineTemperatureController(Vehicle *vehicle, EngineTemperatureControllerState controller_status)
{
    if (controller_status == CONTROLLER_ON)
    {
        vehicle->controller_state = CONTROLLER_ON;
    }
    else
    {
        vehicle->controller_state = CONTROLLER_OFF;
    }
}

EngineTemperatureControllerState GetEngineTemperatureControllerState(const Vehicle *Vehicle)
{
    return Vehicle->controller_state;
}

void SetEngineTemperature(struct Vehicle *vehicle, int engine_temp)
{
    vehicle->engine_temp = engine_temp;
}

int GetEngineTemperature(const Vehicle *Vehicle)
{
    return Vehicle->engine_temp;
}


