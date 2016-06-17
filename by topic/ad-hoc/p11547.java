import java.io.*;
import java.util.Scanner;

public class p11547{
	public static void main(String[] arg){
		Scanner sc = new Scanner(System.in);
		int t,n;
		t = sc.nextInt();
		while(t!=0){
			t--;
			n = sc.nextInt();
			n = Math.abs( (((n*567)/9 + 7492)*235)/47 - 498);
			System.out.println( (n/10)%10 );
		}
	}
}
