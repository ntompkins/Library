# Chapter 4

### Outline
+ Intro to the _Math_ class
+ Using _char_
+ Comparing the _Character_ class
+ _String_ objects and methods
+ Reading from the console
+ Formatting the console

### Character Class Methods
+ isDigit();
+ isLetter();
+ isLetterOrDigit();
+ isLowerCase();
+ isUpperCase();
+ toLowerCase();
+ toUpperCase();

### String Object Methods
+ length();
+ charAt();
+ concat();
+ toUpperCase();
+ toLowerCase();
+ trim();
+ indexOf(); _Does this method ignore case?_

### Instanace Methods
+ When invoking a method on a string you have to invoke it from a specific instance of the object.
  + > String message = "Welcome to Java";
  + > message.length();

### Static Methods
+ Non-instance methods
+ Math methods are static methods
+ Not tied to a specific instance of an object
+ > Math.max(2,3);

### Comparing Strings
+ equals();
+ equalsIgnoreCase();
+ compareTo();
+ compareToIgnoreCase();
+ startsWith();
+ substring(); // returns the string's substring that begins with the character at the specified <beginIndex> and extends to the end of the string
+ 

### Formatting Output
+ System.out.printf(format, items);
+ Specifiers begin with %

#### Specifiers List
+ %b > boolean values
+ %c > char
+ %d > decimal integer
+ %f > floating point
+ %e 

#### Escape Sequences