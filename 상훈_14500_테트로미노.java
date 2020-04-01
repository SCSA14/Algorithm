import java.util.*;

public class Main {

	static int[][][] a = {{{0,0,0,0},{0,1,2,3}}
						,{{0,1,2,3},{0,0,0,0}}
						,{{0,0,1,1},{0,1,0,1}}
						,{{0,1,2,2},{0,0,0,1}}
						,{{0,1,0,0},{0,0,1,2}}
						,{{0,1,1,1},{2,0,1,2}}
						,{{0,1,1,2},{0,0,1,1}}
						,{{0,0,1,1},{1,2,0,1}}
						,{{0,0,0,1},{0,1,2,1}}
						,{{0,1,1,2},{1,0,1,1}}
						,{{0,1,1,1},{1,0,1,2}}
						,{{0,1,1,2},{0,0,1,0}}
						,{{0,0,1,2},{0,1,1,1}}
						,{{0,1,1,2},{1,0,1,0}}
						,{{0,0,1,1},{0,1,1,2}}
						,{{0,1,2,2},{1,1,0,1}}
						,{{0,1,1,1},{0,0,1,2}}
						,{{0,0,1,2},{0,1,0,0}}
						,{{0,0,0,1},{0,1,2,2}}};
	static int[][] map;

	public static void main(String[] args) {
		 int n,m;
		 Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		 m = sc.nextInt();
		 map = new int[n][m];
		 for(int i=0;i<n;i++) {
			 for(int j=0;j<m;j++) {
				 map[i][j] = sc.nextInt();
			 }
		 }
		 
		 int max=0;
		 for(int k=0;k<19;k++) {
			 for(int i=0;i<n;i++) {
				 for(int j=0;j<m;j++) {
					 int sum=0;
					 for(int l=0;l<4;l++) {
						 if(i+a[k][0][l]<n && j+a[k][1][l]<m && i+a[k][0][l]>=0 && j+a[k][1][l]>=0  ) {
							 sum+=map[i+a[k][0][l]][j+a[k][1][l]];
						 }else {
							 sum=0;
							 break;
						 }
					 }
					 if(max<sum)max=sum;
				 }
			 }
		 }
		 
		 
		 System.out.println(max);
		
	}
}