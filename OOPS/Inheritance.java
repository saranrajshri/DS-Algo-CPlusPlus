import java.util.*;


//  Single Inheritance
class One {
	public static void printGeeks() {
		System.out.println("Geeks");
	}
}

class Two extends One {
	public static void printFor() {
		System.out.println("For");
	}
}

class Inheritance {
	public static void main(String[] args) {
		Two objectT = new Two();
		objectT.printGeeks();
		objectT.printFor();
		objectT.printGeeks();
	}
}

// Multilevel
import java.util.*;

class One {
	public static void printGeeks() {
		System.out.println("Geeks");
	}
}

class Two extends One {
	public static void printFor() {
		System.out.println("For");
	}
}

class Three extends Two {
    public static void printGeeks1() {
        System.out.println("Geeks1");
    }
}

class Main {
	public static void main(String[] args) {
		Three objectT = new Three();
		objectT.printGeeks();
		objectT.printFor();
		objectT.printGeeks();
		objectT.printGeeks1();
	}
}


// Multiple 
import java.util.*;

interface one {
    public void printGeeks();
}

interface two {
    public void printFor();
}

interface three extends one, two {
    public void printGeeks();
}

class Demo implements three {
    
    public void printGeeks() {
        System.out.println("Geeks");
    }
    
    public void printFor() {
        System.out.println("For");
    }
    
    
}

class Main {
    public static void main(String [] args) {
        Demo d = new Demo();
        d.printGeeks();
        d.printFor();
        d.printGeeks();
    }
}