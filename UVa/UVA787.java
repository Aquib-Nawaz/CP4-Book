import java.util.*;
import java.math.BigInteger;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt()){
            List<BigInteger> list = new ArrayList<BigInteger>();

            while(true){
                int n = sc.nextInt();
                if(n==-999999)
                    break;
                list.add(BigInteger.valueOf(n));
            }

            BigInteger val = BigInteger.valueOf(1),ans=list.get(0), negV=null;

            for(int i=0;i<list.size();i++){
                val = val.multiply(list.get(i));
                ans = ans.max(val);

                if(val.compareTo(BigInteger.valueOf(0)) == -1){
                    if(negV==null)
                        negV = val;
                    else
                        ans = ans.max(val.divide(negV));
                }

                if(val.compareTo(BigInteger.valueOf(0)) == 0){
                    val = BigInteger.valueOf(1);
                    negV=null;
                }
            }

            System.out.println(ans);
        }

    }
}
