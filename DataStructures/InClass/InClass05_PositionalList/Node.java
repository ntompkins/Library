public class Node<E> {
 E element;
 Node<E> next;
 
 public Node() {
  
 }
 public Node(E e) {
  
 }
 
 public void setNext(Node next) {
  this.next = next;
 }
 public void setElement(E element) {
  this.element = element;
 }
 public E getElement() {
  return element;
 }
 public Node getNext() {
  return next;
 }
 
}