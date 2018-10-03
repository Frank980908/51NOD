import java.util.*;
import java.math.*;
public class T{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		String str = cin.next();
		int n = cin.nextInt();
		BigDecimal a = new BigDecimal(str);
		BigDecimal res = new BigDecimal("1");
		for( int i = 0 ; i < n ; i++ ){
			res = res.multiply(a);
		}
		str = res.stripTrailingZeros().toPlainString();
		System.out.println(str.startsWith("0.")?str.substring(1) : str );
	}
}