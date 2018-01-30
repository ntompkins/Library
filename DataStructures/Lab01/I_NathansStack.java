// Author: Nathan Tompkins
public interface I_NathansStack<E> {
    public boolean isEmpty();
    public boolean push(E e);
    public E pop() throws NathansEmptyStackException;
    public E top() throws NathansEmptyStackException;
}