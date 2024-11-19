clear
ls
mkdir build
mkdir emptyDir
mkdir src
cd src
touch main.cpp
cd ..
touch run.sh
touch README.dm
touch .gitignore
cd emptyDir/
touch .gitkeep
ls
cd ..
ls
clear
ls
clear
cd src/
cd ..
mkdir testcase
cd src
g++ -o ../build/main ./main.cpp 
../build/main 
