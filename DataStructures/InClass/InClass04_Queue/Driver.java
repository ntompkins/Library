package nathansqueue;

public class Driver {
  public static void main(String[] args) throws Exception {
    String[] names  = {"konnor","jackson","nathanT","jonathan","jesse","zach","josh","luke","max","matt","richard","kai","ian"};
  
    NathansQueue<String> q = new NathansQueue<>();
    for(String name : names) {
      q.enqueue(name);
    }
    while(q.size()>1) {
      q.enqueue(q.dequeue());
      q.enqueue(q.dequeue());
      String name = q.dequeue();
      System.out.println(name+" was removed.");
    }  
    String winner = q.dequeue();
    System.out.println("The winner is " + winner);

  }
}