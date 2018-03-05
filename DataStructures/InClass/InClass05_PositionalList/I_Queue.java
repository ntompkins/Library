public interface I_Queue<E> {
    public void enqueue (E element);
    public E dequeue() throws EmptyQueueException;
    public boolean IsEmpty();
    public int size();    
}
