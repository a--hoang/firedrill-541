#include "Matrix.h"
#include <iostream>
#include <random>

void printTimeInState(float states[], int numStates, float timer) {
  for (int i = 0; i < numStates; i++) {
    std::cout << states[i] / timer << ",";
  }
  std::cout << timer << ";" << std::endl;
}

void part1 () {
  // Initialize transition matrix (make probabilities sum to 1 for easier calculation)
  Matrix transition(3,3);
  transition.set(0,0,0.5);
  transition.set(0,1,0.5);
  transition.set(0,2,0);
  transition.set(1,0,0.333);
  transition.set(1,1,0.5);
  transition.set(1,2,0.167);
  transition.set(2,0,0);
  transition.set(2,1,0.5);
  transition.set(2,2,0.5);

  // Current state tracker
  int current = 0;

  // Random number generation
  std::default_random_engine generator;
  // Arrivals are exponential (1)
  std::exponential_distribution<float> arrival(1.0);
  std::uniform_real_distribution<float> event(0.0,1.0);

  float timer = 0.0;
  float timeInState[3] = {0.0, 0.0, 0.0};
  float nextRand = 0.0;
  while (timer < 10000) {
    float interval = arrival(generator);
    timer += interval;
    nextRand = event(generator);
    // Check and record probabilities
    float count = 0.0;
    int i = 0;
    for (i = 0; i < 3; i++) {
      count+=transition.get(current,i);
      if (nextRand <= count)
        break;
    }

    timeInState[i] += interval;
    current = i;
    printTimeInState(timeInState, 3, timer);
  }

  // std::cout << "Part 1: " << std::endl;
  //
  // // Print time
  // for (int i =0; i < 3; i++) {
  //   std::cout << timeInState[i] << "  " << std::endl;
  // }
  //
  // std::cout << std::endl;
}

void part2() {
  // Initialize transition matrix (make probabilities sum to 1 for easier calculation)
  Matrix transition(4,4);
  transition.set(0,0,0.5);
  transition.set(0,1,0);
  transition.set(0,2,0.5);
  transition.set(0,3,0);
  transition.set(1,0,0.25);
  transition.set(1,1,0.5);
  transition.set(1,2,0);
  transition.set(1,3,0.25);
  transition.set(2,0,0.333);
  transition.set(2,1,0);
  transition.set(2,2,0.5);
  transition.set(2,3,0.167);
  transition.set(3,0,0);
  transition.set(3,1,0.333);
  transition.set(3,2,0.167);
  transition.set(3,3,0.5);

  // Current state tracker
  int current = 0;

  // Random number generation
  std::default_random_engine generator;
  // Arrivals are exponential (1)
  std::exponential_distribution<float> arrival(1.0);
  std::uniform_real_distribution<float> event(0.0,1.0);

  float timer = 0.0;
  float timeInState[4] = {0.0, 0.0, 0.0, 0.0};
  float nextRand = 0.0;
  while (timer < 10000) {
    float interval = arrival(generator);
    timer += interval;
    nextRand = event(generator);
    // Check and record probabilities
    float count = 0.0;
    int i = 0;
    for (i = 0; i < 4; i++) {
      count+=transition.get(current,i);
      if (nextRand <= count)
        break;
    }

    timeInState[i] += interval;
    current = i;
    printTimeInState(timeInState, 4, timer);
  }

  // std::cout << "Part 2: " << std::endl;
  // // Print time
  // for (int i =0; i < 4; i++) {
  //   std::cout << timeInState[i] << "  " << std::endl;
  // }
  //
  // std::cout << std::endl;
}

int main() {

  part1();
  part2();
  return 0;
}
