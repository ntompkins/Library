import java.lang.Math;
import java.util.regex.*;

public class Calculator {
  // Method to process string input
  public static double calculate(String entry) {
    // try {
      /* Addition */
      if(entry.matches("(?s).*\\+.*")) {
        String[] operands = entry.split("(\\+)");
        return (Double.parseDouble(operands[0]) + Double.parseDouble(operands[1]) );
      }
      /* Subtraction */
      else if(entry.matches("(?s).*\\-.*")) {
        String[] operands = entry.split("(\\-)");
        return ( Double.parseDouble(operands[0]) - Double.parseDouble(operands[1]) );
      }
      /* Multiplication */
      else if(entry.matches("(?s).*\\*.*")) {
        String[] operands = entry.split("(\\*)");
        return ( Double.parseDouble(operands[0]) * Double.parseDouble(operands[1]) );
      }
      /* Division */
      else if(entry.matches("(?s).*\\/.*")) {
        String[] operands = entry.split("(\\/)");
        return ( Double.parseDouble(operands[0]) / Double.parseDouble(operands[1]) );
      }
      /* Power */
      else if(entry.matches("(?s).*\\^.*")) {
        String[] operands = entry.split("(\\^)");
        return ( Math.pow(Double.parseDouble(operands[0]),Double.parseDouble(operands[1])) );
      }
      /* Return broken entry */
      else {
       System.out.println("Invalid Entry");
       return 0.0;
      }
    // } catch(ArithmeticException e) {
    //   System.out.println("Invalid Entry");
    //   return e;
    // }
  }
  public static double add(double l,double r) { return l + r;}
  public static double sub(double l,double r) { return l - r;}
  public static double mul(double l,double r) { return l * r;}
  public static double div(double l,double r) { return l / r;}
}
