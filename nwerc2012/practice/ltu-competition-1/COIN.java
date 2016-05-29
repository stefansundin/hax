import java.util.Scanner;


public class COIN {

	/**
	 * @param args
	 */
	static int[] table = new int[7500];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		
		table[0] = 1;
		for (int i=1; i <= 7489; i++) {
			int ant = 0;
			int plus = 0;
			
			if (i == 5) {
				plus++;
			} else if ((float) i % (float)5 == 0) {
				ant++;
				plus+=table[5];
			}
			
			if (i == 10) {
				 plus++;
			} else if ((float)i % (float)10 == 0) {
				ant++;
				plus += table[10];
			}
			
			if (i == 25) {
				plus+=3;
			} else if ((float) i % (float)25 == 0) {
				ant++;
				plus += table[25];
			}
			
			if (i == 50) {
				plus++;
			} else if ((float) i % (float)50 == 0) {
				ant++;
				plus += table[50];
			}
			
			if (ant < 1) {
				ant = 0;
			}
			
			table[i] = table[i-1] + plus - ant;
		}
		
		while (sc.hasNext()) {
			int num = sc.nextInt();
			System.out.println(table[num] + " " + superloop(num));
			//System.out.println(superloop(num));
			
			
			
			/*
			for (int i=0; i <= num; i++) {
				for (int j=0; j <= num/5; j++) {
					for (int k=0; k <= num/10; k++) {
						for (int l=0; l <= num/25; l++) {
							for (int m=0; m <= num/50; m++) {
								if (i*1+j*5+k*10+l*25+m*50 == num) {
									x++;
								}
								
							}	
	
						}
	
					}
	
				}
	
			}
			System.out.println(x);
			*/
		}
	}

	static int superloop(int num) {
		int x = 0;
		for (int i=0; i <= num; i++) {
			for (int j=0; j <= num/5; j++) {
				for (int k=0; k <= num/10; k++) {
					for (int l=0; l <= num/25; l++) {
						for (int m=0; m <= num/50; m++) {
							if (i*1+j*5+k*10+l*25+m*50 == num) {
								x++;
							}
							
						}	

					}

				}

			}

		}
		return x;
	}
//	

}
