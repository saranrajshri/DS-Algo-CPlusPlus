import java.util.*;

// Method overloading - Compile time polymorphism
class Demo {
    public static int addUp(int a, int b) {
        return a + b;
    }
    
    public static int addUp(int a, int b, int c) {
        return a + b + c;
    }
}

class Main {
	public static void main(String[] args) {
	    Demo objectD = new Demo();
	    System.out.println(objectD.addUp(5, 2));
	    System.out.println(objectD.addUp(5, 2, 5));
	}
}

// Method overriding - Run time polymorphism
class Demo {
	public static printMessage() {
		System.out.println("Hi..This is a message");
	}
}

class Main extends Demo {
	
	public static printMessage() {
		System.out.println("New message");
	}

	public static void main(String[] args) {
		Demo objectD = new Demo();
		objectD.printMessage();
	}
}
