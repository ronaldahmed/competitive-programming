import java.io.*;
import java.util.Scanner;

public class p11727{
	public static void main(String[] arg){
		Scanner sc = new Scanner(System.in);
		int t,a,b,c,j=1;
		t = sc.nextInt();
		while(t!=0){
			t--;
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			int sum=a+b+c, aa,cc;
			
			aa = Math.min(Math.min(a,b),Math.min(a,c));
			cc = Math.max(Math.max(c,a),Math.max(c,b));
//			System.out.println("--- "+ a + " "+b+ " "+ +c); 			
			
			System.out.println("Case " + (j++)+": "+(sum-aa-cc));
		}
	}
}
