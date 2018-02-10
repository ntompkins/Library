public class Item {
 // variables
 private int x;
 private int y;
 private char c;
 
 // Constructor
 Item(int x, int y, char c) {
  setX(x);
  setY(y);
  setC(c);
 }
 
 // Methods
 public void setX(int n) {
  x = n;
 }
 public void setY(int n) {
  y = n;
 }
 public void setC(char x) {
  c = x;
 }
 public int getX()  { return x; }
 public int getY()  { return y; }
 public char getType() { return c; }
}