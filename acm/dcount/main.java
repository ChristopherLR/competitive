import java.io.*;
import java.util.*;

public class main {
	public static ArrayList <String> set = new ArrayList();
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		in.nextInt();
		while(in.hasNext()){
			count(in.nextInt());
			for ( int i = 0 ; i <9 ; i++){
				System.out.print(set[i]);
				System.out.print(" ");
			}
			System.out.print(set[9]);
			System.out.print("\n");
			set = new int[10];
		}
		System.out.print("");
	}

	public static void count (int n){
		if (n == 0){
			return;
		}
		innerCount(n);
		count( n - 1);
	}

	public static int innerCount( int n){
		if (n == 0){
			return 0;
		} else {
			set[n%10]++;
			return innerCount(n/10);
		}
	}

}
