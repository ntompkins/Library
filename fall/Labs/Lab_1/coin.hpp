using namespace std;
#ifndef COIN_H
#define COIN_H
class Coin {
  private:
    string sideUp="";
    int headsCount=0,
      tailsCount=0,
      tossCount=0;
  
  public:
      Coin() {                        // Constructor
        setHeadsCount(0);
        setTailsCount(0);
        int h = headsCount;
        int t = tailsCount;
        int c = getTossCount();
      }
      ~Coin() {                       // Destructor
      }
      
      // Accesors
 	    string getSideUp() {
        return sideUp;
      }
      int getTailsCount() {
        return tailsCount;
      }
      int getHeadsCount() {
        return headsCount;
      }
      int getTossCount() {
        int i = headsCount + tailsCount;
        return i;  // Total tosses
      }
      
      // Modifiers
      void setSideUp(string s) {
        sideUp = s;
      }
      void setHeadsCount() {          // Increment
        ++headsCount;
      }
      void setTailsCount() {          // Increment
        ++tailsCount;
      }
      void setHeadsCount(int h) {     // Overloaded
        headsCount = h;
      }
      void setTailsCount(int t) {     // Overloaded
        tailsCount = t;
      }
      
      // Prototypes
      void tossCoin();
};
#endif