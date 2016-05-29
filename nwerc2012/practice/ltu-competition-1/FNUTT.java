import java.util.Scanner;


public class FNUTT {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int comments = 0;
		Boolean instring = false;
		
		String line;
		
		while (sc.hasNext()) {
			line = sc.nextLine();
			for (int i=0; i < line.length(); i++) {
				if (instring) {
					System.out.print(line.charAt(i));
					if (line.charAt(i) == '\"' && line.charAt(i-1) != '\\') {
						System.out.println();
						instring=false;
						continue;
					}
				}
				else if (line.charAt(i) == '/' && line.length() > i+1 && line.charAt(i+1) == '*') {
					comments++;
				}
				else if (line.charAt(i) == '*' && line.length() > i+1 && line.charAt(i+1) == '/') {
					comments--;
				}
				else if (line.charAt(i) == '/' && line.length() > i+1 && line.charAt(i+1) == '/') {
					break;
				}
				else if (line.charAt(i) == '"' && i-1 >= 0 && line.charAt(i-1) != '\\' && line.charAt(i-1) != '\'' && comments == 0) {
				//else if (line.indexOf("\"") == i && line.charAt(i-1) != '\\' && line.charAt(i-1) != '\'' && comments == 0) {
					System.out.print(line.charAt(i));
					instring=true;
				}
			}
		}

	}
	

}
