import java.util.*;
import java.math.BigInteger;
public class UVA713 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n-- > 0) {
            StringBuffer sb = new StringBuffer(), sb1 = new StringBuffer();
            sb.append(sc.next());
            sb1.append(sc.next());
            sb.reverse();
            sb1.reverse();
            BigInteger b1 = new BigInteger(sb.toString());
            BigInteger b2 = new BigInteger(sb1.toString());
            sb = new StringBuffer(b1.add(b2).toString());
            sb.reverse();
            while(sb.charAt(0) == '0' && sb.length() > 1)
                sb.deleteCharAt(0);
            System.out.println(sb);
        }

    }
}
