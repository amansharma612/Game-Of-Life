# Game Of Life
This is a C++ implementation of the Conway's game of life. I have used SFML as a graphics library to render the cells on screen. I have also created 3 God functions which can give life or destory according to a psuedorandom function. Further optimizations in the calculation are possible but not implemented as of yet.

The God's implemented are based on the concept of central limit theorem, where I take the average of uniform random variables to create some kind of Gaussian Distribution.

1. The first God gives life according to a Gaussian centered at mean.
2. The second God give life according to a Gaussian, and also deleted life according to some other Gaussian distribution.
3. The third God picks cells according to some Gaussian, and then inverts it states. i.e. alive to dead and dead to alive.

## Compilation and Running

Run the following commands on your machine.

Here the possible options of GodName are 1 2 and 3.
``` 
    sudo apt-get install libsfml-dev
    g++ -g -c window.cpp ConwayGame.cpp main.cpp
    g++ main.o window.o ConwayGame.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
    ./sfml-app <GodName>
```