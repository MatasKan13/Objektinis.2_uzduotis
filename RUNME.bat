rmdir /s /q build
mkdir build
robocopy . .\build stud1000.txt stud10000.txt stud100000.txt stud1000000.txt stud10000000.txt 
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
ninja
v1_5.exe
pause