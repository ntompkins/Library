# Handling Exceptions in JAVA

When an exception occurs, an [exception object](https://docs.oracle.com/javase/7/docs/api/java/lang/Exception.html) is created.

### Try-Catch Block
1. Code a try-catch block (p. 452-54)
2. Throw an exception
3. Catch an exceptions

### Which Exceptions to Occur?
Test your code to find the exceptions that _need_ to be handled.

### Example Syntax
```
try {
  // attempt statements
}
catch (type ex) {
  // processing statements
}
```

### Declaring Exceptions
+ Declaring an exception in a method declaration
```
public void myMethod() throws IOException {
  // code
}
```
+ You can declare multiple exceptions

### Locations
+ You can throw an exception in a method.
+ You can throw an exception in a try block.

#### In a Method
+ Pass the exception from one place to another


### Syntax
```
try {
  // Strategy 1
  IllegalArgumentException ex = new IllegalArgumentException("Wrong Argument");
  throw ex;
  // Strategy 2
  
} catch (type ex) {
  // process ex
}
```

# Exceptions I've Encountered
+ [IOException](https://docs.oracle.com/javase/7/docs/api/java/io/IOException.html)
+ [ArrayIndexOutOfBoundsException](http://docs.oracle.com/javase/7/docs/api/java/lang/ArrayIndexOutOfBoundsException.html)
+ [NullPointerException](https://docs.oracle.com/javase/7/docs/api/java/lang/NullPointerException.html)