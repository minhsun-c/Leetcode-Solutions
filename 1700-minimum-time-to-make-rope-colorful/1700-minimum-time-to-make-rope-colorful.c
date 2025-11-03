int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int time = 0;
    int prev = 0;

    for (int i=1; i<neededTimeSize; i++) {
        if (colors[i] == colors[prev]) {
            if (neededTime[i] >= neededTime[prev]) {
                time += neededTime[prev];
                prev = i;
            } else {
                time += neededTime[i];
            }
        } else {
            prev = i;
        }
    }
    return time;
}