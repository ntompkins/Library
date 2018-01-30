# The File Class
### Introduction
There are methods in the file class that allow you to:

1. Obtain properties of a file and/or directory
2. Rename and delete  file and/or directory

The file class does _not_ contain methods for reading
and writing the _contents_ of files.


### Example Program

```

public class TestFileClass {
  public statc void printWriterInput() throws IOException {
    
    // Create object
    java.io.File file = new java.io.File("scores.txt");
    
    // Check if file exists
    if(file.exists()) {
      System.out.print("File already exists.");
      System.exit(0);
    }
    
    // Create File
    java.io.PrintWriter output = new java.ioPrintWriter(file);
    
    output.print("John T Smith ");
    output.println(90);
    
    output.print("Eric K Jones ");
    output.println(85);
    
    // Close the file
    output.close();
  }
  public class void scannerInput throws IOException {
    // Create file
    java.io.File file = new java.io.File("scores.txt");
    
    // Create a Scanner
    Scanner input = new Scanner(file);
    
    // input
    while (input.hasNext()) {
      String firstName = input.next();
      String mi = input.next();
      String lastName = input.next();
      int score = input.nextInt();
    }
    input.close();
  }
  public class void tryCatchInput() {
    try (
      
    ) {
      
    }
  }
}

```

### Methods
```

isDirectory() // true if object is a directory

isFile()      // true if object is file

mkdir()       // creates directory

```


### Files are stored in directories
+ Absolute file name - c:\book\Welcome.java
+ Directory path - c:\book
+ Relative file name - Welcome.java


### Writing Methods
+ `Printwriter output = new PrintWriter(filename);`
+ `print`
+ `println`
+ `printf`

