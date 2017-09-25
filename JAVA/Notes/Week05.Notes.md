// Create Arrays
double [] myList = new double[10];
double [] myList = {1.9, 2.8, 3.4, 3.5};
// Arrays are static sized, ArrayLists are dynamic
// To find the length of the array, you can use the length method: 
// _myList.length_ <== no parentheses, unlike String.

// Loading random numbers
for (int i=0; i < myList.length; i++) {
  myList[i] = Math.random();
}

// To copy elements from one array to another you can
1. Use a for loop
2. use arraycopy method > 
   System.arraycopy(sourceArray, 1, targetArray, 1, 4);
   System.arraycopy(sourceArray, 0, targetArray, 0, sourceArray.length);

// Passing arrays to methods are passed by reference not by value

// Returning an array from a method
public static int[] reverse(int[] list) {
  int[] result = new int[list.length];
  for (int i = 0, j = result.length-1; i < list.length; i++, j--) {
    result[j] = list[i];
  }
  return result;
}

// JAVA has a built-in sort method: array.sort
// or, if JAVA 8, Arrays.parallelSort(list) <== this uses multicore
