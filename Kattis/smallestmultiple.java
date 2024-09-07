// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
import java.math.BigInteger;


class HelloWorld {
    public static BigInteger gcd(BigInteger a, BigInteger b){
        if(b.equals(BigInteger.ZERO))return a;
        return gcd(b, a.mod(b));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            Scanner news = new Scanner(sc.nextLine());
            BigInteger ret = BigInteger.ONE;
            while(news.hasNextBigInteger()){
                BigInteger b = news.nextBigInteger();
                ret = ret.multiply(b).divide(gcd(b,ret));
            }
            System.out.println(ret);
        }
    }
}