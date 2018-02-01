/*
Storage of data in two ways: Static and Dynamic
Array is the main static structure (I know how much memory I need).
Linked List is the main dynamic structure (I don't know how much memory I need).

*/

public class SinglyLinkedList {

    // Points to head node
    static Node head; 

    public static void main(String[] args) {
        
        // Create first node 
        Node n = new Node(5,null);
        // Set head to reference n
        head = n;
        // Create second node to point to head
        Node n1 = new Node(10,head);
        // Set n1 to the new head
        head = n1;
        // Create third node to point to head
        Node n2 = new Node(15,head);
        // Set n2 to the new head
        head = n2;
        
        // Add node n that points to new value without losing first n
        n = new Node(20,head);
        head = n;
        
        Node current = head;
        while(current!=null) {
            System.out.println(current.data);
            current = current.next;
        }
    }
}
