import java.io.*;
import java.util.Scanner;

public class p11764{
	public static void main(String[] arg){
		Scanner sc = new Scanner(System.in);
		int t,n, low, up, j=1;
		t = sc.nextInt();
		while(t!=0){
			t--;
			low=0; up=0;
			n = sc.nextInt();
			int t1 = sc.nextInt();
			for(int i=1,t2;i<n;++i){
				t2 = sc.nextInt();
				if(t2<t1)		low++;
				else if(t2>t1)	up++;
				t1=t2;
			}
			System.out.println("Case "+(j++)+": "+up+" "+low);
		}
	}
}
