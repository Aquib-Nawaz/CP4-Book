
import java.util.*;
import java.math.*;
class HelloWorld{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        BigInteger b = new BigInteger(s,2);
        System.out.println(b.toString(8));
    }
}