#include "ConwayGame.h"
#include <unistd.h>
#include <cstdlib>

ConwayGame::ConwayGame(int gameSize, int whichGod){
    this->whichGod = whichGod;
    for (int i = 0; i < gameSize * gameSize; i++) {
        this->boardPosition.push_back(0);
        this->newPosition.push_back(0);
    }

    this->gameSize = gameSize;


    setInitCondition();
}


void ConwayGame::updatePositions(){
    

    for (int i = 0; i < gameSize * gameSize; i++) {
        int x_pos = i / gameSize;
        int y_pos = i % gameSize;

        int neighLiveCnt = 0;

        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {

                int nx = (x_pos + j) % gameSize;
                int ny = (y_pos + k) % gameSize;

                if (nx == x_pos && ny == y_pos) continue;

                if(boardPosition[(nx * gameSize) + ny] == 1) neighLiveCnt++;

            }
        }


        if (boardPosition[x_pos * gameSize + y_pos] == 1){
            if (neighLiveCnt < 2) newPosition[x_pos * gameSize + y_pos] = 0;
            else if (neighLiveCnt <= 3) newPosition[x_pos * gameSize + y_pos] = 1;
            else if (neighLiveCnt > 3) newPosition[x_pos * gameSize + y_pos] = 0;
        } else if (neighLiveCnt == 3) {
            newPosition[x_pos * gameSize + y_pos] = 1;
        
        }
        

        
         
    }

    boardPosition = newPosition;
    godMove(whichGod);  
    
}


void ConwayGame::setInitCondition(){
    int mid = gameSize / 2;
    boardPosition[mid * gameSize + mid] = 1;
    boardPosition[(mid) * gameSize + (mid) + 1] = 1;
    boardPosition[(mid) * gameSize + (mid) + 2] = 1;
    boardPosition[(mid - 1) * gameSize + (mid) + 2] = 1;
    boardPosition[(mid - 2) * gameSize + (mid) + 1] = 1;

}


void ConwayGame::godMove(int whichGod){

    // give life to 50 different cells
    if (whichGod == 1) {
        for (int i = 0; i < 50; i++) {
            int sumX = 0;
            int sumY = 0;
            for (int j = 0; j < 10; j++) {
                sumX += rand() % gameSize;
                sumY += rand() % gameSize;
            }

            sumX /= 10;
            sumY /= 10;

            boardPosition[((sumX) * gameSize + sumY) % (gameSize * gameSize)] = 1;
                    
        }
    } else if (whichGod == 2) {
        for (int i = 0; i < 50; i++) {
            int sumX = 0;
            int sumY = 0;
            for (int j = 0; j < 10; j++) {
                sumX += rand() % gameSize;
                sumY += rand() % gameSize;
            }

            sumX /= 10;
            sumY /= 10;

            boardPosition[((sumX) * gameSize + sumY) % (gameSize * gameSize)] = 1;
                    
        }

        for (int i = 0; i < 100; i++) {
            int sumX = 0;
            int sumY = 0;
            for (int j = 0; j < 10; j++) {
                sumX += rand() % (gameSize);
                sumY += rand() % (gameSize);
            }

            sumX /= 10;
            sumY /= 10;

            boardPosition[((sumX) * gameSize + sumY) % (gameSize * gameSize)] = 0;
                    
        }
    } else if (whichGod == 3) {
        for (int i = 0; i < 100; i++) {
            int sumX = 0;
            int sumY = 0;
            for (int j = 0; j < 20; j++) {
                sumX += rand() % (gameSize);
                sumY += rand() % (gameSize);
            }

            sumX /= 20;
            sumY /= 20;

            boardPosition[((sumX) * gameSize + sumY) % (gameSize * gameSize)] += 1;
            boardPosition[((sumX) * gameSize + sumY) % (gameSize * gameSize)] %= 2;
                    
        }
    }
};