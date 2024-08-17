import java.util.*;
import java.math.BigInteger;
public class UVA11879 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger sb1 = new BigInteger("17");
        while (true) {
            StringBuffer sb = new StringBuffer();
            sb.append(sc.next());
            BigInteger b1 = new BigInteger(sb.toString());
            if(b1.equals(BigInteger.ZERO)) break;
            System.out.printf("%d\n", b1.mod(sb1).equals(BigInteger.ZERO) ? 1 : 0);
        }

    }
}
