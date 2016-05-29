import java.util.Scanner;


public class MATRIX {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[][] matrix = new int[n][n];
		
		for (int i=0; i < n; i++) {
			for (int j=0; j < n; j++) {
				matrix[j][i] = sc.nextInt();
			}
		}

		int maxsum = Integer.MIN_VALUE;
		int sum = 0;
		for (int i=0; i < n; i++) {
			sum = 0;
			for (int j=0; j < n; j++) {
				sum += matrix[i][j];
			}
			if (sum > maxsum) {
				maxsum = sum;
			}
		}

		for (int j=0; j < n; j++) {
			sum = 0;
			for (int i=0; i < n; i++) {
				sum += matrix[i][j];
			}
			if (sum > maxsum) {
				maxsum = sum;
			}
		}

		for (int i=0; i < n; i++) {
			// down left
			sum = 0;
			for (int x=i, y=0; x >= 0 && y < n; x--, y++) {
				sum += matrix[x][y];
			}
			if (sum > maxsum) {
				maxsum = sum;
			}

			// down right
			sum = 0;
			for (int x=i, y=0; x < n && y < n; x++, y++) {
				sum += matrix[x][y];
			}
			if (sum > maxsum) {
				maxsum = sum;
			}
		}

		for (int i=0; i < n; i++) {
			// up left
			sum = 0;
			for (int x=i, y=n-1; x >= 0 && y >= 0; x--, y--) {
				sum += matrix[x][y];
			}
			if (sum > maxsum) {
				maxsum = sum;
			}

			// up right
			sum = 0;
			for (int x=i, y=n-1; x < n && y >= 0; x++, y--) {
				sum += matrix[x][y];
			}
			if (sum > maxsum) {
				maxsum = sum;
			}
		}
		
		System.out.println(maxsum);

	}

}
