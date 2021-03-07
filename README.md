# itp
Program to simulate the life of the university

# Dependencies:
gcc 10.2.0

# How to run:
clone the repository and in its directory perform following commands:
```
g++ -c accesslevel.cpp admin.cpp director.cpp labemployee.cpp main.cpp professor.cpp room.cpp student.cpp university.cpp user.cpp
g++ -o main.exe accesslevel.o admin.o director.o labemployee.o main.o professor.o room.o student.o university.o user.o
./main.exe
```
# Description
The program simulates the daily life of university: university has users who do certain actions which are specified in their classes, users can interact with rooms by trying to open it, etc. To begin with, university should be initialized. It is done in main.cpp, where the pool, rooms and other parameters are specified for University class, then the university got created and the method start(int days) called, where days is the number of iterations. For each iteration there is a log with the number of iterations(days) and the log of users and their actions. The professors, students, etc all that is custom and can be specified in the parameters of University class constructor to where we push the Pool which is the structure which contains the students, professors, etc, the rooms, name of university and etc. 
