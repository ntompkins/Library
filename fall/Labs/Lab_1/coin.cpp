#include "coin.hpp"
void Coin::tossCoin() {
  srand(time(0));
  if ((rand() % 2) == 0) {
    setSideUp("Heads");
    setHeadsCount();
  } else {
    setSideUp("Tails");
    setTailsCount();
  }
}