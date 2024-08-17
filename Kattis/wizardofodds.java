import java.util.*;
import java.math.BigInteger;
public class wizardofodds {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        StringBuffer sb = new StringBuffer();
        StringBuffer sb1 = new StringBuffer();
        sb.append(sc.next());
        sb1.append(sc.next());
        BigInteger N = new BigInteger(sb.toString());
        BigInteger K = new BigInteger(sb1.toString());
        if(K.compareTo(BigInteger.valueOf(350)) == 1)
        {
            System.out.println("Your wish is granted!");
        }
        else
        {
            K = BigInteger.valueOf(2).pow(K.intValue());
            if(N.compareTo(K) == 1)
            {
                System.out.println("You will become a flying monkey!");
            }
            else
            {
                System.out.println("Your wish is granted!");
            }
        }
    }
}
