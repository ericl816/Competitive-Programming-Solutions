#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

int get_next_int()
{
    int n;
    scanf("%d", &n);
    return n;
}

typedef struct
{
    int nextRoom;
    int nextDoor;
    bool valid;
} RoomDoor;
 
typedef struct
{
    int doorCount;
    RoomDoor* doors;
    std::unordered_map<int, int> doorMap;
} Room;

int   totalRooms;
Room*  rooms;
 
void read_input()
{
    totalRooms = get_next_int();
    rooms = new Room[totalRooms];
    for (int room = 0; room < totalRooms; room++)
    {
        int doorCount = get_next_int();
        rooms[room].doorCount = doorCount;
        rooms[room].doors = new RoomDoor[doorCount];
        for (int door = 0; door < doorCount; door++)
        {
            int nextRoom = get_next_int() - 1; 
            rooms[room].doors[door].nextRoom = nextRoom;
            rooms[room].doors[door].valid = true;
            rooms[nextRoom].doorMap[room] = door; 
        }
    }
}
 
void precompute_next_door()
{
    for (int room = 0; room < totalRooms; room++)
    {
        int roomDoorCount = rooms[room].doorCount;
        for (int door = 0; door < roomDoorCount; door++)
        {
            int nextRoom = rooms[room].doors[door].nextRoom;
            int nextDoor = rooms[room].doorMap[nextRoom] - 1;
            if (nextDoor == -1)
                nextDoor = rooms[nextRoom].doorCount - 1;
            rooms[room].doors[door].nextDoor = nextDoor;
        }
    }
}

int* roomMaxPathDistance;
int* roomStartDistance;
 
void init_solver()
{
    roomMaxPathDistance = new int[totalRooms];
    roomStartDistance = new int[totalRooms];
    for (int i = 0; i < totalRooms; i++)
        roomMaxPathDistance[i] = 0;
}
 
void init_distances()
{
    for (int room = 0; room < totalRooms; room++)
        roomStartDistance[room] = -1;
}
 
void process_door(int room, int distance)
{
    if (roomStartDistance[room] == -1)
    {
      
        roomStartDistance[room] = distance;
    }
    else
    {
       
        int path_distance = distance - roomStartDistance[room];
 
        if (path_distance > roomMaxPathDistance[room])
            roomMaxPathDistance[room] = path_distance;
 
        roomStartDistance[room] = distance;
    }
}
 
void solve_path(int startRoom, int startDoor)
{
    int currentRoom = startRoom;
    int currentDoor = startDoor;
    int distance = 0;
    int pass = 0;
 
    void init_distances();
 
    do
    {
        
        process_door(currentRoom, distance);
       
        rooms[currentRoom].doors[currentDoor].valid = false;
       
        int nextRoom = rooms[currentRoom].doors[currentDoor].nextRoom;
        int nextRoomDoor = rooms[currentRoom].doors[currentDoor].nextDoor;
        
        distance++;
        
        currentRoom = nextRoom;
        currentDoor = nextRoomDoor;
      
        if (currentRoom == startRoom && currentDoor == startDoor)
            pass++;
    } while (pass < 2);
}
 
void solve_rooms()
{
    init_distances();
    for (int room = 0; room < totalRooms; room++)
    {
        int roomDoorCount = rooms[room].doorCount;
        for (int door = 0; door < roomDoorCount; door++)
        {
            
            if (rooms[room].doors[door].valid)
                solve_path(room, door);
        }
    }
}

void answer_questions()
{
    int totalQuestions = get_next_int();
    for (int q = 0; q < totalQuestions; q++)
    {
        int question = get_next_int() - 1; 
        printf("%d\n", roomMaxPathDistance[question]);
    }
}
 
int main()
{
    read_input();
    precompute_next_door();
    init_solver();
    solve_rooms();
    answer_questions();
    return 0;
}