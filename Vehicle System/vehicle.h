#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED



// Contents of the header file go here
typedef enum
{
    OFF,
    ON,
    QUIT
} VehicleState;

typedef enum
{
    AC_ON,
    AC_OFF
} ACState;

typedef enum
{
    CONTROLLER_ON,
    CONTROLLER_OFF
} EngineTemperatureControllerState;

typedef struct  Vehicle
{
    VehicleState state;
    ACState ac;
    int speed;
    int room_temp;
    int engine_temp;
    EngineTemperatureControllerState controller_state;
}Vehicle;


int GetVehicleState(const Vehicle* vehicle);
void SetVehicleState(Vehicle* vehicle, VehicleState state);

char SensorStateMenu();
char InputTrafficLightColor();
void SetVehicleSpeed(struct Vehicle *vehicle, int speed);
int GetVehicleSpeed(const Vehicle* vehicle);
void PrintVehicleState(struct Vehicle vehicle);

int InputRoomTemperature();
void SetAC(struct Vehicle *vehicle, ACState ac_status);
ACState GetACState(const Vehicle *vehicle);
void SetRoomTemperature(struct Vehicle *vehicle, int room_temp);
int GetRoomTemperature(const Vehicle *vehicle);

int InputEngineTemperature();
void SetEngineTemperatureController(struct Vehicle *Vehicle, EngineTemperatureControllerState controller_status);
void SetEngineTemperature(struct Vehicle *vehicle, int engine_temp);
int GetEngineTemperature(const Vehicle *Vehicle);
EngineTemperatureControllerState GetEngineTemperatureControllerState(const Vehicle *Vehicle);



#endif // VEHICLE_H_INCLUDED
