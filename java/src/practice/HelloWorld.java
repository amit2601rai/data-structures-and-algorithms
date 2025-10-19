package practice;

/** Simple Hello World program in Java */
public class HelloWorld {
  public static void main(String[] args) {
    System.out.println("Hello, World!");
    System.out.println("Java is running successfully!");

    // Print some information
    System.out.println("Java Version: " + System.getProperty("java.version"));
    System.out.println("Operating System: " + System.getProperty("os.name"));

    // Example with command line arguments
    if (args.length > 0) {
      System.out.println("Command line arguments:");
      for (int i = 0; i < args.length; i++) {
        System.out.println("  arg[" + i + "] = " + args[i]);
      }
    } else {
      System.out.println("No command line arguments provided.");
    }
  }
}
