import java.util.Scanner;


public class EKVATION {

	static double[] table = new double[101];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		
		for (int i=0; i < num; i++) {
			System.out.println(Math.round(C(sc.nextInt()))); 
		}
		
	}
	
	static double C(int n) {
		if (n == 0) return 0;
		if (table[n] != 0) return table[n];
		
		
		double sum = 0;
		for (int j=1; j <= n; j++) {
			sum += C(j-1) + C(n-j);
		}
		table[n] = n + 1 + sum/n;
		return table[n];
	}

}
