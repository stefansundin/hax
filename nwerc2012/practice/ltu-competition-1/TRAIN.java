import java.util.Scanner;


public class TRAIN {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long numtrains = sc.nextLong();
		
		for (long i=0; i < numtrains; i++) {
			int numcarts = sc.nextInt();
			
			if (numcarts == 0) sc.nextLine();
			
			int[] carts = new int[51];
			for (int j=0; j < numcarts; j++) {
				carts[j] = sc.nextInt();
			}

			long sum = 0;
			for (int j=1; j <= numcarts; j++) {
				for (int k=0; k < numcarts; k++) {
					if (carts[k] == j) {
						carts[k] = -1;
						break;
					}
					else if (carts[k] != -1) {
						sum++;
					}
				}
			}
			

			System.out.println("Optimal train swapping takes "+sum+" swaps.");
			
			
		}

	}

}



/*

long numtrains = sc.nextLong();

for (long i=0; i < numtrains; i++) {
	int numcarts = sc.nextInt();

	Stack<Integer> carts = new Stack<Integer>();
	
	for (int j=0; j < numcarts; j++) {
		carts.add(sc.nextInt());
	}
	
	long sum = 0;
	for (int j=1; j <= numcarts; j++) {
		long first = carts.indexOf(j);
		if (first != -1) {
			sum += first;
			carts.remove(first);
		}
	}
	
	System.out.println("Optimal train swapping takes "+sum+" swaps.");
	
	
}
*/