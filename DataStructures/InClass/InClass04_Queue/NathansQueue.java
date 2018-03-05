package nathansqueue;

/**
 *
 * @author nathantompkins
 */
public class NathansQueue<E> implements I_Queue {
    
    Node <E> head;
    Node <E> tail;
    int size;
    
    public NathansQueue() {
        
    }
    
    @Override
    public void enqueue(E element) {
        Node<E> n = new Node<>();
        n.setElement(element);
        if(IsEmpty()) {
            head = n;
            tail = n;
        } else {
            tail.setNext(n);
            tail = n;
        }
        size++;
    }

    @Override
    public Object dequeue() throws EmptyQueueException {
        if(IsEmpty()) {
            throw new EmptyQueueException("Error in dequeuing; The queue is empty.");
        } else {
            Node<E> temp = head;
            head = head.getNext();
            size--;
            return temp.getElement();
        }
    }

    @Override
    public boolean IsEmpty() {
        return head == null;
    }

    @Override
    public int size() {
        return size;
    }
    
    
}
