import java.util.Scanner;

public class Driver {
 public static void main(String[] args) {
  
  // Create input scanner
  Scanner input = new Scanner(System.in);
  
  // Get map info
  System.out.print("Rows (20 max): ");
  int rows = input.nextInt();
  System.out.print("Cols (70 max): ");
  int cols = input.nextInt();
  System.out.print("Items in map: ");
  int items = input.nextInt();

  // Consume newline
  input.nextLine();
  
  // Create new cave object
  Cave cave = new Cave(rows,cols,items);
  
  // set objects
  for(int i=0; i < items; i++) {
    System.out.print("Object "+(i+1)+": ");
    // Split line at whitespace
    String[] info = input.nextLine().split(" ");
    
    // Check for diamond and home
    if(info[0].charAt(0)=='d')
      cave.setDiamond(
        Integer.parseInt(info[1]),
        Integer.parseInt(info[2])
      );
    else if(info[0].charAt(0)=='h')
      cave.setHome(
        Integer.parseInt(info[1]),
        Integer.parseInt(info[2])
      );

    // Parse strings and pass to cell 
    cave.setCell(
      Integer.parseInt(info[1]),
      Integer.parseInt(info[2]),
      info[0].charAt(0)
    );
    
  }
  
  cave.addBorder();
  // System.out.println("Diamond: "+cave.getDiamondX()+","+cave.getDiamondY());
  // System.out.println("Home: "+cave.getHomeX()+","+cave.getHomeY());
  
   // cave.addBorder();
  
  System.out.print(cave.toString());
  // // Change map size
  // cave.setRows(rows+1);
  // cave.setCols(cols+1);
  // cave.updateMap();
  
  // // Repopulate map
  // for(int x=0; x < cave.getRows(); x++) {
  //  for(int y=0; y < cave.getCols(); y++) {
  //   if(x==0)
  //    cave.setCell(x,y,'O');
  //   else if(y==0 || y==cave.getCols()-1)
  //    cave.setCell(x,y,'O');
  //   else if(x==cave.getRows()-1)
  //    cave.setCell(x,y,'O');
  //   else
  //    cave.setCell(x,y,' ');
  //  }
  // }
  
  // // Print array
  // System.out.print(cave.toString());
  
  input.close();
 }
 
}