
#include <vector>
#include <chrono>


class ConwayGame {
    private:
        int whichGod;
        void setInitCondition();
        void godMove(int whichGod);


    public:
        std::vector<int> boardPosition;
        std::vector<int> newPosition;
        int gameSize;
        ConwayGame(int gameSize, int whichGod);
        void updatePositions();
};