// Author: Nathan Tompkins
public class NathansStack<E> implements I_NathansStack<E> {
    
    // Create variables
    public static final int CAP = 1000;
    private E[] data;
    private int t = -1;
    
    // Constructors
    public NathansStack() { this(CAP); }
    public NathansStack(int capacity) {
        data = (E[]) new Object[capacity];
        
    };
    
    public int size() {
        
        // Return size of the stack
        return(t+1);
    } 
    
    @Override
    public boolean isEmpty() {
        
        // Return value of the counter
        return t == -1;
    }

    @Override
    public boolean push(E e) throws IllegalStateException {
        
        // Exception if stack is full
        if( size() == data.length ) throw new IllegalStateException("Stack is full.");
        
        // Add data to stack
        data[++t] = e;
        
        // return true if no exception
        return true;
    }

    @Override
    public E pop() throws NathansEmptyStackException {
        
        // Check if stack is empty
        if(isEmpty()) 
            throw new NathansEmptyStackException("Unable to pop; the stack is empty.");
        
        // Assign value to return variable
        E answer = data[t];
        
        // Empty top of stack
        data[t] = null;
        
        // Decrement counter
        t--;
        
        // Return variable
        return answer;
    }

    @Override
    public E top() throws NathansEmptyStackException {
        
        // Check if stack is empty
        if(isEmpty())
            throw new NathansEmptyStackException("Unable to get the top. Stack is empty.");
        
        // Return top of the stack
        return data[t];
    } 
}