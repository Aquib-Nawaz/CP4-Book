// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
import java.math.*;

class HelloWorld {

    static int getVal(char c){
        if (c<='9'&&c>=0)return c-'0'+1;
        return c-'a'+11;
    }
    static BigInteger MAX = new BigInteger("4294967295");

    static int minradix(String s){
        int ans=0;
        for(int i=0;i<s.length();i++){
            ans = Math.max(ans,getVal(s.charAt(i)));
        }

        return ans;
    }

    static int ones(String s){
        char [] chars= new char[s.length()];
        Arrays.fill(chars,'1');
        String t = new String(chars);
        if(t.equals(s))return t.length();
        return -1;
    }

    static boolean checkGreater(BigInteger b){
        return b.compareTo(MAX)==1;
    }

    static boolean checkequal(BigInteger b1, BigInteger b2, BigInteger b3, char op){
        BigInteger lhs;
        if(op=='+')lhs = b1.add(b2);
        else if(op=='-')lhs = b1.subtract(b2);
        else if(op=='*')lhs = b1.multiply(b2);
        else {
            if(!b1.mod(b2).equals(BigInteger.ZERO))return false;
            lhs = b1.divide(b2);
        }

        return lhs.equals(b3);
    }

    static char getChar(int r){
        if(r<10)return (char)(r+'0');
        if(r==36)return '0';
        return (char)(r-10+'a');
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while(T-->0){
            String num1 = sc.next();
            char op = sc.next().charAt(0);
            String num2 = sc.next();
            sc.next();
            String num3 = sc.next();
            boolean f=false;
            int mn = Math.max(Math.max(minradix(num1),minradix(num2)),minradix(num3));

            if(mn==2){
                int a=ones(num1),b=ones(num2),c=ones(num3);
                if(a!=-1&&b!=-1&&c!=-1 && checkequal(
                    BigInteger.valueOf(a), BigInteger.valueOf(b),
                    BigInteger.valueOf(c),op)){
                    System.out.print(1);
                    f=true;
                }
            }

            for(int i=mn;i<=36;i++){

                BigInteger a = new BigInteger(num1,i), b= new BigInteger(num2,i),c= new BigInteger(num3,i);
                if(checkGreater(a)||checkGreater(b)||checkGreater(c)){
                    break;
                }

                if(checkequal(a,b,c,op)){
                    System.out.print(getChar(i));
                    f=true;
                }

            }
            if(!f)System.out.print("invalid");
            System.out.println("");

        }
    }
}