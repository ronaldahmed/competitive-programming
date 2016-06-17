import java.io.*;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int k = Integer.parseInt(sc.nextLine());
		int n,m;
		while(k!=0){
			k--;
			n = sc.nextInt();
			m = sc.nextInt();
			System.out.println( (n/3)*(m/3) );
		}
		System.out.close();
		sc.close();
	}
}
