package staticVariable; 
public class Student 
{ 
// Declare a static variable id having data type int and assign it the value 20. 
  static int id = 20; 
public static void main(String[] args) 
 { 
// Create an object of the class Student. 
    Student s = new Student(); // Call static variable using object reference variable s and store it by variable x with data type int. 
     int x = s.id; // Print on the console. 
    System.out.println(x); // Now Call static variable id using the class name. 
    System.out.println(Student.id); 
  } 
}