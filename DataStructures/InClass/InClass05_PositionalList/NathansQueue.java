
import java.util.Iterator;

public class NathansQueue<E> implements I_Queue<E>, Iterable<E> {
    
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
    public E dequeue() throws EmptyQueueException {
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
    public Iterator<E> iterator() {
        return new NathansQueueIterator();
    }
    
    class NathansQueueIterator implements Iterator<E> {
        Node<E> bookmark;
        
        public NathansQueueIterator() {
           bookmark = head;
        }
        @Override
        public boolean hasNext() {
            if (bookmark == null)
                return false;
            return true;
        }

        @Override
        public E next() {
            if(bookmark == null) {
              throw new IllegalAccessError("No next element in queue.");
            }
            E temp = bookmark.getElement();
            bookmark = bookmark.getNext();
            return temp;
        }

        @Override
        public void remove() {
            // Iterator.super.remove();
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
