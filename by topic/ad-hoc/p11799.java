import java.io.*;
import java.util.Scanner;

public class p11799{
	public static void main(String[] arg){
		Scanner sc = new Scanner(System.in);
		int t,n,j=1,mx;
		t = sc.nextInt();
		while(t!=0){
			t--;
			mx=0;
			n = sc.nextInt();
			for(int i=0;i<n;++i)
				mx = Math.max( mx,sc.nextInt() );			
			System.out.println("Case "+(j++)+": "+mx);
		}
	}	
}
