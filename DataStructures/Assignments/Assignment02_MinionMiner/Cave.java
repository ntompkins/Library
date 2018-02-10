public class Cave {

  // Max map is 20x70
  private int MAX_ROWS = 20;
  private int MAX_COLS = 70;
  
  // Private variables
  private int rows=0;
  private int cols=0;
  private int items=0;
  private int steps=0;
  
  // Create items to locate
  Item diamond = new Item(-1,-1,'d');
  Item home = new Item(-1,-1,'h');
  
  // Create character map for cave
  private char[][] map = new char[MAX_ROWS][MAX_COLS];

  // Constructor
  Cave(int r, int c, int i) {
      
      // Set rows, columns, and no. of items
      setRows(r);
      setCols(c);
      setItems(i);
      
      // Update size of the map array
      updateMap();
  }
  
  // Don't allow array larger than MAX values
  public void setRows(int r) {
    if(r<=MAX_ROWS)
      rows = r;
    else 
      rows = MAX_ROWS;
  }
  
  public void setCols(int c) {
    if(c<=MAX_COLS)
      cols = c;
    else
      cols = MAX_COLS;
  }
  
  public void setItems(int i) {
    // Should always have two items: diamond and home
    items = i;
  }
  
  public void setCell(int x, int y, char c) {
    map[x][y] = c;
  }
  
  public void setDiamond(int x, int y) {
    diamond.setX(x);
    diamond.setY(y);
  }
  
  public void setHome(int x, int y) {
    home.setX(x);
    home.setY(y);
  }
  
  // Getters
  public char getCell(int x, int y) { return map[x][y]; }
  public int getRows() { return rows; }
  public int getCols() { return cols; }
  public int getSteps() { return steps; }
  public int getDiamondX() { return diamond.getX(); }
  public int getDiamondY() { return diamond.getY(); }
  public int getHomeX() { return home.getX(); }
  public int getHomeY() { return home.getY(); }
  
  // Add obstacle border around map
  public void addBorder() {
    char[][] temp = new char[rows+2][cols+2];
    // Add blocks around array
    for(int r=0;r<rows-1;r++){
      for(int c=0;c<cols-1;c++) {
        if(r==0||c==0) {
          temp[r][c] = 'O';
        }
        else if (r==rows-1) {
          temp[r-1][c] = 'O';
        }
        else if(c==cols-1) {
          temp[r][c-1] = 'O';
        }
        else {
          temp[r][c] = map[r-1][c-1];
        }
      }
    }
    map = null;
    map = temp;
  }
  
  public void addStep() {
    steps++;
  }
  
  public void updateMap() {
    char [][] temp = new char[rows][cols];
    // dereference original map
    map = null;
    // reference new map
    map = temp;
  }
  
  // Return string version of the array
  public String toString() {
    String s="";
    for(int r=0; r < getCols(); r++) {
      for(int c=0; c < getRows(); c++) {
        s+=""+getCell(r,c)+" ";
      }
      s+="\n";
    }
    return s;
  }
}