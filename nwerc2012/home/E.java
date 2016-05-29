import java.io.BufferedReader;
import java.math.BigInteger;
import java.util.Scanner;


public class E {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner((System.in));
		
		BigInteger sum = BigInteger.ZERO; 
		int i;
		while (s.hasNextInt()) {
			int n = s.nextInt();
			sum = BigInteger.valueOf(n + 1);
			
			for (i=2;i<=n/2.0;i++){
				int x = (int)(n*(2*(i-1)-1)/(double)i);
				sum = sum.add(BigInteger.valueOf(x));
			}
			System.out.println(sum);
		}

	}

}
