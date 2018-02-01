/*
Author: Nathan Tompkins
*/

import java.util.Arrays;
import java.lang.Character;

public class Nonogram {

  // Public variables
  public int numRows = 0;
  public int numCols = 0;

  // Private variables
  private String [][] hints = new String [2][20];
  private boolean [][] puzzle = new boolean [numRows][numCols];

  // create array to hold total trues in each row/col
  int [][] tallied = new int [2][20];

  // Custom constructor for nonogram class
  public Nonogram(String [][] h, boolean [][] p, int r, int c) {
    hints = Arrays.copyOf(h, h.length);
    puzzle = Arrays.copyOf(p, p.length);
    numRows = r;
    numCols = c;
  }

  // Check puzzle
  public boolean checker() {
    boolean validSolution = true;

    // Loop through puzzle[][] and count trues
    for(int x=0; x < 2; x++) {

      // Tally true/falses in boolean array
      if(x==0) {
        for(int r=0; r < numRows; r++) {
          int tally = 0;
          for(int c=0; c < numCols; c++) {

            // if boolean is true add to the total count
            if(puzzle[r][c]) {
              tally++;
            }
          }

          tallied[x][r] = tally;
        }
      } else {
        for(int c=0; c < numCols; c++) {
          int tally = 0;
          for(int r=0; r < numRows; r++) {
            if(puzzle[r][c]) {
              tally++;
            }
          }
          tallied[x][c] = tally;
        }

      }
    }
    
    
    // Loop through hints[][] and count integers
    for(int r=0; r < 2; r++) {
      int tally = 0;
      
      // Loop through rows
      for(int c=0; c < Math.max(numRows,numCols); c++) {
        String s = hints[r][c];
        if(s == null) 
          break;
        for(int x=0; x < s.length(); x++) {
          char y = s.charAt(x);

          if((tally > 0) && (y==(' '))) {
            tally++;
          }
          if(y!=' ') {
            tally = Character.getNumericValue(y);
          }
        }
        // Compare allowed blocks to counted blocks
        //System.out.println("Allowed:"+tallied[r][c]+", Counted:"+tally);
        if(tally > tallied[r][c]) {
            validSolution = false;
        }
      }
    }
    return validSolution;
  }

  // Return string version of the puzzle
  @Override
  public String toString() {
    String s = "";
    for(int i=0; i < numRows; i++) {
      for(int j=0; j < numCols; j++) {
        if(puzzle[i][j])
          s+="1 ";
        else
          s+="0 ";
      }
      s+="\n";
    }
    return s;
  }

}
